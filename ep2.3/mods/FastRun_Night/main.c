/*******************************************************************************
FastRun::Night (c) The_ZeN, (r) Shadows, vanek, feanor
*******************************************************************************/

#include "..\inc\swilib.h"
#include "conf_loader.h"
#include "fastrun_ipc.h"
#include "fastrun.c"
#include "language.h"
#include "bookmarks.c"
#include "menus.c"
#include "keyhooks.c"
/*int toupper(int c)
{
  if ((c>='a')&&(c<='z')) c+='A'-'a';
  return(c);
}*/
char emenu=1;
#pragma inline
int strcmp_nocase(const char *s1,const char *s2)
{
  int i;
  int c;
  while(!(i=(c=toupper(*s1++))-toupper(*s2++))) if (!c) break;
  return(i);
}



void RedrawScreen() // ������ �� ����
{
  CSM_RAM *data=FindCSMbyID(CSM_root()->idle_id);
  if(IsGuiOnTop(idlegui_id)) //���� IdleGui �� ����� �����
  {
    GUI *igui=GetTopGUI();
    if (igui) //� �� ����������
    {
      void *canvasdata;
#ifdef ELKA
      {
#else
      void *idata;
      idata=GetDataOfItemByID(igui,2);
      if (idata)
      {
#endif
#ifdef ELKA
	if(IDLE_ENA)canvasdata=BuildCanvas();
#else
        if(IDLE_ENA)canvasdata=((void **)idata)[DISPLACE_OF_IDLECANVAS/4];
#endif
        if(IDLE_ENA)
        {
          if ( NumOfItems_idle > 0)
          {
            DrawIdleMenu();
          }
          else
          {
            WSHDR * ws = AllocWS( 256 );
            DrawCanvas( canvasdata , x1,  y1, x1+LEN_ID, y1 + 4 + (GetFontYSIZE(TEXT_FONT))*2, 1 );
            DrawRoundedFrame( x1,  y1, x1+LEN_ID , y1 + 4 + (GetFontYSIZE(TEXT_FONT))*2, 0, 0, 0, cfgPanBGCol_ID_dis, cfgPanBGCol_ID_dis );
            wsprintf(ws, percent_t, LG_SETBOOKS_IDLE_1);
            DrawString( ws, x1,  y1 + 2, x1+LEN_ID,  y1 + 2 + GetFontYSIZE(TEXT_FONT), TEXT_FONT, 2, cfgFontCol_ID, GetPaletteAdrByColorIndex( 23 ) );
            wsprintf(ws, percent_t, LG_SETBOOKS_IDLE_2);
            DrawString( ws, x1,  y1 + 2 + GetFontYSIZE(TEXT_FONT), x1+LEN_ID,  y1 + 4 + (GetFontYSIZE(TEXT_FONT))*2, TEXT_FONT, 2, cfgFontCol_ID, GetPaletteAdrByColorIndex( 23 ) );
            FreeWS(ws);
          }
        }
        else 
          if ( NumOfItems_idle > 0 && IdleMenuActive)
             {
               DrawIdleMenu();
             }
        if(ConfigUpdated)
        {
          ShowMSG(1,(int)LG_INITCFG);
          ConfigUpdated=0;
        }
      }
    }
  }
}

void TimerProc()// ����������� �� �������
{
    RedrawScreen();
    GBS_SendMessage(MMI_CEPID,MSG_IPC,IPC_UPDATE_STAT,&my_ipc);
}
/*
int maincsm_onmessage(CSM_RAM* data,GBS_MSG* msg)
{
  if(msg->msg == MSG_RECONFIGURE_REQ) 
  {
    extern const char *successed_config_filename;
    if (strcmp_nocase(successed_config_filename,(char *)msg->data0)==0)
    {
      ConfigUpdated=1;
      InitConfig();
      MenuInit();
    }
  }
  if (msg->msg==MSG_IPC)// IPC
  {
    IPC_REQ *ipc;
    if ((ipc=(IPC_REQ*)msg->data0))
    {
      if (strcmp_nocase(ipc->name_to,ipc_my_name)==0)// ���� ������� ����������� ���������
      {
        switch (msg->submess)
        {
        case IPC_UPDATE_STAT:
          GBS_StartTimerProc(&idle_timer, 10*TMR_SECOND/28, TimerProc);
        }
      }
    }
  }
  return(1);
}
*/  
int maincsm_onmessage(CSM_RAM* data,GBS_MSG* msg)
{
  if(msg->msg == MSG_RECONFIGURE_REQ) 
  {
    extern const char *successed_config_filename;
    if (strcmp_nocase(successed_config_filename,(char *)msg->data0)==0)
    {
       ConfigUpdated=1;
        InitConfig();      
       x1=xx1; y1=yy1;IDLE_GORIZ=IDLE_GORIZO;     
       K=K1; L=L1; M=M1; N=N1; P=P1; R=R1;
      MenuInit();
    }
  }
  if (msg->msg==MSG_IPC)// IPC
  {
    IPC_REQ *ipc;
    if ((ipc=(IPC_REQ*)msg->data0))
    {
      if (strcmp_nocase(ipc->name_to,ipc_my_name)==0)// ���� ������� ����������� ���������
      {
        switch (msg->submess)
        {
        case IPC_UPDATE_STAT:
              RedrawScreen();
          GBS_StartTimerProc(&idle_timer, 10*TMR_SECOND/40, TimerProc);
        }
      }
    }
  }
  return(1);
}
   //   x1=xx1; y1=yy1;IDLE_GORIZ=IDLE_GORIZO;     
     //  K=K1; L=L1; M=M1; N=N1; P=P1; R=R1;
static void maincsm_oncreate(CSM_RAM *data)
{
 if (FASTRUN_ENA) 
 {
   AddKeybMsgHook((void *)FastRun_KeyHook);
   FR_KEYHOOK_ENA=1;
 }
 else FR_KEYHOOK_ENA=0;
 if (IDLE_ENA) 
 {
   AddKeybMsgHook((void *)IDLE_KeyHook);
   IDLE_KEYHOOK_ENA=1;
 }
 else IDLE_KEYHOOK_ENA=0;
 MenuInit();
 InitFastRunMenu();
 GBS_SendMessage(MMI_CEPID,MSG_IPC,IPC_UPDATE_STAT,&my_ipc);
  //==============================================================
  //==============================================================
 char *exe=0, *par=0;
 if (emenu>0){
   emenu=0;
   WSHDR *ws=AllocWS(512);
   str_2ws(ws,FILE_EMENU,strlen(FILE_EMENU)+1);
   ExecuteFile(ws,0,par);
   FreeWS(ws);}
  //==============================================================
}

static void Killer(void)
{
  extern void *ELF_BEGIN;
  kill_data(&ELF_BEGIN,(void (*)(void *))mfree_adr());
}

static void maincsm_onclose(CSM_RAM *csm)
{
  if (FR_KEYHOOK_ENA) RemoveKeybMsgHook((void *)FastRun_KeyHook);
  if (IDLE_KEYHOOK_ENA) RemoveKeybMsgHook((void *)IDLE_KeyHook);
  GBS_DelTimer(&idle_timer);
  SUBPROC((void *)Killer);
}

static unsigned short maincsm_name_body[140];

static const struct
{
  CSM_DESC maincsm;
  WSHDR maincsm_name;
}MAINCSM =
{
  {
  maincsm_onmessage,
  maincsm_oncreate,
#ifdef NEWSGOLD
  0,
  0,
  0,
  0,
#endif
  maincsm_onclose,
  sizeof(CSM_RAM),
  1,
  &minus11
  },
  {
    maincsm_name_body,
    NAMECSM_MAGIC1,
    NAMECSM_MAGIC2,
    0x0,
    139
  }
};


static void UpdateCSMname(void)// ��� ����� � �����
{
  wsprintf((WSHDR *)(&MAINCSM.maincsm_name),"FastRun::Night");
}
// ----------------------------------------------------------------------------


int main(const char *exename, const char *filename)
{

  CSMROOT *csmr;
  CSM_RAM *save_cmpc;
  CSM_RAM main_csm;
  InitConfig();
  x1=xx1; y1=yy1;IDLE_GORIZ=IDLE_GORIZO; 
  K=K1; L=L1; M=M1; N=N1; P=P1; R=R1;
  
  UpdateCSMname();
  LockSched();
  csmr=CSM_root();
  save_cmpc=csmr->csm_q->current_msg_processing_csm;
  csmr->csm_q->current_msg_processing_csm=csmr->csm_q->csm.first;
  CreateCSM(&MAINCSM.maincsm,&main_csm,0);
  csmr->csm_q->current_msg_processing_csm=save_cmpc;
  UnlockSched();
  return (0);
}
