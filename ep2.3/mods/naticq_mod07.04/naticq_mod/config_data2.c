#include "..\inc\cfg_items.h"
#include "language.h"
//������������

#ifdef NEWSGOLD
#define DEFAULT_DISK "4"
#else
#define DEFAULT_DISK "0"
#endif

//-----------------------------------------------------------------------------//
//                                ��������� ������
//-----------------------------------------------------------------------------//

#ifdef BCFG
__root const CFG_HDR cfghdr0={CFG_LEVEL,"",0,0};

//View settings
__root const CFG_HDR cfghdr23_4={CFG_LEVEL,"��������� ������",1,0};

//Long press right in chat
  __root const CFG_HDR cfghdr4_67={CFG_CBOX,"������� ������� ������ � ����",0,3};
  __root const int LongRightAction = 0;
  __root const CFG_CBOX_ITEM cfgcbox4_56[3]={"������","��������� ���","�������� �����"};    

//Long press right in chat
  __root const CFG_HDR cfghdr34_64={CFG_CBOX,"������� ������� ����� � ����",0,2};
  __root const int LongLeftAction = 0;
  __root const CFG_CBOX_ITEM cfgcbox444_56[2]={"������","���������� ���"};
  
  //Action on # button in contact list
    __root const CFG_HDR cfghdr78_4520={CFG_CBOX,"�������� �� # � ��",0,2};
    __root const int ActionResh = 0;
    __root const CFG_CBOX_ITEM cfgcbox_668_z[2]={"�������� ���������� ���","����.���.���"};
    
#ifdef ELKA
//Press vol up or vol down button in CL
  __root const CFG_HDR cfghdr34_642={CFG_CBOX,"���. �������� �� �����.����",0,2};
  __root const int isVolDownButton = 1;
  __root const CFG_CBOX_ITEM cfgcbox434_56[2]={"���","��"};
  
  __root const CFG_HDR cfghdr34_6342={CFG_CBOX,"���.�������� �� �����.�����",0,2};
  __root const int isVolUpButton = 1;
  __root const CFG_CBOX_ITEM cfgcbox4134_56[2]={"���","��"};
#endif
__root const CFG_HDR cfghdr223_5={CFG_LEVEL,"",0,0}; //�������� ������
	
	
//-----------------------------------------------------------------------------//
//------------------------------- STATUS SETTING ------------------------------//
//-----------------------------------------------------------------------------//
  
__root const CFG_HDR cfghdr_45={CFG_LEVEL,"��������� ��������",1,0};

//Status icon on mainscreen position
#ifdef ELKA
#ifdef kluchnik
    __root const CFG_HDR cfghdr467_1 = {CFG_CBOX,"���������� ������ �������",0,5};
    __root const int ShowStatusIcon = 1;
    __root const CFG_CBOX_ITEM cfgcbox9_1[5]={"�� ������� ������","� ��������","� ��������(����� ��)","�����","�����"};
#else
    __root const CFG_HDR cfghdr467_1 = {CFG_CBOX,"���������� ������ �������",0,5};
    __root const int ShowStatusIcon = 0;
    __root const CFG_CBOX_ITEM cfgcbox9_1[5]={"�� ������� ������","� ��������","� ��������(����� ��)","�����","�����"};
#endif
#endif
        
//Show x-status on iconbar or mainscreen
#ifdef kluchnik
    __root const CFG_HDR cfghdrz_68 = {CFG_CBOX,"�����.������� ������",0,4};
    __root const int show_xstatus = 2;
    __root const CFG_CBOX_ITEM cfgcbox_8z[4]={"�����","�� ��","� ��������","�����"};
#else
#ifdef ELKA
    __root const CFG_HDR cfghdrz_68 = {CFG_CBOX,"�����.������� ������",0,4};
    __root const int show_xstatus = 1;
    __root const CFG_CBOX_ITEM cfgcbox_8z[4]={"�����","�� ��","� ��������","�����"};
#else
    __root const CFG_HDR cfghdrz_68 = {CFG_CBOX,"�����.������� ������",0,2};
    __root const int show_xstatus = 1;
    __root const CFG_CBOX_ITEM cfgcbox_8z[2]={"�����","�� ��"};
#endif
#endif    
    __root const CFG_HDR cfghdrz_1={CFG_COORDINATES,"������� ������� �� ��",0,0};
    __root const unsigned int IDLEICON_XX=2;
    __root const unsigned int IDLEICON_YX=70;
    
#ifdef ELKA
//Number first pic status in folder img for show in iconbar
    __root const CFG_HDR cfghdr19_22={CFG_UINT,"1� ������� ������� � ��������",0,65535};
    __root const unsigned int NumStatusToIconBar = 8000;  

//Number first pic x-status in folder img for show in iconbar    
    __root const CFG_HDR cfghdr19_242={CFG_UINT,"1� ������� �������� � ��������",0,65535};
    __root const unsigned int NumXStatusToIconBar = 8100;  
#endif
__root const CFG_HDR cfghdr_4={CFG_LEVEL,"",0,0};//STATUS SETTINGS
  
  
//-----------------------------------------------------------------------------//
//-------------------------------- PNGFONT SETTING ----------------------------//
//-----------------------------------------------------------------------------//
  
  
__root const CFG_HDR cfghdr1_45={CFG_LEVEL,"��������� ���������",1,0};
   
//Nember png-font or system
   __root const CFG_HDR cfghdr65z={CFG_UINT,"����� ������ (1=png/1xx=system)",0,115};
   __root const unsigned int fonto=1;
    
//Path to png-font
#ifdef kluchnik
   __root const CFG_HDR cfghdr98={CFG_STR_UTF8,"���� � ������",0,63};
   __root const char fontpath[64]="4:\\elf\\naticq\\font\\";
#else
   __root const CFG_HDR cfghdr98={CFG_STR_UTF8,"���� � ������",0,63};
   __root const char fontpath[64]="";
#endif
//Coordinates for message on idle
   __root const CFG_HDR cfghd83 = {CFG_COORDINATES,"������� �� ��",0,0};
   __root const unsigned int msg_d_x = 0;
   __root const unsigned int msg_d_y = 65;   
   
  __root const CFG_HDR cfghdr60_2={CFG_COLOR,"���� ������",0,0};
  __root const char fontColor[4]={0xFF,0xFF,0xFF,100};
  
  __root const CFG_HDR cfghdr60_3={CFG_COLOR,"���� ����",0,0};
  __root const char bgrColor[4]={0x00,0x00,0x00,100};

//Max show symbol on idle
   __root const CFG_HDR cfghdr19a_1={CFG_UINT,"���������� ��������",0,50};
   __root const unsigned int main_lenght = 24;
      
   __root const CFG_HDR cfghdr9z9={CFG_CBOX,"������������ .. � ������ ",0,2};
   __root const int use_cutter = 1;
   __root const CFG_CBOX_ITEM cfgcbox18a_4[2]={"No","Yes"};

   __root const CFG_HDR cfghdr65y={CFG_UINT,"���������� ����� �������",0,999999};
   __root const unsigned int spaco1=1;
      
   //__root const CFG_HDR cfghdr65u={CFG_UINT,"Main msg space",0,999999};
   //__root const unsigned int spaco2=0;
    
__root const CFG_HDR cfghdrss_45={CFG_LEVEL,"",0,0};//PNGFONT SETTING
  

 //-----------------------------------------------------------------------------//
//                                 ONLINE TIME
//-----------------------------------------------------------------------------//


__root const CFG_HDR cfghdr_m71={CFG_LEVEL,"����� ������",1,0};

    __root const CFG_HDR cfghdr699 = {CFG_COORDINATES,"������� �������",0,0};
    __root const unsigned int onlineTime_x = 77;
    __root const unsigned int onlineTime_y = 98;

    __root const CFG_HDR cfghdr698 = {CFG_CBOX,"����� ��� �����������",0,2};
    __root const int Pause_Time = 1;
    __root const CFG_CBOX_ITEM cfgcbox85[2]={"No","Yes"};

__root const CFG_HDR cfghdr_m70={CFG_LEVEL,"",0,0};


//-----------------------------------------------------------------------------//
//                              AUTO PING/UNREAD
//-----------------------------------------------------------------------------//


__root const CFG_HDR cfghdr_m91={CFG_LEVEL,"��������/�������������",1,0};

    __root const CFG_HDR cfghd66 = {CFG_COORDINATES,"���������� ���������",0,0};
    __root const unsigned int Ping_X = 2;
    __root const unsigned int Ping_Y = 262;
    
    __root const CFG_HDR cfghdr1z9a_1={CFG_UINT,"���� ����� �����(times)",0,50};
    __root const unsigned int ping_time_config = 29;
    
    __root const CFG_HDR cfghdr298 = {CFG_CBOX,"���������� �������������",0,2};
    __root const int Is_Unread_On = 0;
    __root const CFG_CBOX_ITEM cfgcbox86[2]={"No","Yes"};
    
    __root const CFG_HDR cfghd67 = {CFG_COORDINATES,"���������� �������������",0,0};
    __root const unsigned int unread_X = 99;
    __root const unsigned int unread_Y = 65;

__root const CFG_HDR cfghdr_m90={CFG_LEVEL,"",0,0};



//-----------------------------------------------------------------------------//
//                                AUTO STATUS                                  //
//-----------------------------------------------------------------------------//


__root const CFG_HDR cfghdr_m61={CFG_LEVEL,"����������",1,0};

    __root const CFG_HDR cfghdr668 = {CFG_CBOX,"��������",0,2};
    __root const int Auto_Status = 1;
    __root const CFG_CBOX_ITEM cfgcbox89[2]={"No","Yes"};
    
    __root const CFG_HDR cfghdr667={CFG_UINT,"����� (1min=12)",120,500};
    __root const unsigned int AUTO_ENGADE=120;
    
    __root const CFG_HDR cfghdr_13={CFG_CBOX,"GMT ����",0,33};
    __root const int time_zone = 16;
    __root const CFG_CBOX_ITEM cfgcbox_13[33]={"-12:00", "-11:00", "-10:00", "-09:00", "-08:00", "-07:00", "-06:00", "-05:00", "-04:00", "-03:30", "-03:00", "-02:00", "-01:00", "00:00", "+01:00", "+02:00", "+03:00", "+03:30", "+04:00", "+04:30", "+05:00", "+05:30", "+05:45", "+06:00", "+06:30", "+07:00", "+08:00", "+09:00", "+09:30", "+10:00", "+11:00", "+12:00", "+13:00"};
    
    __root const CFG_HDR cfghdrzz_8={CFG_STR_WIN1251,"��������� �����������",0,23};
    __root const char awayHelloMsg[24]="������";
    
    __root const CFG_HDR cfghdrzz_9={CFG_STR_WIN1251,"��������� ����������",0,1023};
    __root const char awayMsg[1024]="� ������ �� ���� ��������!";
    
    __root const CFG_HDR cfghdr66_2 = {CFG_CBOX,"���������� ����������� �����",0,2};
    __root const int Reset_timer = 0;
    __root const CFG_CBOX_ITEM cfgcbox90[2]={"�������� ���������","������� ����� �������"};
  
//Show away time on idle
    __root const CFG_HDR cfghdr663 = {CFG_CBOX,"���������� �� ��",0,2};
    __root const int showAwayIdle = 0;
    __root const CFG_CBOX_ITEM cfgcbox82[2]={"No","Yes"};
    
    __root const CFG_HDR cfghd6_7 = {CFG_COORDINATES,"�������",0,0};
    __root const unsigned int auto_x = 0;
    __root const unsigned int auto_y = 252;
  
__root const CFG_HDR cfghdr_m60={CFG_LEVEL,"",0,0};

//------------------------------------------------------------------------------//
//                                SCREEN SAVER                                  //
//------------------------------------------------------------------------------//

__root const CFG_HDR cfghdr_91={CFG_LEVEL,"��������",1,0};

    __root const CFG_HDR cfghdr9_1 = {CFG_CBOX,"�������� ��������",0,2};
    __root const int isScreenSaverEna = 0;
    __root const CFG_CBOX_ITEM cfgcbox9_2[2]={"No","Yes"};
    
    __root const CFG_HDR cfghdr9_3={CFG_UINT,"����� �� ������������(1���=12)",0,1000};
    __root const unsigned int screenSaverTime=120;

__root const CFG_HDR cfghdr_90={CFG_LEVEL,"",0,0};

//------------------------------------------------------------------------------//
//                                EXTRA CONFIG                                  //
//------------------------------------------------------------------------------//


__root const CFG_HDR cfghdr_m51={CFG_LEVEL,"������ �����",1,0};

//Show contact header with...
#ifdef kluchnik
    __root const CFG_HDR cfghdr467 = {CFG_CBOX,"���������� � ��������� ��",0,5};
    __root const int TIME_OR_MSG = 4;
    __root const CFG_CBOX_ITEM cfgcbox91[5]={"�����","���������","��������","���","��� �����(���)"};
#else
    __root const CFG_HDR cfghdr467 = {CFG_CBOX,"���������� � ��������� ��",0,5};
    __root const int TIME_OR_MSG = 3;
    __root const CFG_CBOX_ITEM cfgcbox91[5]={"�����","���������","��������","���","��� �����(���)"};
#endif
//Vibra count in vibra remaider
    __root const CFG_HDR cfghdr65={CFG_UINT,"���-�� �������� � ���.�������.",0,10};
    __root const unsigned int Vibra_cc=2;
    
//CSM for player
    __root const CFG_HDR cfghdr66={CFG_STR_UTF8,"CSM ������",0,8};
    __root const char CsmAdr[9]="A087B454";  //el=A087B454 //es=A068E244
    
//Text before name track
    __root const CFG_HDR cfghdr67={CFG_STR_WIN1251,"����� ��� ������ �����",0,12};
    __root const char playing[13]="MediaPlayer:";
  
//Show command sending    
    __root const CFG_HDR cfghdr780={CFG_CBOX,"���������� ������ ������",0,2};
    __root const int show_send_info = 1;
    __root const CFG_CBOX_ITEM cfgcbox8_z[2]={"No","Yes"};

    //isLogStatusChange
    __root const CFG_HDR cfghdr7_80={CFG_CBOX,"�����. ����� ���.����.��������",0,2};
    __root const int isLogStatusChange = 1;
    __root const CFG_CBOX_ITEM cfgcbox8df_z[2]={"No","Yes"};
    
    /*
//Show time offline contact
    __root const CFG_HDR cfghdr7_80={CFG_CBOX,"���������� ����� ����.��������",0,2};
    __root const int isLogOffline = 1;
    __root const CFG_CBOX_ITEM cfgcbox8df_z[2]={"No","Yes"};
    
//Show time onlain contact
    __root const CFG_HDR cfghdr7_81={CFG_CBOX,"���������� ����� �����.��������",0,2};
    __root const int isLogOnline = 1;
    __root const CFG_CBOX_ITEM cfgcbox9df_z[2]={"No","Yes"};
   */
//Show Loopback contact in CL
    __root const CFG_HDR cfghdr71_30={CFG_CBOX,"���������� Loopback � ��",0,2};
    __root const int IsShowLoopback = 1;
    __root const CFG_CBOX_ITEM cfgcbox_3z[2]={"No","Yes"};
    
__root const CFG_HDR cfghdr_m50={CFG_LEVEL,"",0,0};


__root const CFG_HDR cfghdr11_9={CFG_STR_UTF8,"��������� ����� ����",0,255};
__root const char ignor_list[256]="";

#endif
