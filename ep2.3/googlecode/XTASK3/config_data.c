#include "..\inc\cfg_items.h"
//������������
__root const CFG_HDR cfghdr0={CFG_STR_UTF8,"CSM list�ļ�·��",3,127};
#ifdef NEWSGOLD
__root const char csmlist_fname[128]="4:\\ZBin\\etc\\CSMlist.txt";
#else 
__root const char csmlist_fname[128]="0:\\ZBin\\etc\\CSMlist.txt";
#endif

__root const CFG_HDR cfghdr1={CFG_CHECKBOX,"������ӭ��Ϣ",0,2};
__root const int ENA_HELLO_MSG=1;
//__root const CFG_CBOX_ITEM cfgcbox1[2]={"No","Yes"};

__root const CFG_HDR cfghdr25={CFG_STR_GB,"UnderIdleCSM_DESC",0,8};
__root const char UNDER_IDLE_CONSTR[9]="";

#ifndef NEWSGOLD
__root const CFG_HDR cfghdr23={CFG_CBOX,"����ģʽ",0,4};
__root const int ACTIVE_KEY_STYLE=0;
__root const CFG_CBOX_ITEM cfgcbox23[4]={"�̰�","����","* + #","�м�"};

__root const CFG_HDR cfghdr24={CFG_UINT,"�����ȼ�",0,99};
__root const int ACTIVE_KEY=99;
#else
__root const CFG_HDR cfghdr23={CFG_CBOX,"����ģʽ",0,2};
__root const int ACTIVE_KEY_STYLE=0;
__root const CFG_CBOX_ITEM cfgcbox23[2]={"�̰�","����"};

#ifdef ELKA
__root const CFG_HDR cfghdr24={CFG_UINT,"�����ȼ�",0,99};
__root const int ACTIVE_KEY=0x15;
#else
__root const CFG_HDR cfghdr24={CFG_UINT,"�����ȼ�",0,99};
__root const int ACTIVE_KEY=0x11;
#endif
#endif

//__root const CFG_HDR cfghdr2={CFG_CBOX,"����: ����ʱ",0,5};
//__root const int ENA_LONG_PRESS=2;
//__root const CFG_CBOX_ITEM cfgcbox2[5]={"����ϵͳԭ��","�����κ���","���������̨����","�������б�","�����������������̨"};

#ifdef NEWSGOLD
__root const CFG_HDR cfghdr3={CFG_CBOX,"���ģʽ",0,3};
__root const int RED_BUT_MODE=2;
__root const CFG_CBOX_ITEM cfgcbox3[3]={"����ϵͳԭ��","����ģʽ","���������̨����"};
#endif

__root const CFG_HDR cfghdr22={CFG_CHECKBOX,"����������ʱʹ��",0,2};
__root const int ENA_LOCK=1;
//__root const CFG_CBOX_ITEM cfgcbox22[2]={"No","Yes"};

__root const CFG_HDR cfghdr33={CFG_CHECKBOX,"��ʾNewStyleDaemons",0,2};
__root const int SHOW_DAEMONS=1;
//__root const CFG_CBOX_ITEM cfgcbox33[2]={"No","Yes"};

__root const CFG_HDR cfghdr4={CFG_STR_GB,"��������1����",1,31};
__root const char BM1NAME[32]="";
__root const CFG_HDR cfghdr5={CFG_STR_UTF8,"��������1�ļ�·��",3,127};
__root const char BM1FILE[128]="";

__root const CFG_HDR cfghdr6={CFG_STR_GB,"��������2����",1,31};
__root const char BM2NAME[32]="";
__root const CFG_HDR cfghdr7={CFG_STR_UTF8,"��������2�ļ�·��",3,127};
__root const char BM2FILE[128]="";

__root const CFG_HDR cfghdr8={CFG_STR_GB,"��������3����",1,31};
__root const char BM3NAME[32]="";
__root const CFG_HDR cfghdr9={CFG_STR_UTF8,"��������3�ļ�·��",3,127};
__root const char BM3FILE[128]="";

__root const CFG_HDR cfghdr10={CFG_STR_GB,"��������4����",1,31};
__root const char BM4NAME[32]="";
__root const CFG_HDR cfghdr11={CFG_STR_UTF8,"��������4�ļ�·��",3,127};
__root const char BM4FILE[128]="";

__root const CFG_HDR cfghdr12={CFG_STR_GB,"��������5����",1,31};
__root const char BM5NAME[32]="";
__root const CFG_HDR cfghdr13={CFG_STR_UTF8,"��������5�ļ�·��",3,127};
__root const char BM5FILE[128]="";

__root const CFG_HDR cfghdr14={CFG_STR_GB,"��������6����",1,31};
__root const char BM6NAME[32]="";
__root const CFG_HDR cfghdr15={CFG_STR_UTF8,"��������6�ļ�·��",3,127};
__root const char BM6FILE[128]="";

__root const CFG_HDR cfghdr16={CFG_STR_GB,"��������7����",1,31};
__root const char BM7NAME[32]="";
__root const CFG_HDR cfghdr17={CFG_STR_UTF8,"��������7�ļ�·��",3,127};
__root const char BM7FILE[128]="";

__root const CFG_HDR cfghdr18={CFG_STR_GB,"��������8����",1,31};
__root const char BM8NAME[32]="";
__root const CFG_HDR cfghdr19={CFG_STR_UTF8,"��������8�ļ�·��",3,127};
__root const char BM8FILE[128]="";

__root const CFG_HDR cfghdr20={CFG_STR_GB,"��������9����",1,31};
__root const char BM9NAME[32]="";
__root const CFG_HDR cfghdr21={CFG_STR_UTF8,"��������9�ļ�·��",3,127};
__root const char BM9FILE[128]="";
