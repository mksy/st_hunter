#include "..\inc\cfg_items.h"
#include "..\inc\swilib.h"

#ifdef NEWSGOLD
#define DEFAULT_DISK "4"
#else
#define DEFAULT_DISK "0"
#endif

__root const CFG_HDR cfghdr0={CFG_CHECKBOX,"�������� iGPRS",0,0};
__root const int ENABLE_MAN = 1;

__root const CFG_HDR cfghdr0_0={CFG_CHECKBOX,"NSD ����� ������",0,0};
__root const int ENABLE_NSD = 1;

__root const CFG_HDR cfghdr1={CFG_LEVEL,"��������� �������",1,0};

__root const CFG_HDR cfghdr1_1={CFG_CHECKBOX,"���������� ����� �����������",0,0};
__root const int START_MES = 1;

__root const CFG_HDR cfghdr1_2={CFG_CHECKBOX,"�������� ���� ��� �������",0,0};
__root const int START_SOUND = 0;

__root const CFG_HDR cfghdr1_3={CFG_UINT,"����� �����",0,65535};
__root const int NUMBER_SOUNG = 0;

__root const CFG_HDR cfghdr1_4={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr2={CFG_LEVEL,"��������� �����������",1,0};

__root const CFG_HDR cfghdr2_1={CFG_CHECKBOX,"�������. ��� ���������� ��������",0,0};
__root const int NOTIFY_UPDATED = 1;

__root const CFG_HDR cfghdr2_2={CFG_CHECKBOX,"�������� ����������� �����������",0,0};
__root const int NOTIFY_EX = 1;

__root const CFG_HDR cfghdr2_3={CFG_LEVEL,"��������� ��������. �����������",1,0};

__root const CFG_HDR cfghdr2_3_1={CFG_TIME,"�������� ����������� �����",0,0};
__root const TTime TimeFrom={8,0};

__root const CFG_HDR cfghdr2_3_2={CFG_TIME,"��������� ����������� �����",0,0};
__root const TTime TimeTo={22,0};

__root const CFG_HDR cfghdr2_3_3={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_4={CFG_LEVEL,"����������� ��� �����������",1,0};

__root const CFG_HDR cfghdr2_4_1={CFG_CHECKBOX,"�������� ����� �����������",0,0};
__root const int NOTIFY_ON_MESSAGE = 0;

__root const CFG_HDR cfghdr2_4_2={CFG_STR_WIN1251,"����� �����������",0,63};
__root const char MESSAGE_ON_TEXT[64]="GPRS ������ ������!";

__root const CFG_HDR cfghdr2_4_3={CFG_CHECKBOX,"����������� ���������",0,0};
__root const int NOTIFY_ON_VIBRA = 1;

__root const CFG_HDR cfghdr2_4_4={CFG_UINT,"�������� ��������",0,63535};
__root const int Vibra_ON_Power = 10;

__root const CFG_HDR cfghdr2_4_5={CFG_CHECKBOX,"���������� ������",0,0};
__root const int NOTIFY_ON_SOUND = 0;

__root const CFG_HDR cfghdr2_4_6={CFG_UINT,"����� �����",0,65535};
__root const int NUMBER_ON_SOUND = 0;

__root const CFG_HDR cfghdr2_4_7={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_5={CFG_LEVEL,"����������� ��� ����������",1,0};

__root const CFG_HDR cfghdr2_5_1={CFG_CHECKBOX,"�������� ����� �����������",0,0};
__root const int NOTIFY_OFF_MESSAGE = 0;

__root const CFG_HDR cfghdr2_5_2={CFG_STR_WIN1251,"����� �����������",0,63};
__root const char MESSAGE_OFF_TEXT[64]="GPRS ������ ���������!";

__root const CFG_HDR cfghdr2_5_3={CFG_CHECKBOX,"����������� ���������",0,0};
__root const int NOTIFY_OFF_VIBRA = 1;

__root const CFG_HDR cfghdr2_5_4={CFG_UINT,"�������� ��������",0,63535};
__root const int Vibra_OFF_Power = 10;

__root const CFG_HDR cfghdr2_5_5={CFG_CHECKBOX,"���������� ������",0,0};
__root const int NOTIFY_OFF_SOUND = 0;

__root const CFG_HDR cfghdr2_5_6={CFG_UINT,"����� �����",0,65535};
__root const int NUMBER_OFF_SOUND = 0;

__root const CFG_HDR cfghdr2_5_7={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_6={CFG_LEVEL,"�������������� �����������",1,0};

__root const CFG_HDR cfghdr2_6_1={CFG_CHECKBOX,"�������� ���������. �����������",0,0};
__root const int NOTIFY_AUTO = 0;

__root const CFG_HDR cfghdr2_6_2={CFG_UINT,"���������� ����� (������)",0,63535};
__root const int NOTIFY_INT = 300;

__root const CFG_HDR cfghdr2_6_3={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_6_4={CFG_LEVEL,"����������� � �����. ������",1,0};

__root const CFG_HDR cfghdr2_6_4_1={CFG_CHECKBOX,"�������� ������. � �����. ���.",0,0};
__root const int NOTIFY_SEND = 0;

__root const CFG_HDR cfghdr2_6_4_2={CFG_LEVEL,"��� ���������� ������",1,0};

__root const CFG_HDR cfghdr2_6_4_2_1={CFG_CHECKBOX,"���������� ��������",0,0};
__root const int NOTIFY_SEND_NORM_DISP = 1;

__root const CFG_HDR cfghdr2_6_4_2_2={CFG_CHECKBOX,"���������� �����������",0,0};
__root const int NOTIFY_SEND_NORM_KEY = 0;

__root const CFG_HDR cfghdr2_6_4_2_3={CFG_UINT,"������� ���������",0,63535};
__root const int NOTIFY_SEND_NORM_ILL = 100;

__root const CFG_HDR cfghd2_6_4_2_4={CFG_UINT,"����� �����. 1/10 ���",0,63535};
__root const int NOTIFY_SEND_NORM_FADE = 10;

__root const CFG_HDR cfghd2_6_4_2_5={CFG_UINT,"������� ��������� 1/10 ���",0,63535};
__root const int NOTIFY_SEND_NORM_TIMEOUT = 1;

__root const CFG_HDR cfghdr2_6_4_2_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_6_4_3={CFG_LEVEL,"��� ������. �����",1,0};

__root const CFG_HDR cfghdr2_6_4_3_1={CFG_CHECKBOX,"���������� ��������",0,0};
__root const int NOTIFY_SEND_LOCK_DISP = 1;

__root const CFG_HDR cfghdr2_6_4_3_2={CFG_CHECKBOX,"���������� �����������",0,0};
__root const int NOTIFY_SEND_LOCK_KEY = 0;

__root const CFG_HDR cfghdr2_6_4_3_3={CFG_UINT,"������� ���������",0,63535};
__root const int NOTIFY_SEND_LOCK_ILL = 100;

__root const CFG_HDR cfghd2_6_4_3_4={CFG_UINT,"����� �����. 1/10 ���",0,63535};
__root const int NOTIFY_SEND_LOCK_FADE = 10;

__root const CFG_HDR cfghd2_6_4_3_5={CFG_UINT,"������� ��������� 1/10 ���",0,63535};
__root const int NOTIFY_SEND_LOCK_TIMEOUT = 1;

__root const CFG_HDR cfghdr2_6_4_3_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_6_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr2_7={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

/*__root const CFG_HDR cfghdr3={CFG_LEVEL,"��������� Ping",1,0};

__root const CFG_HDR cfghdr3_1={CFG_CHECKBOX,"�������������� ping",0,0};
__root const int PING_ENABLE = 0;

__root const CFG_HDR cfghdr3_2={CFG_UINT,"�������� �������� (������)",0,63535};
__root const int PING_TIME = 60;

__root const CFG_HDR cfghdr3_3={CFG_CHECKBOX,"���������� � ������� ping",0,0};
__root const int NOTIFY_PING = 0;

__root const CFG_HDR cfghdr3_4={CFG_STR_WIN1251,"����� �����������",0,63};
__root const char PING_MESSAGE[64]="Ping %d ������";

__root const CFG_HDR cfghdr3_5={CFG_UTF8_STRING,"����",0,63};
__root const char HOST_NAME[64]="www.google.com";

__root const CFG_HDR cfghdr3_6={CFG_UINT,"����",0,63535};
__root const int HOST_PORT = 80;

__root const CFG_HDR cfghdr3_7={CFG_CHECKBOX,"��������� ���������� GPRS",0,0};
__root const int GPRS_RESTART = 0;

__root const CFG_HDR cfghdr3_8={CFG_UINT,"���� ping ����������� (������)",0,65535};
__root const int GPRS_AWAY = 60;

__root const CFG_HDR cfghdr3_9={CFG_UINT,"���� ping ������ (������)",0,65535};
__root const int GPRS_LONG = 30;

__root const CFG_HDR cfghdr3_10={CFG_CHECKBOX,"���������� IP ����� � ����",0,0};
__root const int WRITE_IP = 0;

__root const CFG_HDR cfghdr3_11={CFG_STR_UTF8,"���� � �����",0,63};
__root const char WRITE_FILEPATH[64]=DEFAULT_DISK":\\ZBin\\Var\\iGPRS.log";

__root const CFG_HDR cfghdr3_12={CFG_LEVEL,"",0,0};*/

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr4={CFG_LEVEL,"��������� ������",1,0};

__root const CFG_HDR cfghdr4_1={CFG_CHECKBOX,"��������� ��������� �������",0,0};
__root const int reg_enable = 0;

__root const CFG_HDR cfghdr4_11={CFG_CHECKBOX,"���������� � ���-�� ����. ������",0,0};
__root const int reg_file = 0;

__root const CFG_HDR cfghdr4_2={CFG_LEVEL,"��� �������� GPRS ����������",1,0};

__root const CFG_HDR cfghdr4_2_1={CFG_CHECKBOX,"��������� ��������� ������",0,0};
__root const int reg_create_enable = 0;

__root const CFG_HDR cfghdr4_2_2={CFG_STR_UTF8,"��������� ���� �1",0,63};
__root const char reg_create_file_1[64] = "";

__root const CFG_HDR cfghdr4_2_3={CFG_STR_UTF8,"��������� ���� �2",0,63};
__root const char reg_create_file_2[64] = "";

__root const CFG_HDR cfghdr4_2_4={CFG_STR_UTF8,"��������� ���� �3",0,63};
__root const char reg_create_file_3[64] = "";

__root const CFG_HDR cfghdr4_2_5={CFG_STR_UTF8,"��������� ���� �4",0,63};
__root const char reg_create_file_4[64] = "";

__root const CFG_HDR cfghdr4_2_6={CFG_STR_UTF8,"��������� ���� �5",0,63};
__root const char reg_create_file_5[64] = "";

__root const CFG_HDR cfghdr4_2_7={CFG_STR_UTF8,"��������� ���� �6",0,63};
__root const char reg_create_file_6[64] = "";

__root const CFG_HDR cfghdr4_2_8={CFG_STR_UTF8,"��������� ���� �7",0,63};
__root const char reg_create_file_7[64] = "";

__root const CFG_HDR cfghdr4_2_9={CFG_STR_UTF8,"��������� ���� �8",0,63};
__root const char reg_create_file_8[64] = "";

__root const CFG_HDR cfghdr4_2_10={CFG_STR_UTF8,"��������� ���� �9",0,63};
__root const char reg_create_file_9[64] = "";

__root const CFG_HDR cfghdr4_2_11={CFG_STR_UTF8,"��������� ���� �10",0,63};
__root const char reg_create_file_10[64] = "";

__root const CFG_HDR cfghdr4_2_12={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr4_3={CFG_LEVEL,"��� ������� GPRS ����������",1,0};

__root const CFG_HDR cfghdr4_3_1={CFG_CHECKBOX,"��������� ��������� ������",0,0};
__root const int regulation_close_enable = 0;

__root const CFG_HDR cfghdr4_3_2={CFG_STR_UTF8,"��������� ���� �1",0,63};
__root const char regulation_close_file_1[64] = "";

__root const CFG_HDR cfghdr4_3_3={CFG_STR_UTF8,"��������� ���� �2",0,63};
__root const char regulation_close_file_2[64] = "";

__root const CFG_HDR cfghdr4_3_4={CFG_STR_UTF8,"��������� ���� �3",0,63};
__root const char regulation_close_file_3[64] = "";

__root const CFG_HDR cfghdr4_3_5={CFG_STR_UTF8,"��������� ���� �4",0,63};
__root const char regulation_close_file_4[64] = "";

__root const CFG_HDR cfghdr4_3_6={CFG_STR_UTF8,"��������� ���� �5",0,63};
__root const char regulation_close_file_5[64] = "";

__root const CFG_HDR cfghdr4_3_7={CFG_STR_UTF8,"��������� ���� �6",0,63};
__root const char regulation_close_file_6[64] = "";

__root const CFG_HDR cfghdr4_3_8={CFG_STR_UTF8,"��������� ���� �7",0,63};
__root const char regulation_close_file_7[64] = "";

__root const CFG_HDR cfghdr4_3_9={CFG_STR_UTF8,"��������� ���� �8",0,63};
__root const char regulation_close_file_8[64] = "";

__root const CFG_HDR cfghdr4_3_10={CFG_STR_UTF8,"��������� ���� �9",0,63};
__root const char regulation_close_file_9[64] = "";

__root const CFG_HDR cfghdr4_3_11={CFG_STR_UTF8,"��������� ���� �10",0,63};
__root const char regulation_close_file_10[64] = "";

__root const CFG_HDR cfghdr4_3_12={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr4_4={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr5={CFG_LEVEL,"�������� ������� GPRS",1,0};

__root const CFG_HDR cfghdr5_1={CFG_CHECKBOX,"������������� �������� ������",0,0};
__root const int interception_enable = 0;

__root const CFG_HDR cfghdr5_2={CFG_UINT,"������ ������ ������ � ������",0,65535};
__root const int interception_buffer = 1024;

__root const CFG_HDR cfghdr5_3={CFG_STR_UTF8,"���� ��� �������� �������",0,63};
__root const char interception_FILEPATH[64]=DEFAULT_DISK":\\ZBin\\Var\\Interception\\%d.log";

__root const CFG_HDR cfghdr5_4={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr6={CFG_LEVEL,"����� GPRS ������",1,0};

__root const CFG_HDR cfghdr6_1={CFG_CHECKBOX,"����������� �����",0,0};
__root const int session_time_enable = 1;

__root const CFG_HDR cfghdr6_2={CFG_LEVEL,"����������� �� Idle",1,0};

__root const CFG_HDR cfghdr6_2_1 = {CFG_CHECKBOX, "���������� ����� ������", 0, 0};
__root const int IDLE_SES_ENABLE = 0;

__root const CFG_HDR cfghdr6_2_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_SES_ACTIVE = 1;

__root const CFG_HDR cfghdr6_2_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_SES_LOCK = 1;

__root const CFG_HDR cfghdr6_2_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_SES_MES[64]="����� GPRS: %d:%02d:%02d";

__root const CFG_HDR cfghdr6_2_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_SES_X=3;
__root const unsigned int IDLE_SES_Y=131;

__root const CFG_HDR cfghdr6_2_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_SES_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr6_2_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_SES_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr6_2_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_SES_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr6_2_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_SES_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr6_2_10={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr6_3={CFG_CHECKBOX,"���������� � ����� ������",0,0};
__root const int session_time_show = 0;

__root const CFG_HDR cfghdr6_4={CFG_STR_WIN1251,"����� ���������",0,63};
__root const char session_time_message[64]="����� ������: %d:%02d:%02d";

__root const CFG_HDR cfghdr6_5={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr7={CFG_LEVEL,"������ � ���������",1,0};

__root const CFG_HDR cfghdr7_2={CFG_LEVEL,"��������� �����������",1,0};

__root const CFG_HDR cfghdr7_2_1 = {CFG_UINT, "������ ������� � ��", 0, 65535};
__root const int trafic_size = 1024;

__root const CFG_HDR cfghdr7_2_2 = {CFG_UINT, "��������� ������� (1/1)", 0, 65535};
__root const int trafic_gold = 5;

__root const CFG_HDR cfghdr7_2_3 = {CFG_UINT, "��������� ������� (1/100)", 0, 99};
__root const int trafic_silver = 0;

/*__root const CFG_HDR cfghdr7_2_4 = {CFG_UINT, "��������� ������ � ��.", 0, 65535};
__root const int trafic_start = 0;*/

__root const CFG_HDR cfghdr7_2_4 = {CFG_UINT, "��������� �� ��.", 0, 65535};
__root const int trafic_blur = 0;

__root const CFG_HDR cfghdr7_2_5 = {CFG_CHECKBOX, "��������� ����� ���������", 0, 0};
__root const int trafic_all_blur = 0;

__root const CFG_HDR cfghdr7_2_6={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_21={CFG_LEVEL,"��������� ������",1,0};

__root const CFG_HDR cfghdr7_21_1={CFG_STR_WIN1251,"������������ ������",0,63};
__root const char text_valute[64]="���";

__root const CFG_HDR cfghdr7_21_2={CFG_STR_WIN1251,"������������ ��",0,63};
__root const char text_mb[64]="��";

__root const CFG_HDR cfghdr7_21_3={CFG_STR_WIN1251,"������������ ��",0,63};
__root const char text_kb[64]="��";

__root const CFG_HDR cfghdr7_21_4={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_22={CFG_LEVEL,"����������� �������",1,0};

__root const CFG_HDR cfghdr7_22_1 = {CFG_CHECKBOX, "�������� ����������� �������", 0, 0};
__root const int LIMIT_TRAF_ACTIVE = 0;

__root const CFG_HDR cfghdr7_22_2={CFG_LEVEL,"��������� �����������",1,0};

__root const CFG_HDR cfghdr7_22_2_1={CFG_UINT,"������ ������� (� ��.)",0,65535};
__root const unsigned int LIMIT_TRAF_KB=0;

__root const CFG_HDR cfghdr7_22_2_2={CFG_UINT,"����� ������ (� ���.)",0,65535};
__root const unsigned int LIMIT_TRAF_SEC=0;

__root const CFG_HDR cfghdr7_22_2_3={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_22_3={CFG_LEVEL,"��������� ��������",1,0};

__root const CFG_HDR cfghdr7_21_3_01 = {CFG_CHECKBOX, "��������� GPRS", 0, 0};
__root const int LIMIT_TRAF_OFF = 1;

__root const CFG_HDR cfghdr7_21_3_1 = {CFG_CHECKBOX, "��������� ����", 0, 0};
__root const int LIMIT_TRAF_PLAY = 0;

__root const CFG_HDR cfghdr7_21_3_2 = {CFG_UINT,"����� �����",0,65535};
__root const unsigned int LIMIT_TRAF_NUM=0;

__root const CFG_HDR cfghdr7_21_3_3 = {CFG_CHECKBOX, "�����������", 0, 0};
__root const int LIMIT_TRAF_VIBRA = 1;

__root const CFG_HDR cfghdr7_21_3_4 = {CFG_UINT,"��������",0,65535};
__root const unsigned int LIMIT_TRAF_POWER=10;

__root const CFG_HDR cfghdr7_21_3_5 = {CFG_CHECKBOX, "�������� ���������", 0, 0};
__root const int LIMIT_TRAF_MES = 1;

__root const CFG_HDR cfghdr7_21_3_6 = {CFG_STR_WIN1251,"����� ���������",0,63};
__root const char LIMIT_TRAF_TEXT[64]="����� ��������!";

__root const CFG_HDR cfghdr7_21_3_7={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_22_4={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_3={CFG_LEVEL,"����������� ��������� �� Idle",1,0};

__root const CFG_HDR cfghdr7_3_1 = {CFG_CHECKBOX, "���������� ��������� �� ������", 0, 0};
__root const int IDLE_TRAF_SES_ENABLE = 0;

__root const CFG_HDR cfghdr7_3_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_TRAF_SES_ACTIVE = 1;

__root const CFG_HDR cfghdr7_3_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_TRAF_SES_LOCK = 1;

__root const CFG_HDR cfghdr7_3_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_TRAF_SES_MES[64]="������: %s";

__root const CFG_HDR cfghdr7_3_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_TRAF_SES_X=3;
__root const unsigned int IDLE_TRAF_SES_Y=111;

__root const CFG_HDR cfghdr7_3_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_TRAF_SES_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr7_3_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_TRAF_SES_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr7_3_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_TRAF_SES_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr7_3_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_TRAF_SES_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr7_3_10={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_4={CFG_LEVEL,"�����. ����� ��������� �� Idle",1,0};

__root const CFG_HDR cfghdr7_4_1 = {CFG_CHECKBOX, "���������� ����� ���������", 0, 0};
__root const int IDLE_ALL_TRAF_ENABLE = 0;

__root const CFG_HDR cfghdr7_4_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_ALL_TRAF_ACTIVE = 1;

__root const CFG_HDR cfghdr7_4_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_ALL_TRAF_LOCK = 1;

__root const CFG_HDR cfghdr7_4_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_ALL_TRAF_MES[64]="�����: %s";

__root const CFG_HDR cfghdr7_4_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_ALL_TRAF_X=3;
__root const unsigned int IDLE_ALL_TRAF_Y=91;

__root const CFG_HDR cfghdr7_4_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_ALL_TRAF_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr7_4_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_ALL_TRAF_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr7_4_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_ALL_TRAF_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr7_4_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_ALL_TRAF_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr7_4_10={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr7_5={CFG_LEVEL,"�����. ������� �� ������ �� Idle",1,0};

__root const CFG_HDR cfghdr7_5_1 = {CFG_CHECKBOX, "���������� ������ �� ������", 0, 0};
__root const int IDLE_TRAF_ENABLE = 0;

__root const CFG_HDR cfghdr7_5_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_TRAF_ACTIVE = 1;

__root const CFG_HDR cfghdr7_5_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_TRAF_LOCK = 1;

__root const CFG_HDR cfghdr7_5_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_TRAF_MES[64]="������: %s";

__root const CFG_HDR cfghdr7_5_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_TRAF_X=3;
__root const unsigned int IDLE_TRAF_Y=71;

__root const CFG_HDR cfghdr7_5_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_TRAF_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr7_5_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_TRAF_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr7_5_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_TRAF_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr7_5_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_TRAF_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr7_5_10={CFG_LEVEL,"",0,0};


__root const CFG_HDR cfghdr8_5={CFG_LEVEL,"�����. ������ ������� �� Idle",1,0};

__root const CFG_HDR cfghdr8_5_1 = {CFG_CHECKBOX, "���������� ����� ������", 0, 0};
__root const int IDLE_TRAF_ALL_ENABLE = 0;

__root const CFG_HDR cfghdr8_5_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_TRAF_ALL_ACTIVE = 1;

__root const CFG_HDR cfghdr8_5_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_TRAF_ALL_LOCK = 1;

__root const CFG_HDR cfghdr8_5_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_TRAF_ALL_MES[64]="�����: %s";

__root const CFG_HDR cfghdr8_5_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_TRAF_ALL_X=3;
__root const unsigned int IDLE_TRAF_ALL_Y=51;

__root const CFG_HDR cfghdr8_5_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_TRAF_ALL_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr8_5_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_TRAF_ALL_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr8_5_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_TRAF_ALL_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr8_5_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_TRAF_ALL_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr8_5_10={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr8_6={CFG_LEVEL,"",0,0};

////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr9={CFG_LEVEL,"����������",1,0};

__root const CFG_HDR cfghdr9_1 = {CFG_CHECKBOX, "����� ����������", 0, 0};
__root const int STAT_ENABLE = 0;

__root const CFG_HDR cfghdr9_2={CFG_LEVEL,"��������� ����������",1,0};

__root const CFG_HDR cfghdr9_2_1 = {CFG_CHECKBOX, "���������� ����� ������ ������", 0, 0};
__root const int STAT_START_TIME = 1;

__root const CFG_HDR cfghdr9_2_2 = {CFG_CHECKBOX, "���������� ����� ����� ������", 0, 0};
__root const int START_END_TIME = 1;

__root const CFG_HDR cfghdr9_2_3 = {CFG_CHECKBOX, "���������� ������ ������", 0, 0};
__root const int STAT_TRAF = 1;

__root const CFG_HDR cfghdr9_2_31 = {CFG_CHECKBOX, "���������� ������. ������ ������", 0, 0};
__root const int STAT_BLUR_TRAF = 1;

__root const CFG_HDR cfghdr9_2_4 = {CFG_CHECKBOX, "���������� ��������� ������", 0, 0};
__root const int STAT_MONEY = 1;

__root const CFG_HDR cfghdr9_2_5 = {CFG_CHECKBOX, "���������� ����� ������", 0, 0};
__root const int STAT_TIME = 1;

__root const CFG_HDR cfghdr9_3={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr9_4={CFG_STR_UTF8,"���� � ���� ����������",0,63};
__root const char STAT_FILEPATH[64]=DEFAULT_DISK":\\ZBin\\Var\\GPRS.log";

__root const CFG_HDR cfghdr9_5={CFG_LEVEL,"",0,0};


////////////////////////////////////////////////////////////////////////////////

__root const CFG_HDR cfghdr10={CFG_LEVEL,"������",1,0};

__root const CFG_HDR cfghdr10_1={CFG_LEVEL,"����� �� Idle",1,0};

__root const CFG_HDR cfghdr10_1_1 = {CFG_CHECKBOX, "���������� �����", 0, 0};
__root const int IDLE_TIME_ENABLE = 0;

__root const CFG_HDR cfghdr10_1_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int IDLE_TIME_ACTIVE = 1;

__root const CFG_HDR cfghdr10_1_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int IDLE_TIME_LOCK = 1;

__root const CFG_HDR cfghdr10_1_4={CFG_STR_WIN1251,"������ �����������",0,63};
__root const char IDLE_TIME_MES[64]="�����: %d:%02d:%02d";

__root const CFG_HDR cfghdr10_1_5={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int IDLE_TIME_X=3;
__root const unsigned int IDLE_TIME_Y=20;

__root const CFG_HDR cfghdr10_1_6={CFG_COLOR,"���� ������",0,0};
__root const char IDLE_TIME_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr10_1_7={CFG_UINT,"�����",0,65535};
__root const unsigned int IDLE_TIME_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr10_1_8 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int IDLE_TIME_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr10_1_9={CFG_COLOR,"���� ��������",0,0};
__root const char IDLE_TIME_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr10_1_10={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_2={CFG_LEVEL,"�������� ����������",1,0};

__root const CFG_HDR cfghdr10_2_1 = {CFG_CHECKBOX, "�������� �������� ����������", 0, 0};
__root const int SEE_STAT_ENABLE = 0;

__root const CFG_HDR cfghdr10_2_2 = {CFG_CHECKBOX, "������ ��� �������� ������", 0, 0};
__root const int SEE_STAT_ACTIVE = 0;

__root const CFG_HDR cfghdr10_2_3 = {CFG_CHECKBOX, "������ ��� �������. �����", 0, 0};
__root const int SEE_STAT_LOCK = 1;

__root const CFG_HDR cfghdr10_2_4={CFG_CBOX,"����� ������� ������",0,3};
__root const int SEE_MODE_KBD=2;
__root const CFG_CBOX_ITEM cfgcbox1[3]={"KEY_DOWN","KEY_UP","LONG_PRESS"};

__root const CFG_HDR cfghdr10_2_5={CFG_UINT,"������� ������",0,100};
__root const unsigned int SEE_STAT_BTN=GREEN_BUTTON;

__root const CFG_HDR cfghdr10_2_6={CFG_STR_UTF8,"���� � ����� � ���������",0,63};
__root const char SEE_FOLDER[64]=DEFAULT_DISK":\\Zbin\\img\\iGPRS\\";

__root const CFG_HDR cfghdr10_2_7={CFG_LEVEL,"��������� ������",1,0};

__root const CFG_HDR cfghdr10_2_7_1={CFG_COLOR,"���� ������",0,0};
__root const char SES_COLORS[4]={255,255,255,100};

__root const CFG_HDR cfghdr10_2_7_2={CFG_UINT,"�����",0,65535};
__root const unsigned int SES_FONT=FONT_SMALL;

__root const CFG_HDR cfghdr10_2_7_3 = {CFG_CHECKBOX, "�������� ��������", 0, 0};
__root const int SES_FRINGING_ENABLE = 1;

__root const CFG_HDR cfghdr10_2_7_4={CFG_COLOR,"���� ��������",0,0};
__root const char SES_FRINGING_COLORS[4]={0,0,0,100};

__root const CFG_HDR cfghdr10_2_7_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_2_71={CFG_LEVEL,"����������� �������",1,0};

__root const CFG_HDR cfghdr10_2_71_1 = {CFG_CHECKBOX, "�������� ����������� �������", 0, 0};
__root const int ses_ex_key_en = 0;

__root const CFG_HDR cfghdr10_2_71_2={CFG_UINT,"������� ���������� GPRS",0,100};
__root const unsigned int ses_ex_key_off=RED_BUTTON;

__root const CFG_HDR cfghdr10_2_71_3={CFG_UINT,"������� ��������� GPRS",0,100};
__root const unsigned int ses_ex_key_on=GREEN_BUTTON;

__root const CFG_HDR cfghdr10_2_71_4={CFG_UINT,"������� ������������ GPRS",0,100};
__root const unsigned int ses_ex_key_res=ENTER_BUTTON;

__root const CFG_HDR cfghdr10_2_71_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_2_811={CFG_STR_WIN1251,"����� ��������� (GPRS ����.)",0,63};
__root const char SES_GPRS_ON[64]="GPRS ��������";

__root const CFG_HDR cfghdr10_2_812={CFG_STR_WIN1251,"����� ��������� (GPRS �� ����.)",0,63};
__root const char SES_GPRS_OFF[64]="GPRS �� ��������";

__root const CFG_HDR cfghdr10_2_81={CFG_STR_WIN1251,"����� ��������� (����� ������)",0,63};
__root const char SES_IT[64]="����� ������: %d:%02d:%02d";

__root const CFG_HDR cfghdr10_2_8={CFG_STR_WIN1251,"����� ��������� (�����. �����)",0,63};
__root const char SES_SR[64]="����. �����: %d:%02d:%02d";

__root const CFG_HDR cfghdr10_2_9={CFG_STR_WIN1251,"����� ��������� (����. �����)",0,63};
__root const char SES_MAX[64]="����. �����: %d:%02d:%02d";

__root const CFG_HDR cfghdr10_2_10={CFG_STR_WIN1251,"����� ��������� (���-�� �����.)",0,63};
__root const char SES_NUM[64]="���-�� �����: %d";

__root const CFG_HDR cfghdr10_2_11={CFG_STR_WIN1251,"����� ����� (���� ������)",0,63};
__root const char SES_ALL[64]="�����";

__root const CFG_HDR cfghdr10_2_12={CFG_STR_WIN1251,"����� ������ (�� ������)",0,63};
__root const char SES_SES[64]="������";

/*__root const CFG_HDR cfghdr10_2_13={CFG_STR_WIN1251,"������ ���������",0,63};
__root const char SES_FORM_ST[64]="%s �.";

__root const CFG_HDR cfghdr10_2_14={CFG_STR_WIN1251,"������ ������� (�� ������)",0,63};
__root const char SES_FORM_KB[64]="%s ��";

__root const CFG_HDR cfghdr10_2_15={CFG_STR_WIN1251,"������ ������� (�����)",0,63};
__root const char SES_FORM_MB[64]="%s ��";*/

__root const CFG_HDR cfghdr10_2_17={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_3={CFG_LEVEL,"PNG �����",1,0};

__root const CFG_HDR cfghdr10_3_1 = {CFG_CHECKBOX, "PNG ����� �� IDLE", 0, 0};
__root const int png_on_idle = 0;

__root const CFG_HDR cfghdr10_3_11 = {CFG_CHECKBOX, "PNG ����� �� ����", 0, 0};
__root const int png_on_gui = 0;

__root const CFG_HDR cfghdr10_3_2 = {CFG_CHECKBOX, "������ PNG �����", 0, 0};
__root const int png_full = 1;

__root const CFG_HDR cfghdr10_3_3={CFG_STR_UTF8,"���� � ����� ������",0,63};
__root const char PNG_FOLDER[64]=DEFAULT_DISK":\\Zbin\\img\\calibri\\";

__root const CFG_HDR cfghdr10_3_4={CFG_UINT,"���������� ����� �������",0,63};
__root const int PNG_LEN=0;

__root const CFG_HDR cfghdr10_3_5={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_4={CFG_LEVEL,"������ ������ �� IDLE",1,0};

__root const CFG_HDR cfghdr10_4_1 = {CFG_CHECKBOX, "���������� ������ �� IDLE", 0, 0};
__root const int icon_on_idle = 0;

__root const CFG_HDR cfghdr10_4_2={CFG_COORDINATES,"��������� �� Idle",0,0};
__root const unsigned int icon_on_idle_X=0;
__root const unsigned int icon_on_idle_Y=0;

__root const CFG_HDR cfghdr10_4_3={CFG_LEVEL,"",0,0};

__root const CFG_HDR cfghdr10_41={CFG_UINT,"����� ���������� 1/10 ���",0,63535};
__root const int UPDATE_TIME = 10;

__root const CFG_HDR cfghdr10_412={CFG_UINT,"�������� ShowMSG",0,10};
__root const int ShowMSG_Param = 1;

__root const CFG_HDR cfghdr10_5 = {CFG_CHECKBOX, "�������� ����� �� IDLE", 0, 0};
__root const int canvas_on_idle = 1;

__root const CFG_HDR cfghdr10_6 = {CFG_CHECKBOX, "�������� GPRS ��� �������", 0, 0};
__root const int gprs_start = 1;

__root const CFG_HDR cfghdr10_7 = {CFG_CHECKBOX, "��������� GPRS ��� ��������", 0, 0};
__root const int gprs_end = 1;

__root const CFG_HDR cfghdr10_8 = {CFG_CHECKBOX, "LowCPUClock �� IDLE � ����", 0, 0};
__root const int cpu_low = 0;

/*__root const CFG_HDR cfghdr10_2_7_2={CFG_UINT,"�������� ���������� ������ (1/10 ���)",0,65535};
__root const unsigned int UPD_TIME=10;*/

/*__root const CFG_HDR cfghdr10_4 = {CFG_CHECKBOX, "������ ������� ����. �� IDLE", 0, 0};
__root const int low_on_idle = 0;*/

__root const CFG_HDR cfghdr10_9={CFG_LEVEL,"",0,0};


