#include "..\inc\swilib.h"
#include "rect_patcher.h"
#include "../inc/cfg_items.h"
#include "conf_loader.h"

//-----------------------------------------------------//
//�� �������� ����������,�� ��� ����� � ����� ������� :)
const int minus11=-11;
unsigned short maincsm_name_body[140];

unsigned int MAINCSM_ID = 0;
unsigned int MAINGUI_ID = 0;
typedef struct
{
  CSM_RAM csm;
  int gui_id;
}MAIN_CSM;

typedef struct
{
  GUI gui;
  WSHDR *ws1;
  WSHDR *ws2;
  int i1;
}MAIN_GUI;

//��������� ���������� �� �������
extern const int font;
extern void InitConfig();

//----------------------------------//

//����������� ������, ���������� ��������� �� ������:)�� ����������� ������ ������ ��� ������ �� 5 �����
int x=0,y=0;//���������� ��� ����������
int col;//���� �������
int i=15;//������� ����������:)


int scrX=0; //���������� ������ ������������ ������ �����
int scrY=0;
int cursorX=0; //���������� ������� � �����
int cursorY=0;
int Xscr=10;  // ������� ���������� � ������ 
              // ������ ���������� � ������� ��������� ����� 
int Yscr=16;
int i;
int y;
int x;
int p;
void printmap();
int npic (int x,int y);
void printpic (int x,int y,int numer);
void printCUR ();
void vverh ();
void vniz ();
void vpravo ();
void vlevo ();
void vibor ();
  
extern char map[3728]=// ����� ���������
{
  0x14,0x14,// ������ ����� �� �������� 20 �� 20
  
  0x01,0x03,0x02,0x07,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x0A,0x02,0x04,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x06,0x08,0x09,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  
};

static void OnRedraw(MAIN_GUI *data)//��� ������� ����� ��� ����������� ������,��� ������ ��� ��� ��� �����
{
  printmap ();
  printCUR ();
}




// ��� ���� ������� ��������� � � �///////////////////////////////////////////////////////////////////
int npic (int x,int y){// ������� ���������� ����� �������� �� ����� � � � ���������
 i=1;
 p=1;
i=2+x+y*map[0];
int p=map[i];
return p;
}




void printpic (int x,int y,int numer){//������ �������� �� ����� ���������� �� ������ � �����
char *path=malloc(128);
sprintf(path, "4:\\zbin\\Black Raven\\img\\map\\%d.png", numer);
DrawImg(x,y,(int)path);
}
void printCUR (){
 int scrCURx;
 int scrCURy;
 scrCURx=Xscr+(cursorX-scrX)*30;
 scrCURy=Yscr+(cursorY-scrY)*30;
DrawImg(scrCURx,scrCURy,(int)"4:\\zbin\\Black Raven\\img\\map\\0.png");
 
}
void printmap (){
  int scr_w=ScreenW();//����������� ���������� ������ � ������ ������
  int scr_h=ScreenH();
  DrawRoundedFrame(0,0,ScreenW()-1,ScreenH()-1,0,0,0,GetPaletteAdrByColorIndex(4),GetPaletteAdrByColorIndex(1));//������ ���
  
  x=Xscr;   //���������� ������ ������ ����� � ������
  y=Yscr;
  int xm=scrX;  // ���������� ������ � �����
  int ym=scrY;
  int i=1;
  i=npic(xm,ym);
  printpic (x,y,);
  x=+30,xm=+1;
    i=npic(xm,ym);
  printpic (x,y,i);
  x=+60,xm=+1;
    i=npic(xm+2,ym);
  printpic (x,y,i);
  x=+90,xm=+1;
    i=npic(xm+3,ym);
  printpic (x,y,i);
  x=+120,xm=+1;
  
  
  for (i=1;i<5;i++)
  {
    
  }
  
  /*xm=scrX;
  ym=scrY+1;
  x=Xscr;
  y=Yscr+30;
  i=1;
  
   i=npic(xm,ym);
  printpic (x,y,i);
  x=+30,xm=+1;
    i=npic(xm,ym);
  printpic (x,y,i);
  x=+60,xm=+1;
    i=npic(xm+2,ym);
  printpic (x,y,i);
  x=+90,xm=+1;
    i=npic(xm+3,ym);
  printpic (x,y,i);
  x=+120,xm=+1;
  
   xm=scrX;
  ym=scrY+2;
  x=Xscr;
  y=Yscr+60;
  i=1;
  
   i=npic(xm,ym);
  printpic (x,y,i);
  x=+30,xm=+1;
    i=npic(xm,ym);
  printpic (x,y,i);
  x=+60,xm=+1;
    i=npic(xm+2,ym);
  printpic (x,y,i);
  x=+90,xm=+1;
    i=npic(xm+3,ym);
  printpic (x,y,i);
  x=+120,xm=+1;
  
   xm=scrX;
  ym=scrY+3;
  x=Xscr;
  y=Yscr+90;
  i=1;
  
   i=npic(xm,ym);
  printpic (x,y,i);
  x=+30,xm=+1;
    i=npic(xm,ym);
  printpic (x,y,i);
  x=+60,xm=+1;
    i=npic(xm+2,ym);
  printpic (x,y,i);
  x=+90,xm=+1;
    i=npic(xm+3,ym);
  printpic (x,y,i);
  x=+120,xm=+1;
  
   xm=scrX;
  ym=scrY+4;
  x=Xscr;
  y=Yscr+120;
  i=1;
  
   i=npic(xm,ym);
  printpic (x,y,i);
  x=+30,xm=+1;
    i=npic(xm,ym);
  printpic (x,y,i);
  x=+60,xm=+1;
    i=npic(xm+2,ym);
  printpic (x,y,i);
  x=+90,xm=+1;
    i=npic(xm+3,ym);
  printpic (x,y,i);
  x=+120,xm=+1;
  */
 }

// ��������� ������� �����
void vverh ()
{
 if(cursorY-scrY==0)
 {
   scrY--;
 }
 cursorY--;
}
// ��������� ������� ����
  void  vniz ()
  {
  if(cursorY-scrY==4)
  
  {
  scrY++;
  }
cursorY++;  
  }

// ��������� ������� ������
  void vpravo ()
{
 if(cursorX-scrX==3)
 {
   scrX++;
 }
 cursorX++;
}


// ��������� ������� �����
  void vlevo ()
  
 {
 if(cursorX-scrX==0)
 {
   scrX--;
 }
 cursorX--;
}

// ��������� ������� �����

  void vibor (){
  }


//-----------------------------------------------------------------------------------------------------



static void onCreate(MAIN_GUI *data, void *(*malloc_adr)(int))//��� ������ ��� ���� ��� �������� ���
{
#ifdef ELKA//���� ����,�� ��������� �������
  DisableIconBar(1);
#endif
  data->ws1=AllocWS(256);//�������� ������ ��� ������
  data->gui.state=1;
}

static void onClose(MAIN_GUI *data, void (*mfree_adr)(void *))//����� ������ ��� ���� ��� �������� ���:)
{
  data->gui.state=0;
  FreeWS(data->ws1);//��������, ����������� ������
}

static void onFocus(MAIN_GUI *data, void *(*malloc_adr)(int), void (*mfree_adr)(void *))//���� ��� �� ����� �� ����� �� ������ ��� �����
{
  data->gui.state=2;
  DisableIDLETMR();//��������� ������,����� ����� 2 ������ ���� ���������
}

static void onUnfocus(MAIN_GUI *data, void (*mfree_adr)(void *))//� ���� ��� �� ������,�� ����� ������� ���� ��������:)
{
  if (data->gui.state!=2) return;
  data->gui.state=1;
}

static int OnKey(MAIN_GUI *data, GUI_MSG *msg)//�� ��� ��� ���
{
  DirectRedrawGUI(); //�������������� ����� ��� ����� ������� �������,���� ����� ������������ REDRAW();
  if (msg->gbsmsg->msg==KEY_DOWN)//���� ������� ������
  {
    
    switch(msg->gbsmsg->submess)
    {
    case UP_BUTTON: case '2':vverh ();break;
    case DOWN_BUTTON: case '8':vniz ();break;
    case RIGHT_BUTTON: case '6':vpravo ();break;
    case LEFT_BUTTON: case '4':vlevo ();break;
    case ENTER_BUTTON:vibor ();break;
    case RIGHT_SOFT:case RED_BUTTON:
      return (1);
    }
  }
  if (msg->gbsmsg->msg==LONG_PRESS)//��� ��������
  {
    
    switch(msg->gbsmsg->submess)
    {
    case UP_BUTTON: case '2':vverh ();break;
    case DOWN_BUTTON: case '8':vniz ();break;
    case RIGHT_BUTTON: case '6':vpravo ();break;
    case LEFT_BUTTON: case '4':vlevo ();break;
    case RIGHT_SOFT:case RED_BUTTON:
      return (1);
    }
  }
  return(0);
}

extern void kill_data(void *p, void (*func_p)(void *));//��� ������� ������� ���� � ����������� ������

int method8(void){return(0);}
int method9(void){return(0);}

const void * const gui_methods[11]={
  (void *)OnRedraw,
  (void *)onCreate,
  (void *)onClose,
  (void *)onFocus,
  (void *)onUnfocus,
  (void *)OnKey,
  0,
  (void *)kill_data,
  (void *)method8,
  (void *)method9,
  0
};

static void maincsm_oncreate(CSM_RAM *data)//���������� ��� �������� �����,������ ��� �����
{
  //��� ������ ��������� ��� ��������� �� ��� ����� ���� ���� � ��� ��������������
  static const RECT Canvas={0,0,0,0};
  MAIN_GUI *main_gui=malloc(sizeof(MAIN_GUI));
  MAIN_CSM*csm=(MAIN_CSM*)data;
  zeromem(main_gui,sizeof(MAIN_GUI));
  patch_rect((RECT*)&Canvas,0,YDISP,ScreenW()-1,ScreenH()-1);
  main_gui->gui.canvas=(void *)(&Canvas);
  main_gui->gui.flag30=2;
  main_gui->gui.methods=(void *)gui_methods;
  main_gui->gui.item_ll.data_mfree=(void (*)(void *))mfree_adr();
  csm->csm.state=0;
  csm->csm.unk1=0;
  csm->gui_id=CreateGUI(main_gui);
}

void ElfKiller(void)//����������� ��� ������� ����� ������ � ���������
{
  extern void *ELF_BEGIN;
  kill_data(&ELF_BEGIN,(void (*)(void *))mfree_adr());
}


static void maincsm_onclose(CSM_RAM *csm)//������� �������� �����,��� ����������� ������ ���� ����� � �.�.
{
  SUBPROC((void *)ElfKiller);
}


#pragma inline=forced
int toupper(int c)
{
  if ((c>='a')&&(c<='z')) c+='A'-'a';
  return(c);
}
#pragma inline
int strcmp_nocase(const char *s1,const char *s2)
{
  int i;
  int c;
  while(!(i=(c=toupper(*s1++))-toupper(*s2++))) if (!c) break;
  return(i);
}

static int maincsm_onmessage(CSM_RAM *data, GBS_MSG *msg)//��� ������� ��������� ��� ��������� ����������� �� ����� ��� �������:)
{
  //��������� � �������������� ��������,��� � �.�. � �.�.
  MAIN_CSM *csm=(MAIN_CSM*)data;
  if ((msg->msg==MSG_GUI_DESTROYED)&&((int)msg->data0==csm->gui_id))
  {
    csm->csm.state=-3;
  }
  if (msg->msg==MSG_RECONFIGURE_REQ)//���� ���� ��������������,�� ��������� ��������� �����
  {
    extern const char *successed_config_filename;
    if (strcmp_nocase(successed_config_filename,(char *)msg->data0)==0)
    {
      ShowMSG(1,(int)"example config updated!");
      InitConfig();
    }
  }

  return(1);
}


static const struct//��� ��������� ���,����������� �� ����:)
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
  sizeof(MAIN_CSM),
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

void UpdateCSMname(void)//�� ���������� ��� ����� ������������ ������
{
  wsprintf((WSHDR *)(&MAINCSM.maincsm_name),"example");
}


int main(char *exename, char *fname)//exename-���� ������������ �����, fname �������� ������������ �����
{
  MAIN_CSM main_csm;
  InitConfig();//���������� ������,������ ������ ��������� �� ����
  LockSched();
  UpdateCSMname();//��������� ��� ��� ������
  CreateCSM(&MAINCSM.maincsm,&main_csm,0);//������� ���
  UnlockSched();
  return 0;
}
