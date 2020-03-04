#include "main.h"
#define SKIN   //���, �������� - COLOR,BG,SKIN 
#define STD    //����, �������� - ADV,STD
#define TMR_SECOND 216

char white[4]={0xFF,0xFF,0xFF,0x60};
char RED[4]={0xFF,0x00,0x00,0x60};
char prozr[4]={0x00,0x00,0x00,0x00};
char black[4]={0x00,0x00,0x00,0x60};

const char IMG1[126]="0:\\shell\\icons\\app.png";
const char IMG2[126]="0:\\shell\\icons\\BCFG.png";
const char IMG3[126]="0:\\shell\\icons\\calendar.png";
const char IMG4[126]="0:\\shell\\icons\\dev.png";
const char IMG5[126]="0:\\shell\\icons\\ELF.png";
const char IMG6[126]="0:\\shell\\icons\\explorer.png";
/*
const char MENU1_s[128]="2:\\japp\\FlexMenu\\1_s.png";//��������� ������
const char MENU2_s[128]="2:\\japp\\FlexMenu\\2_s.png";
const char MENU3_s[128]="2:\\japp\\FlexMenu\\3_s.png";
const char MENU4_s[128]="2:\\japp\\FlexMenu\\4_s.png";
const char MENU5_s[128]="2:\\japp\\FlexMenu\\5_s.png";
const char MENU6_s[128]="2:\\japp\\FlexMenu\\6_s.png";

const char MENU1_b[128]="2:\\japp\\FlexMenu\\1_b.png";//�������
const char MENU2_b[128]="2:\\japp\\FlexMenu\\2_b.png";
const char MENU3_b[128]="2:\\japp\\FlexMenu\\3_b.png";
const char MENU4_b[128]="2:\\japp\\FlexMenu\\4_b.png";
const char MENU5_b[128]="2:\\japp\\FlexMenu\\5_b.png";
const char MENU6_b[128]="2:\\japp\\FlexMenu\\6_b.png";
*/
const char MENU1_s[128]="0:\\shell\\menu\\1_s.png";//��������� ������
const char MENU2_s[128]="0:\\shell\\menu\\2_s.png";
const char MENU3_s[128]="0:\\shell\\menu\\3_s.png";
const char MENU4_s[128]="0:\\shell\\menu\\4_s.png";
const char MENU5_s[128]="0:\\shell\\menu\\5_s.png";
const char MENU6_s[128]="0:\\shell\\menu\\6_s.png";

const char MENU1_b[128]="0:\\shell\\menu\\1_b.png";//�������
const char MENU2_b[128]="0:\\shell\\menu\\2_b.png";
const char MENU3_b[128]="0:\\shell\\menu\\3_b.png";
const char MENU4_b[128]="0:\\shell\\menu\\4_b.png";
const char MENU5_b[128]="0:\\shell\\menu\\5_b.png";
const char MENU6_b[128]="0:\\shell\\menu\\6_b.png";

const char bg3img[128]="0:\\shell\\img\\BG.png";

GBSTMR timer,menu_tmr;
int panel_x=20,panel_y=120;//���������� ������
int Cross_x,Cross_y;//���������� ��������
int imd_x=0,img_y=2;//���������� �������� ��� ������
int menu_x=40,menu_y=140;
unsigned int *err;
char per_s[]="%s";
char per_d[]="%d";
char per_t[]="%t";
char per_6s[]="%s\n%s\n%s\n%s\n%s\n%s";

int DrawPuskk=0;//1-�������, 0-���

int start(char name[128])//������ ������
{
 WSHDR *ws;
 ws=AllocWS(256);
 str_2ws(ws,name,256);
 ExecuteFile(ws,0,0);
 FreeWS(ws);
 return(1);
}

char *shortcut(char cut[15])//������ ���������
{
int (*p) (void);
 p=(int(*)(void))GetFunctionPointer(cut);
 if(p!=NULL)
  (*p)();
 else
   ShowMSG(1,(int)"NULL pointer function!");
return 0;
}
GBSTMR mytmr;
void TimerProc(void)
{  REDRAW();
   GBS_StartTimerProc(&mytmr,TMR_SECOND,TimerProc);
}

//=============================================================================
void DrawBG()
{
//#ifdef COLOR
  if(workdesctop==1)
  DrawRoundedFrame(0,0,131,175,0,0,0,GetPaletteAdrByColorIndex(4),GetPaletteAdrByColorIndex(1)); 
//#endif
   
//#ifdef BG  
  if(workdesctop==2)
  {
    void *canvasdata=BuildCanvas();
    DrawCanvas(canvasdata,0,0,132,176,1);
  }
  //WSHDR *ws=AllocWS(64);
//  wsprintf(ws,"%d",Items[0].x);
  //DrawString(ws,2,160,128,172,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
     
//#endif  
  
//#ifdef SKIN 
  if(workdesctop==3)
  {
    void *canvasdata=BuildCanvas();
    DrawCanvas(canvasdata,0,0,132,176,1);
    DrawImg(0,0,(int)bg3img);
  }
//#endif*/
}



//--------------------------------------------------
void DrawNetAdv(int x, int y)
{
    for (int i=0; i!=6; i++)  
      if((RamNet()+i)->power!=0) 
        DrawRoundedFrame(x+i*5,y+14-((115-(RamNet()+i)->power)/4),x+3+i*5,y+14,0,0,0,
           GetPaletteAdrByColorIndex( (((RamNet()+i)->ch_number)<255)?2:4 ),
               GetPaletteAdrByColorIndex( (((RamNet()+i)->ch_number)<255)?2:4) );
}


void DrawNetStd(int x, int y)
{
  #define NET_PIC_NUM 860//cx75/25
    DrawImg(x,y,(115-(RamNet()->power))/6+NET_PIC_NUM);
}
    
void DrawNetDb(int x, int y)
{
      WSHDR *ws = AllocWS(256); 
      wsprintf(ws, "%c%ddb",(RamNet()->ch_number<255)?'-':'=',RamNet()->power);
      DrawString(ws,x,y,128,172,7,0,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(23)); 
      FreeWS(ws);
}


void DrawNetExt(int x, int y)
{ 
  int gh=(((RamNet())->ch_number)<255)?2:4 ;
  
  /*DrawLine(x+2,y,x+2,y+5,0,GetPaletteAdrByColorIndex(gh));
  DrawLine(x,y,x+4,y,0,GetPaletteAdrByColorIndex(gh));
  
  SetPixel(x,y+1,GetPaletteAdrByColorIndex(gh));
  SetPixel(x+4,y+1,GetPaletteAdrByColorIndex(gh));
  
  SetPixel(x,y+2,GetPaletteAdrByColorIndex(gh));
  SetPixel(x+4,y+2,GetPaletteAdrByColorIndex(gh));
  
  SetPixel(x+1,y+3,GetPaletteAdrByColorIndex(gh));
  SetPixel(x+3,y+3,GetPaletteAdrByColorIndex(gh));*/
  
  x=x+6;
  for(int i=(RamNet()->power==0 || RamNet()->power<111)?112:RamNet()->power; i!=111; i=i+2,x++)
  {
    SetPixel(x+4,y,GetPaletteAdrByColorIndex(gh));
    SetPixel(x+3,y+1,GetPaletteAdrByColorIndex(gh));
    SetPixel(x+2,y+2,GetPaletteAdrByColorIndex(gh));
    SetPixel(x+1,y+3,GetPaletteAdrByColorIndex(gh));
    SetPixel(x,y+4,GetPaletteAdrByColorIndex(gh));
    SetPixel(x-1,y+5,GetPaletteAdrByColorIndex(gh));
  }
}
  
  
//--------------------------------------------------
void DrawBattStd(int x, int y)
{ 
#define BATT_PIC_NUM 601//cx75/25
  DrawImg(x,y,(BATT_PIC_NUM+*RamCap()/9));
}

void DrawBattExt(int x, int y)
{ 
  DrawImg(x,y,(BATT_PIC_NUM+*RamCap()/9));
}


void DrawBattCap(int x, int y)
{ 
      WSHDR *ws = AllocWS(256); 
      wsprintf(ws, "%d%%",*RamCap());
      DrawString(ws,x,y,128,172,7,0,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(23)); 
      FreeWS(ws);
}


void DrawBattVolt(int x, int y)
{ 
      WSHDR *ws = AllocWS(256); 
      wsprintf(ws, "%d,%dV",(GetAkku(0,9))/1000,(GetAkku(0,9))%1000/10);
      DrawString(ws,x,y,128,172,7,0,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(23)); 
      FreeWS(ws);
}




//--------------------------------------------------
void DrawClock(int x, int y)
{
  #pragma swi_number=0x80CF
  __swi __arm int *RamAlarm();
  
  TDate date;
  TTime time;
  WSHDR *ws = AllocWS(256); 
   
  GetDateTime(&date,&time); 

  wsprintf(ws, "%c%02d:%02d:%02d",(*RamAlarm()==15)?57750:' ',time.hour,time.min,time.sec);
  DrawString(ws,x,y,128,172,7,0,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(23)); 
 
  FreeWS(ws);
}




//--------------------------------------------------
void DrawBar(x,y)
{
  ;
}

/*void DrawOperator(int x,int y)
{
  #pragma swi_number=0x81F4
__swi __arm int GetOperator();

  WSHDR *ws = AllocWS(256);

 unsigned char *serv=(unsigned char*)0xA868BE3D;
 // int adr=0x68BE3C;

  wsprintf(ws, "%s",serv);
  DrawString(ws,x,y,132,176,7,0,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(23)); 
 
  FreeWS(ws);
}*/



//--------------------------------------------------
void DrawDialogs(int x, int y)
{
      int z,i;   
      for (i=0,z=0; i!=5000; i++)  {if (FindCSMbyID(i)!=NULL) z++;}
    
    WSHDR *ws = AllocWS(256);
    wsprintf(ws, "csm:%i",z);
      DrawString(ws,x,y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
    FreeWS(ws);
}

//--------------------------------------------------
void DrawFreeRam(int x, int y)
{
 WSHDR *ws = AllocWS(256); 
 wsprintf(ws, per_d,GetFreeRamAvail()/1000);
 DrawString(ws,x,y,128,172,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
 FreeWS(ws);
}
//==================================================
void DrawCross(int x, int y,char color[4])//�������:) type:0-cross, 1-img
{ /*DrawLine(x,y,x+8,y,0,color);
  DrawLine(x+4,y-4,x+4,y+4,0,color);*/
if(typecur)
  DrawImg(x,y,(int)"0:\\shell\\img\\cursor.png");
else 
{
  DrawLine(x,y,x-4,y,0,color);//left
  DrawLine(x,y,x+4,y,0,color);//right
  DrawLine(x,y,x,y+4,0,color);//down
  DrawLine(x,y,x,y-4,0,color);//up
}

}

void DrawLineCross(int x, int y,char color[4],int TypeLine)//������ ��� ���:))))
{
  switch(TypeLine)
  {
  case 1: SetPixel(x+5,y,color);SetPixel(x+6,y+1,color);SetPixel(x+7,y+2,color);SetPixel(x+8,y+3,color); break;
  case 2: SetPixel(x-5,y,color);SetPixel(x-6,y+1,color);SetPixel(x-7,y+2,color);SetPixel(x-8,y+3,color);break;
  case 3: SetPixel(x+5,y,color);SetPixel(x+6,y+1,color);SetPixel(x+7,y+2,color);SetPixel(x+8,y+3,color);break;
  case 4: SetPixel(x+5,y,color);SetPixel(x+6,y+1,color);SetPixel(x+7,y+2,color);SetPixel(x+8,y+3,color);break;
  }
}
  
//==================================================
//char *NAME[6]={"MC","CfgEdit","Calendar","Dev.Menu","NatIcq","Card Explorer"};
void DrawName(int crd,int i,int type)//type: 1-vertical, 0-horizontal
{SaveNamePanel();
 WSHDR *ws2=AllocWS(64);
  wsprintf(ws2,per_s,NAME[i-1]);
  if(type)
       DrawString(ws2,30,crd,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
  else DrawString(ws2,crd,30,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 

 FreeWS(ws2);
}

void DrawContur_w(int y)//������ ������������
{
  DrawRoundedFrame(2,y+1,17,y+17,2,2,0,RED,prozr);
}

void DrawContur_h(int x)//��������������
{
  DrawRoundedFrame(x+1,2,x+17,17,2,2,0,RED,prozr);
}
//==================================================
void DrawPanel_w()//������������ ������
{
  //panel_x=20,panel_y=120;
  void *canvasdata=BuildCanvas();
  int panel_y=name[0].NumItems*20;
  DrawCanvas(canvasdata,1,1,19,panel_y,1);
  DrawRoundedFrame(0,0,19,panel_y,2,2,0,white,prozr);
  DrawImg(2,img_y,(int)name[0].pic);
  DrawImg(2,img_y+20,(int)name[1].pic);
  DrawImg(2,img_y+40,(int)name[2].pic);
  DrawImg(2,img_y+60,(int)name[3].pic);
//  DrawImg(30,140,(int)IMG3);
//  DrawImg(60,140,(int)IMG4);
  DrawImg(2,img_y+80,(int)name[4].pic);
  DrawImg(2,img_y+100,(int)name[5].pic);
  DrawCross(Cross_x,Cross_y,RED);
  GBS_StartTimerProc(&timer,1,DrawPanel_w);
  GBS_StartTimerProc(&timer,1,DrawContur_w);
}
void DrawPanel_h()//��������������
{ 
  void *canvasdata=BuildCanvas();
  DrawCanvas(canvasdata,40,0,panel_y,panel_x,1);
  DrawRoundedFrame( 40,0,panel_y,panel_x,2,2,0,white,prozr);
  DrawImg(img_y+40,2,(int)IMG1);
  DrawImg(img_y+60,2,(int)IMG2);
  DrawImg(img_y+80,2,(int)IMG3);
  DrawImg(img_y+100,2,(int)IMG4);
  //DrawImg(2,img_y+80,(int)IMG5);
  //DrawImg(2,img_y+100,(int)IMG6);
  DrawCross(Cross_x,Cross_y,RED);
  GBS_StartTimerProc(&timer,1,DrawPanel_h);
  GBS_StartTimerProc(&timer,1,DrawContur_h);

}
void DrawNameContr()//������ ������ � �����
  {
   if(Cross_x>=0 && Cross_x<=17 && Cross_y>=0 && Cross_y <=20 && name[0].NumItems>=1)
   { DrawName(2,1,1);
     DrawContur_w(0);
   }
   else if(Cross_x>=0 && Cross_x<=17 && Cross_y>=20 && Cross_y <=40 &&name[0].NumItems>=2)
   { DrawName(19,2,1);
     DrawContur_w(20);
    }
   else if(Cross_x>=0 && Cross_x<=17 && Cross_y>=40 && Cross_y <=60 && name[0].NumItems>=3)
   { DrawName(35,3,1);
     DrawContur_w(40);
   }
   else if(Cross_x>=0 && Cross_x<=17 && Cross_y>=60 && Cross_y <=80 &&name[0].NumItems>=4)
   {   DrawName(52,4,1);
       DrawContur_w(60);
   }
   else if(Cross_x>=0 && Cross_x<=17 && Cross_y>=80 && Cross_y <=100 && name[0].NumItems>=5)
   {   DrawName(69,5,1);
       DrawContur_w(80);
   }
   else if(Cross_x>=0 && Cross_x<=17 && Cross_y>=100 && Cross_y <=120 && name[0].NumItems>=6)
   { DrawName(87,6,1);
     DrawContur_w(100);
   }
   /*//��������������
   else if(Cross_x>=40 && Cross_x<=60 && Cross_y>=0 && Cross_y <=17)
   { DrawName(40,1,0);
     DrawContur_h(40);
   }
   else if(Cross_x>=60 && Cross_x<=80 && Cross_y>=0 && Cross_y <=17)
   {   DrawName(60,2,0);
       DrawContur_h(60);
   }
   else if(Cross_x>=80 && Cross_x<=100 && Cross_y>=0 && Cross_y <=17)
   {   DrawName(80,3,0);
       DrawContur_h(80);
   }
   else if(Cross_x>=100 && Cross_x<=120 && Cross_y>=0 && Cross_y <=17)
   { DrawName(100,4,0);
     DrawContur_h(100);
   }*/
}

void StartFilePanel_w()//��������  ����/����� ��� ������
{    
       if(Cross_x>=0 && Cross_x<=20 && Cross_y>=0 && Cross_y <=20 && name[0].NumItems>=1)
       { if(strlen(name[0].file)==15) shortcut(name[0].file);
         else start(name[0].file);
         GBS_DelTimer(&timer);
         
       }
       else if(Cross_x>=0 && Cross_x<=20 && Cross_y>=20 && Cross_y <=40 && name[0].NumItems>=2)
       { if(strlen(name[1].file)==15) shortcut(name[1].file);
         else start(name[1].file);
         GBS_DelTimer(&timer);
         
       }
       else if(Cross_x>=0 && Cross_x<=20 && Cross_y>=40 && Cross_y <=60 && name[0].NumItems>=3)
       {  if(strlen(name[2].file)==15) shortcut(name[2].file);
         else start(name[2].file);
         GBS_DelTimer(&timer);
     
       }
       else if(Cross_x>=0 && Cross_x<=20 && Cross_y>=60 && Cross_y <=80 && name[0].NumItems>=4)
       { if(strlen(name[3].file)==15) shortcut(name[3].file);
         else start(name[3].file);
         GBS_DelTimer(&timer);
       }
       else if(Cross_x>=0 && Cross_x<=20 && Cross_y>=80 && Cross_y <=100 && name[0].NumItems>=5)
       { if(strlen(name[4].file)==15) shortcut(name[4].file);
         else start(name[4].file);
         GBS_DelTimer(&timer);
        }
       else if(Cross_x>=0 && Cross_x<=20 && Cross_y>=100 && Cross_y <=120 && name[0].NumItems>=6)
        { if(strlen(name[5].file)==15) start(name[5].file);
          else shortcut(name[5].file);
          GBS_DelTimer(&timer);
        }

}

void StartFilePanel_h()//�������� ��� �������������� ������ 
{      if(Cross_x>=0 && Cross_x<=20 && Cross_y>=0 && Cross_y <=20)
       { start("0:\\zbin\\mc\\mc.elf");GBS_DelTimer(&timer);
         //DrawName(2,1);
       }
       else if(Cross_x>=20 && Cross_x<=40 && Cross_y>=0 && Cross_y <=20)
       { start("0:\\zbin\\utilities\\CfgEdit.elf");GBS_DelTimer(&timer);
         //DrawName(20,2);
       }
       else if(Cross_x>=40 && Cross_x<=60 && Cross_y>=0 && Cross_y <=20)
       {  shortcut("ORGZ_CALENDERMV");GBS_DelTimer(&timer);
         //DrawName(40,3);
       }
       else if(Cross_x>=60 && Cross_x<=80 && Cross_y>=0 && Cross_y <=20)
       { shortcut("ELSE_DEVELP_MNU");GBS_DelTimer(&timer);
          //DrawName(60,4);
       }
       else if(Cross_x>=80 && Cross_x<=100 && Cross_y>=0 && Cross_y <=20)
       {  start("0:\\zbin\\naticq\\naticq.elf");
        //  DrawName(80,5);
          GBS_DelTimer(&timer);
        }
     else if(Cross_x>=100 && Cross_x<=120 && Cross_y>=0 && Cross_y <=20)
     {  shortcut("FLSH_FLEXPLORER");
      // DrawName(100,6);
         GBS_DelTimer(&timer);
     }

}
//====================================================

void DrawMenu(int i)//�������
{menu_x=45,menu_y=70; 
 int k;
// void *canvasdata=BuildCanvas();
 //DrawCanvas(canvasdata,1,1,100,130,1);
  switch(i)
  {
  //  case 1:  DrawImg(menu_x,menu_y,(int)mnu[0].big);break;
    case 2:  DrawImg(menu_x,menu_y,(int)MENU2_b);break;
    case 3:  DrawImg(menu_x,menu_y,(int)MENU3_b);break;
    case 4:  DrawImg(menu_x,menu_y,(int)MENU4_b);break;
    case 5:  DrawImg(menu_x,menu_y,(int)MENU5_b);break;
    case 6:  DrawImg(menu_x,menu_y,(int)MENU6_b);break;
  }
  if(i==1)k=6;
  else k=i-1;
   switch(k)
  {
//    case 1:  DrawImg(menu_x-40,menu_y-15,(int)mnu[0].small);break;
    case 2:  DrawImg(menu_x-40,menu_y-15,(int)MENU2_s);break;
    case 3:  DrawImg(menu_x-40,menu_y-15,(int)MENU3_s);break;
    case 4:  DrawImg(menu_x-40,menu_y-15,(int)MENU4_s);break;
    case 5:  DrawImg(menu_x-40,menu_y-15,(int)MENU5_s);break;
    case 6:  DrawImg(menu_x-40,menu_y-15,(int)MENU6_s);break;
  }
  if(i==6)i=0;
   switch(i+1)
  {
    case 1:  DrawImg(menu_x+50,menu_y-15,(int)MENU1_s);break;
    case 2:  DrawImg(menu_x+50,menu_y-15,(int)MENU2_s);break;
    case 3:  DrawImg(menu_x+50,menu_y-15,(int)MENU3_s);break;
    case 4:  DrawImg(menu_x+50,menu_y-15,(int)MENU4_s);break;
    case 5:  DrawImg(menu_x+50,menu_y-15,(int)MENU5_s);break;
    case 6:  DrawImg(menu_x+50,menu_y-15,(int)MENU6_s);break;
  }

GBS_StartTimerProc(&menu_tmr,1,DrawMenu); 

}
void DrawNameMenu(int i)
{
  char *NAME2[6]={"IRDA","Profiles","Internet","Camera","My files","CardExplorer"};
  WSHDR *ws2=AllocWS(64);
  wsprintf(ws2,per_s,NAME2[i-1]);
  DrawString(ws2,45,120,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
  FreeWS(ws2);
}

void StartFileMenu(int i)
{
  switch(i)
  {
//  case 1:shortcut(mnu[0].file);IRDA=!IRDA;break;
  case 2:shortcut("PROF_PROFILEMNU");break;
  case 3:shortcut("ELSE_SUFFUNUMNU");break;
  case 4:shortcut("ELSE_INTRCAMERA");break;
  case 5:shortcut("FLSH_MYOWNSTUFF");break;
  case 6:shortcut("FLSH_FLEXPLORER");break;
  }    
}
//================================================================
//     ������ ����� ��� ������ ������,
//     ��� �� ���� �����:( �� ��������� �������...:(
//================================================================
int dir_size=0;
static DIR_ENTRY de;
int FindSizeInSubDir(char *dir)
{
  unsigned int err;
  char path[256];
  strcpy(path,dir); 
  char *ptr=path+strlen(path)+1;
  strcat(path,"\\*.*");
  if (FindFirstFile(&de,path,&err)){ 
    do{ strcpy(ptr,de.file_name);  
        dir_size += de.file_size;
       }while(FindNextFile(&de,&err));
  }FindClose(&de,&err);
return dir_size;
}

int SizeDir(char *dir)
{ unsigned int err;
  WSHDR *ws=AllocWS(64);
  char path[256];
  strcpy(path,dir); 
  char *ptr=path+strlen(path)+1;
  strcat(path,"\\*.*");
  if (FindFirstFile(&de,path,&err))
  { do{
        strcpy(ptr,de.file_name);  
        if(de.file_attr && FA_DIRECTORY) dir_size+=FindSizeInSubDir(path);
        else dir_size += de.file_size;
      }while(FindNextFile(&de,&err));
  }FindClose(&de,&err);
return dir_size;
}
//=============================================================================
void DrawFreeMamory(char *path,int y)
{    int x_p=15,y_p=15;
     WSHDR *ws=AllocWS(256);
     void *canvasdata=BuildCanvas();
     DrawCanvas(canvasdata,0,0,132,176,1);
     int total_0 = GetTotalFlexSpace(0, err)/1024;
     int free_0 = GetFreeFlexSpace(0, err)/1024;
     int per_0 = (free_0*100)/total_0;
     int app=SizeDir(path);
    
     wsprintf(ws, "��������� ������:\n��������: %d kb\n��������: %d kb",total_0,free_0);
  DrawString(ws,2,2,131,175,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 

  wsprintf(ws, "%d",free_0);
  DrawString(ws,10+per_0,45+y_p,131,175,6,32,white,prozr); 

  DrawRoundedFrame(2,35+y_p,102+x_p,42+y_p,0,0,0,white,prozr);//������
  DrawRoundedFrame(3,36+y_p,3+per_0+x_p,41+y_p,0,0,0,RED,RED); 
  wsprintf(ws,"Applications: %d kb",app/1024);
  DrawString(ws,2,y,131,175,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
 // FreeWS(ws);
}
//==============================================================================
int pusk_y=50;
void DrawPusk(int crd,int i)//Pusk:)
{// int k,j;  
  void *canvasdata=BuildCanvas();
  DrawCanvas(canvasdata,0,80,75,158,1);
  DrawRoundedFrame(0,80,75,158,3,5,0,white,prozr);
  WSHDR *ws=AllocWS(256);

  wsprintf(ws,per_6s,NAME[0],NAME[1],NAME[2],NAME[3],NAME[4],NAME[5]);
  DrawString(ws,2,crd,132,176,7,32,white,prozr); 
      
// if(Cross_y>=30 && Cross_y<=175 && Cross_x>=0 && Cross_x<=30) DrawPuskk=1;
 if(Cross_x>=0 && Cross_x<=60 && Cross_y>=35+pusk_y && Cross_y <=50+pusk_y)
   { wsprintf(ws,per_s,NAME[0]);
     DrawString(ws,2,35+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
   }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=50+pusk_y && Cross_y <=62+pusk_y)
   { wsprintf(ws,per_s,NAME[1]);
     DrawString(ws,2,47+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
     
   }
  else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=62+pusk_y && Cross_y <=75+pusk_y)
   { wsprintf(ws,per_s,NAME[2]);
     DrawString(ws,2,59+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
   }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=75+pusk_y && Cross_y <=87+pusk_y)
   { wsprintf(ws,per_s,NAME[3]);
     DrawString(ws,2,71+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
   }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=87+pusk_y && Cross_y <=99+pusk_y)
   { wsprintf(ws,per_s,NAME[4]);
     DrawString(ws,2,83+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
   }
  else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=99+pusk_y && Cross_y <=111+pusk_y)
   { wsprintf(ws,per_s,NAME[5]);
     DrawString(ws,2,95+pusk_y,132,176,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125));
     DrawPuskk=1;
   }

 else DrawPuskk=0;
// DrawCross(Cross_x,Cross_y,RED,crd[0].typecur);
// GBS_StartTimerProc(&timer,1,DrawPusk);
FreeWS(ws);
}

void StartFilePusk()//������ ������ ���� ���� :)
{ if(Cross_x>=0 && Cross_x<=60 && Cross_y>=35+pusk_y && Cross_y <=50+pusk_y)
   { start("0:\\zbin\\mc\\mc.elf");//GBS_DelTimer(&timer);
    }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=50+pusk_y && Cross_y <=62+pusk_y)
   { start("0:\\zbin\\utilities\\CfgEdit.elf");//GBS_DelTimer(&timer);
    }
  else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=62+pusk_y && Cross_y <=75+pusk_y)
   { shortcut("ORGZ_CALENDERMV");//GBS_DelTimer(&timer);
    }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=75+pusk_y && Cross_y <=87+pusk_y)
   { shortcut("ELSE_DEVELP_MNU");//GBS_DelTimer(&timer);
    }
 else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=87+pusk_y && Cross_y <=99+pusk_y)
   { start("0:\\zbin\\naticq\\naticq.elf");//GBS_DelTimer(&timer);
    }
  else  if(Cross_x>=0 && Cross_x<=60 && Cross_y>=99+pusk_y && Cross_y <=111+pusk_y)
   { shortcut("FLSH_FLEXPLORER");//GBS_DelTimer(&timer);
    }
}
//==============================================================================
void DrawStrInt(int s,int x, int y)//��� �������...
{//     int len=strlen(s);
      WSHDR *ws = AllocWS(5); 
      wsprintf(ws, per_d,s);
      DrawString(ws,x,y,128,172,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
      FreeWS(ws);
}
void DrawStrChar(char *s,int x, int y)
{     int len=strlen(s);
      WSHDR *ws = AllocWS(len); 
      wsprintf(ws, per_s,s);
      DrawString(ws,x,y,128,172,7,32,GetPaletteAdrByColorIndex(124),GetPaletteAdrByColorIndex(125)); 
      FreeWS(ws);
}

//==============================================================================
/*void DrawInfo()
{
   DrawRoundedFrame(2,35,102,42+y_p,0,0,0,white,prozr);//������
   DrawNetAdv (crd[NetAdv].x, crd[NetAdv].y);
   DrawNetDb ( crd[NetDB].x, crd[NetDB].y);
   DrawDialogs (crd[Dialogs].x, crd[Dialogs].y);
   DrawFreeRam(100,5); 


}*/

