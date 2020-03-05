#include "swilib.h"
#include "ussd_process.h"
#include "xtask_ipc.h"
#include "main.h"
#include "config_data.h"
//IPC
const char ipc_my_name[32]="Casher";
const char ipc_xtask_name[]=IPC_XTASK_NAME;
IPC_REQ gipc;
int CASH_SIZE=0;
int CASH_num=0;
extern long  strtol (const char *nptr,char **endptr,int base);
char cashfname[128];
int MaxCASH[MAX_CASH_SIZE];
int CurrentCASH[MAX_CASH_SIZE];
static GBSTMR ussd_tmr;
static volatile int ussdreq_sended;
static volatile int locked;

//static char old_text[250];


int char16to8(int c)
{
  if (c<0x400) return (c);
  c-=0x400;
  if (c<16)
  {
    if (c==1) c=0;  //big_yo
    else if (c==4) c=2;  //big_ye
    else if (c==6) c=10; //big_i
    else return (c);
  }
  else if (c>79)
  {
    if (c==0x51) c=16; //small_yo
    else if (c==0x54) c=18; //small_ye
    else if (c==0x56) c=11; //small_i
    else if (c==0x57) c=23; //small_yi
    else return (c);
  }
  else c+=8;
  c+=168;
  return (c);
}

static void WriteUSD(int nusd, char *text)
{
  unsigned int ul;
  char std[300];
  char stdF[128];
  if (!text) return;
  sprintf(stdF, "%sussd_%d.txt",cashTEMP_PATH, nusd);
     int f=fopen(stdF,A_ReadWrite+A_Create+A_BIN+A_Truncate,P_WRITE,&ul);
    if (f!=-1)
    {
     ul = sprintf(std, "%s",text);
     fwrite(f,std,ul,&ul);
     fclose(f,&ul);
    }
  //mfree(text);
}
static void WriteLog(int dummy, char *text)
{
  unsigned int ul;
  char std[300];
  TTime t;
  TDate d;
  if (!text) return;
  if (ENA_CASHTRACELOG /*&& strcmp(old_text,text)*/)
  {
    //strcpy(old_text, text);
    int f=fopen(cashLOG_FILE,A_ReadWrite+A_Create+A_Append+A_BIN,P_READ+P_WRITE,&ul);
    if (f!=-1)
    {
      GetDateTime(&d, &t);//text,cashLOG_Format
      ul = sprintf(std, "%02d/%02d/%d %02d.%02d\n%d %d  %d %d %d\n",
              d.day,d.month,d.year,t.hour,t.min,
              CurrentCASH[0], CurrentCASH[1], CurrentCASH[2], CurrentCASH[3], CurrentCASH[4]);
      //ul = sprintf(std, "%s",text);
      fwrite(f,std,ul,&ul);
      fclose(f,&ul);
    }
  }
  //mfree(text);
}

void SaveCash(void)
{
  int f;
  unsigned int ul;
  unsigned char attrib;
  if (*cashfname)
  {
    if ((f=fopen(cashfname,A_ReadWrite+A_Create+A_BIN+A_Truncate,P_WRITE,&ul))!=-1)
    {
      fwrite(f,CurrentCASH,sizeof(CurrentCASH),&ul);      //by BoBa 4.07.07
      fwrite(f,MaxCASH,sizeof(MaxCASH),&ul);
      fclose(f,&ul);
      GetFileAttrib(cashfname,&attrib,&ul);
      if (!(attrib&FA_HIDDEN))
      {
        attrib|=FA_HIDDEN;
        SetFileAttrib(cashfname,attrib,&ul);
      }
    }
  }
}

/*
static void CheckPay(void)
{
  int i=0;
  int f=0;
  do
  {
    if (CurrentCASH[i]>MaxCASH[i])
    {
      MaxCASH[i]=CurrentCASH[i];
      f=1;
    }
    i++;
  }
  while(i<CASH_SIZE);
  if (f) SaveCash();
}
*/


static const char * const patterns[MAX_CASH_SIZE]=
{
  CashPat0,
  CashPat1,
  CashPat2,
  CashPat3,
  CashPat4
};

int SubChar(char *A, char B)
{
  int i=0;
  while(A[i]!=0)
  {
    if(A[i]==B) return(i); 
    i++;
  }
 return(0);
}

static int FindCash(const char *s, int numcesh)
{
  const char *pat;
  int i;
  int f=0;
  char *ep;
  const char *p;
  const char *pval;
  int c;
  int cc;
  int n=numcesh;

  L_RESTARTPAT:
    p=s; //������� ������� � ������
    s++;
    pval=NULL; //����� ���� �� �����
    pat=patterns[n]; //�������� � ������ ��������
    while((c=*pat++,cc=*p)) //���� �� ����� �� ����� ������, � ������� ����
    {
     if (c=='#') //� �� ����� �� ������ ���������
     {
      //��������� �� �����
      if (((cc<'0')||(cc>'9'))&&(cc!='-')) goto L_RESTARTPAT; //������ ����� �� ����� - ������� ������
      pval=p; //�������� ����� ����� �����

     do
      {       
       cc=*++p; //��������� ������     
       
      }
      while(((cc>='0')&&(cc<='9'))||(cc=='-')||(cc=='.')); //���� ��� ��� �����
     }
     else
     {
      //������� ���������
      if (!c)  break; //����� �� ����� ��������, ������ ��� �������, �������
      //���������� �������
      if (cc!=c) goto L_RESTARTPAT; //��� ����������, ����������
      p++;
     }
    }
    if (c) return (0); //�� ����� �� ����� ��������
    if (!pval) return (0); //�� ����� �����
    s=p; //����� ����� ���������� ������
    i=strtol(pval,&ep,10)*100;
    pval=ep;
    if ((*pval=='.')||(*pval==','))
    {    
     pval++;

     int j=strtol(pval, &ep, 10);	//���� ��������� ����� ����� �������...
     int k=ep-pval;			//... �� 10^(2-k)
     if (k==1)
      j*=10;
     else
      while (k>2) {			//����� j �� 10^(k-2)
       j/=10; k--;
      }//���, ������ ��� ������� � �.�. � 3-4 ������� ����� �������. ��� ����� � ����. Lost, 15.01.2008
     i+=j;

     pval=ep;
    }
    if (i>(CurrentCASH[n]+(MaxCASH[n]/100))) //���� ����� ������ ��� ������� +1 ������� �� �������������
    {
     MaxCASH[n]=i;
     f=1;
    }
    CurrentCASH[n]=i;
  if (f) SaveCash();
  return (n);
}

static void _lock(void)
{
 if (locked) return;
  gipc.name_to=ipc_xtask_name;
  gipc.name_from=ipc_my_name;
  gipc.data=0;
  GBS_SendMessage(MMI_CEPID,MSG_IPC,IPC_XTASK_LOCK_SHOW,&gipc);
  locked=1;
}

static void _unlock(void)
{
  if (!locked) return;
  gipc.name_to=ipc_xtask_name;
  gipc.name_from=ipc_my_name;
  gipc.data=0;
  GBS_SendMessage(MMI_CEPID,MSG_IPC,IPC_XTASK_UNLOCK_SHOW,&gipc);
  locked=0;
}

static void ussd_timeout(void)
{
  _unlock();
  ussdreq_sended=0;
  StartHoursTimer();
}


int ProcessUSSD(CSM_RAM* data, GBS_USSD_MSG *msg)
{
  WSHDR *ws;
  int len;
  char *s;
  int i=0;
  int zi=0;

#define ussdreqgui_id (((int *)data)[DISPLACE_OF_USSDREQGUI_ID/4])

   if (msg->msg==MSG_USSD_RX)
  {
    if (!ussdreq_sended) return 0;
    EndUSSDtimer();
  }
  if (msg->msg==MSG_AUTOUSSD_RX)
  {
    //if (!ENA_AUTOCASHTRACE) return 0;
  }
  ws=AllocWS(256);
  len=msg->pkt_length;
  if (len>240) len=240;
  GSMTXT_Decode(ws,msg->pkt,len,msg->encoding_type,(void*(*)(int))malloc_adr(),(void(*)(void))mfree_adr());
  if ((len=ws->wsbody[0]))
  {
    zeromem(s=malloc(len+3),len+3);
    len=0;
    while(len<ws->wsbody[0])
    {
      int c=ws->wsbody[len+1];
      c=char16to8(c);
      if (c<32) c='?';
      if(c==':')c='.';
      s[len++]=c;
    }

    i=FindCash(s, 0);
    if(i)zi=1;
    if(ENA_CashPat1){i=FindCash(s, 1);if(i)zi=1;}
    if(ENA_CashPat2){i=FindCash(s, 2);if(i)zi=1;}
    if(ENA_CashPat3){i=FindCash(s, 3);if(i)zi=1;}
    if(ENA_CashPat4){i=FindCash(s, 4);if(i)zi=1;}

    if(CASH_num == ENA_CashPat1)
     SUBPROC((void *)WriteLog,0,s);
    if(ENA_USD)WriteUSD(CASH_num+1, s);
  }
  FreeWS(ws);
  if (ussdreqgui_id)
  {
    GeneralFunc_flag1(ussdreqgui_id,0);
    ussdreqgui_id=0;
  }
  if (msg->msg==MSG_AUTOUSSD_RX)
  {
    if (!zi) return (0);
    SendAutoUSSDack();
  }
  FreeGSMTXTpkt(msg->pkt);
  return 1;
}

static void ussd_send(void)
{
  if (IsGuiOnTop(((int *)FindCSMbyID(CSM_root()->idle_id))[DISPLACE_OF_IDLEGUI_ID/4]))
  {
    ussdreq_sended=1;
    if(CASH_num==0)
     MakeVoiceCall(CASHREQNUM,0x10,0x2FFF);
    else
     if(CASH_num==1)
      MakeVoiceCall(CASHREQNUM1,0x10,0x2FFF);

    GBS_StartTimerProc(&ussd_tmr,216*60,ussd_timeout);
  }
  else
  {
    SendCashReq();
  }
}

void SendCashReq(void)
{
 if(CASH_num==2) CASH_num=0;
 if (ussdreq_sended) return; //��� ����� ;)
 GBS_StartTimerProc(&ussd_tmr,216*3,ussd_send);
 _lock();
}

void DUSSDtimer(void)
{
  GBS_DelTimer(&ussd_tmr);
}
void EndUSSDtimer(void)
{
  GBS_DelTimer(&ussd_tmr);
  ussdreq_sended=0;
  _unlock();
}

void imsi2str(char *imsi, char *str)
{
  unsigned int c, c1;
  int j, m;
  m=0;
  j=0;
  while(j<IMSI_DATA_BYTE_LEN)
  {
    if (m&1) {c1=c>>4; j++;}
    else c1=(c=imsi[j])&0x0F;
    *str++=c1+'0';
    m++;
  }
  *str=0;
}

void LoadCash(void)
{
  unsigned int ul;
  int s=0;
  char imsi_str[IMSI_DATA_BYTE_LEN*2+1];

  CASH_SIZE=0;

  extern char cur_imsi[];
  imsi2str(cur_imsi,imsi_str);
  sprintf(cashfname,"%sCasher_%s.tmp",cashTEMP_PATH,imsi_str);
  zeromem(CurrentCASH,sizeof(CurrentCASH));
  zeromem(MaxCASH,sizeof(MaxCASH));
  int f=fopen(cashfname,A_ReadOnly+A_BIN,P_READ,&ul);
  if (f!=-1)
  {
    s=fread(f,CurrentCASH,sizeof(CurrentCASH),&ul);     //by BoBa 4.07.07
    s=fread(f,MaxCASH,sizeof(MaxCASH),&ul);
    fclose(f,&ul);
  }
  if (s!=sizeof(MaxCASH))
  {
    memcpy(MaxCASH,CurrentCASH,sizeof(MaxCASH));
    SaveCash();
  }
  while ((CASH_SIZE<MAX_CASH_SIZE)&&(*patterns[CASH_SIZE]))
  {
    CASH_SIZE++;
  }
}
