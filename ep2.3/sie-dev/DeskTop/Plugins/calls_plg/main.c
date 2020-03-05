#include "..\..\..\inc\swilib.h"
#include "..\..\plglib.h"
#include "..\..\plglib.c"


extern void kill_data(void *p, void (*func_p)(void *));
static void Killer(void)
{
  extern void *ELF_BEGIN;
  kill_data(&ELF_BEGIN,(void (*)(void *))mfree_adr());
}


struct{
	char num[64];
	char pos;
}NMS; // ����� ��� ����� ������

int f_h; // ������ ������� ������
WSHDR *ews;
DT *dt; // ��������� �� �������� ���������

DT_ICON *MI; // ��������� �� ��������� ���� ������

const char call_txt[]="�����";






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

// DrwImg(IMGHDR *img, int x, int y, char *pen, char *brush)
// {
  // RECT rc;
  // DRWOBJ drwobj;
  // StoreXYWHtoRECT(&rc,x,y,img->w,img->h);
  // SetPropTo_Obj5(&drwobj,&rc,0,img);
  // SetColor(&drwobj,pen,brush);
  // DrawObject(&drwobj);
// }


extern PGUI_methods numgui;
 //Redraw
static void gOnRedraw() // ����������� ����
{
	
	DrawRectangle(numgui.p.x,numgui.p.y,numgui.p.x2,numgui.p.y2,0,black,black); // ��� ����
	
	// ������ ���������� �����
	wsprintf(ews, perc_t, NMS.num); // �������� �����
	DrawString(ews,numgui.p.x, numgui.p.y, numgui.p.x2,numgui.p.y2, FONT_MEDIUM,TEXT_ALIGNMIDDLE,white,NULL); // ����� ������ �� �����
	
	// ������ ������:
	wsprintf(ews, perc_t, call_txt); // ����� ������ ������
	DrawRectangle(numgui.p.x+3, numgui.p.y2-f_h-5, numgui.p.x+5+Get_WS_width(ews, FONT_SMALL), numgui.p.y2-3, 0,white,black); // ����� ������
	DrawString(ews, numgui.p.x+3, numgui.p.y2-f_h-5, numgui.p.x+5+Get_WS_width(ews, FONT_SMALL), numgui.p.y2-3, FONT_SMALL,TEXT_ALIGNMIDDLE,white,NULL); // ����� ������ ������
}

 //Create
static void gOnCreate() // ��� �������� ����
{
	f_h=GetFontYSIZE(FONT_SMALL); // ������ ������ ������� ������
	ews=AllocWS(256); // ����
	zeromem(&NMS,sizeof(NMS)); // ����
	StoreXYXYtoRECT(&numgui.p, 10, ScreenH()/4, ScreenW()-10, ScreenH()/2); // ����� ��������� ��������� ����
}

 //Close
static void gOnClose() // ��� �������� ����
{
	FreeWS(ews);
}


/////////////////////////
///////////������////////
/////////////////////////

int key_call(GUI_MSG *msg) // ������� �� ������ ������
{
  if(NMS.pos>1) // ���� ������� ������ ������ ������� � ������
  {
	MakeVoiceCall(NMS.num,0x10,0x2FFF); // ������
	return 1; // � ��������� ����
  }
  return 0; // ����� ��������� ����
}

PG_BUTTON btn_call= // ������ ������
{
  0,0, //void *prev,*next; // �� �������
  0, //int n; // �� �������
  {0,0,0,0}, //RECT r; // �� �������
  0, //char *inf; // �� �������
  key_call //int (*Enter)(); // ����������� �� ������� �� ������
};


/////////////////////////
/////////////////////////
/////////////////////////


 //Focus
static void gOnFocus() // ��� ����� "������" ��������� � ����
{
  RECT tp;
  wsprintf(ews, perc_t, call_txt);
  StoreXYWHtoRECT(&tp, 3, numgui.w->h-f_h-5, 5+Get_WS_width(ews, FONT_SMALL), numgui.w->h-3); // ����� ������� ��� ������
  dt->pf->add_btn(&numgui, &btn_call, &tp); // ��������� ������ � ������
}

 //Unfocus
static void gOnUnfocus() // ���� �� �����������
{
}

 //OnKey
static int gOnKey(GUI_MSG *msg) // ��������� ������ ��� �������� ����
{
	int m=msg->gbsmsg->msg;
	int sm=msg->gbsmsg->submess;
	switch(m)
	{
		case LONG_PRESS:
			switch(sm)
			{
				case '0':
					if(NMS.pos==1) NMS.num[0]='+';
					return -1;
				case RIGHT_SOFT:
					if(NMS.pos)
						if(strlen(NMS.num)) zeromem(&NMS,sizeof(NMS));
					return -1;
			}
			break;
		case KEY_DOWN:
			if(((sm>='0')&&(sm<='9')) || (sm=='*') || (sm=='#'))
			{
				NMS.num[NMS.pos++]=sm;
				return -1;
			}
			switch(sm)
			{
				case RIGHT_SOFT:
					if(NMS.pos && strlen(NMS.num)) NMS.num[--NMS.pos]=0;
					else return 1;
					return -1;
				case RED_BUTTON:
					return 1;
// 				case ENTER_BUTTON: // ����� �������� �� �����
// 					if(dt->actpg->n==4)
// 					{
// 						if(NMS.pos>1)
// 						{
// 							MakeVoiceCall(NMS.num,0x10,0x2FFF);
// 							return 1;
// 						}
// 						return 2;
// 					}
// 					return 0;
				case LEFT_SOFT:
					return 2;
				case GREEN_BUTTON:
						if(NMS.pos>1)
						{
							MakeVoiceCall(NMS.num,0x10,0x2FFF);
							return 1;
						}
					return 2;
			}
	//DirectRedrawGUI();
			break;
	}
  //curkey(msg);
	//DirectRedrawGUI();
	return 0;
}

PGUI_methods numgui={ // ��������� ����
	0,0,
	"Number", // ���
	0, // state (PG_st_norm-������� ����, PG_st_max-�� ���� �����)
	1+2, // type (0-without cursor, 1-with cursor, +2-with window, +4-disactive desctop) ���� �����, ����� ����� ������ 0 ��� 3
	0, // ���� ������, �� ������
	0,
	{10,30,100,120},{0,0,0,0}, // ����������
	gOnRedraw, // ������� �����������
	gOnCreate, // ����������� ��� �������� ����
	gOnClose, // ����������� ��� �������� ����
	gOnFocus, // ��� ������ ����� ��������� 
	gOnUnfocus, // ���� �� ������� 
	gOnKey, // ��������� ������ 
	NULL, // �� ������� 
	NULL, // �� ������� 
	{0,0,0,0} // �� ������� 
// 	void *next;
};












// void onMessage(GBS_MSG* msg)
// {
// }


int onEnter() // ������� �� ������
{
	dt->pf->Cr_PGUI(&numgui); // ������ ����
	return 0;
}

void onClose() // ��� �������� ��������
{
    SUBPROC((void *)Killer);
}

void Refresh() // ���������� (��� �� �����)
{
}

void onInf() // ������� ������ ����������� ���������
{
	zeromem(MI->inf, 256);
	sprintf(MI->inf, "%s", MI->nm); // ���� ��� ������
}

int main(char *exename, char *fname)
{
	if((int)fname>=0xa0000000) // fname ������������� ���������
	{
	  // �� ������� ///////////////////////////
	  PLG_P *TP=(PLG_P*)fname; // �� �������
	  MI=TP->ic; // ���� ������
	  dt=TP->dt; // �������� ���������
	  MI->d=1; // �� �������
	  /////////////////////////////////////////
	  
	  //MI->onDraw=onDraw; // ������� ������� ��������� ������ (����� �� �����, ������������ �����������)
	  MI->onEnter=onEnter; // ������� ������� �� ������� �� ������
	  MI->onInf=onInf; // ������� ������� ������ ����������� ���������
	  MI->dyn=0; // �� ������������ (�������� ��������, �������� � ���������� ������) ���� 1, ���������� ������ onDraw
	  MI->sel=0; // �� ����� ����
	  MI->onClose=onClose; // ������� ������� ��� �������� ��������
	  MI->Refresh=NULL;//Refresh; // ���������� ������
// 	  MI->onMessage=onMessage; // �� ��������
	  dt->ef->fill_icons(3); // ��������� ����������������
	}
	else
	  SUBPROC((void *)Killer); // ����������� ���� fname ����� �� ���������
  return 0;
}
