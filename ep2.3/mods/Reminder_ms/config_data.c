#include "..\inc\cfg_items.h"
#include "..\inc\swilib.h"


__root const CFG_HDR cfghdr0={CFG_CBOX,"������������ �����",0,3};
__root const int align=0;
__root const CFG_CBOX_ITEM cfgcbox1[3]={"Left","Center","Right"};

__root const CFG_HDR cfghdr1={CFG_UINT,"�����",0,65535};
__root const int font=FONT_SMALL;

__root const CFG_HDR cfghdr2={CFG_UINT,"���������� ����� �������",0,65535};
__root const int space=1;

__root const CFG_HDR cfghdr3={CFG_COLOR,"����",0,0};
__root const char col[4]={255,255,255,100};

__root const CFG_HDR cfghdr4={CFG_COORDINATES,"����������",0,0};
__root const unsigned int X=0;
__root const unsigned int Y=170;

__root const CFG_HDR cfghdr5={CFG_UINT,"�����",0,12};
__root const int cfgMonth=10;

__root const CFG_HDR cfghdr6={CFG_UINT,"����",0,31};
__root const int cfgDay=3;

__root const CFG_HDR cfghdr7={CFG_STR_WIN1251,"����� ��",0,127};
__root const char TEXT_BEFORE[128]="�������� ";
  
__root const CFG_HDR cfghdr8={CFG_STR_WIN1251,"�����",0,127};
__root const char TEXT_AFTER[128]=" ����";
