#ifndef _LIB_H_
  #define _LIB_H_

#include "stdarg.h"
//#include "lang.h"

#define TMR_SECOND (1300/6)
#define LIBCOUNT 6

// ID �������� SieIM
////////////////////////////////////////////////////////////////////////////////
// ���� �������� �� ������������ �����-������ ������, �� ������ ���� �� ������� � �������������, �.�.
// ������� ���������� ������� ������ ������� 0 (�.�. ��� �����)
////////////////////////////////////////////////////////////////////////////////
// ������� �������
#define OFFLINE 0 // �� � ����
#define INVISIBLE 1 // �������
#define AWAY 2  // ������
#define NA 3  // ����������
#define OCCUPIED 4  // ������������
#define DND 5 // �����
#define DEPRESSION 6  // ��������
#define EVIL 7  // ����
#define HOME 8  // ����
#define LUNCH 9 // �����
#define WORK 10 // �� ������ 
#define ONLINE 11 // � ����
#define FFC 12  // ����� �������
// ��������� �������
#define ALL_CAN_SEE 0  // ����� ��� ����
#define NOBODY_CAN_SEE 1 // ����� ��� ����, ����� ������ ���������
#define VISLIST_CAN_SEE 2  // ����� ������ ��� "�������"
#define INVISLIST_CANNOT_SEE 3 // ������� ��� ����
#define CONTACTLIST_CAN_SEE 4  // ����� ������ ��� ��
// ���� ���������
#define TYPE_ICQ 100  // ���� ��� ������ icq
#define TYPE_JABBER 101 // ���� ��� ������ jabber
#define TYPE_RSS 102  // ���� ��� ������ RSS
#define TYPE_MISC 500  // ������ ��������
#define TYPE_NONE 501 // ������ ������ (��� ���� �������� � �.�. ������ ��)

////////////////////////////////////////////////////////////////////////////////
//                                 loadlib.c                                  //
////////////////////////////////////////////////////////////////////////////////

extern int LoadLib; // ��������� �� ����������?
extern void loadlib_str();  // �������� ���������� str
extern void loadlib_date();  // �������� ���������� date
extern void loadlib_dbg();  // �������� ���������� dbg
extern void loadlib_type();  // �������� ���������� type
extern void loadlib_gprs();  // �������� ���������� gprs
extern void loadlib_mesg();  // �������� ���������� mesg
extern int closelib();  // �������� ���������
extern int loadlib();  // �������� ���������
extern void set_libs (); //��������� ����� ��� ���������
////////////////////////////////////////////////////////////////////////////////
//                   ���������� ���������� ��� ���� lib                       //
////////////////////////////////////////////////////////////////////////////////
extern void kill_data(void *p, void (*func_p)(void *));
extern const int LibID;

////////////////////////////////////////////////////////////////////////////////
//                          ��������� ��� ���� lib                            //
////////////////////////////////////////////////////////////////////////////////

extern int *Debug;
extern char *Path;
extern int *trafic_size;
extern int *trafic_gold;
extern int *trafic_silver;
extern int *trafic_blur;
extern char *text_valute;
extern int *LIMIT_TRAF_ACTIVE;
extern int *LIMIT_TRAF_KB;
extern int *LIMIT_TRAF_SEC;  
extern int *session_time_enable;
extern int *TypeMes;


////////////////////////////////////////////////////////////////////////////////
// ��������� �����
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	int build;	// ������ ��������� ������
	int type;	// ��� ����� (���, ���� � �.�.)
	int count;	// ���������� �������
	int size;	// ������ �����, ���� ��������� �� ��������� � �����������..
	char cright[64];	// �����(�) ������/��������
} LANGH;

/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� STR  ID = 0
                                                                              */
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   void (*WriteStr)(char * msg, char * fn);
   int  (*strcmp_nocase)(const char *s, const char *d);
   char *(*MakeGlobalString)(const char *first, int breakchar, const char *last);
   void (*reverse)(char s[]);
   void (*vsprintf2)(char *text, const char *msg, va_list param);
   int (*InitLgp)(char *lang, void *lng);	// ���� ���� ���������
   int (*InitLgp_2)(char *lang, void **array);	// ���� ���� ������
   int (*CreateLgp)(char *lang,  int build, int type, int count, int size, char *cright, void *lng);	// ���� ���������
   int (*CreateLgp_2)(char *lang,  int build, int type, int count, int size, char *cright, void **array);	// ���� ������
   int (*GetLgpInfo)(char *lang, LANGH *head);	// ��������� ���������� � �����
   void (*CloseLib)();
   int LibID;
}STRExecStruct;

typedef struct
{
   STRExecStruct  *Struct;
}STRParamStruct;

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� DATE ID = 1
                                                                              */
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   char *(*GetDateTimeNow)(void);
   void (*CloseLib)();
   int LibID;
}DATEExecStruct;

typedef struct
{
   DATEExecStruct  *Struct;
}DATEParamStruct;

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� DBG  ID = 2
                                                                              */
////////////////////////////////////////////////////////////////////////////////
typedef struct
{
   void (*WriteDebug)(char * msg);
   void (*WriteDebugSf)(char * msg, ...);
   int  (*DumpAdr)(const void *source,int cnt);
   void (*CloseLib)();
   int LibID;
}DBGExecStruct;

typedef struct
{
   int Debug;
   char  *Path;
   char *(*GetDateTimeNow)(void);
   void (*WriteStr)(char * msg, char * fn);  
   void (*vsprintf2)(char *text, const char *msg, va_list param);
   DBGExecStruct  *Struct;
}DBGParamStruct;

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� TYPE ID = 3
                                                                              */
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   char *(*IntToStr)(int i);
   void (*itoa)(int n, char s[]);
   int (*atoi)(char *attr);
   void (*CloseLib)();
   int LibID;
}TYPEExecStruct;

typedef struct
{
   void (*reverse)(char s[]);
   TYPEExecStruct *Struct;
}TYPEParamStruct;

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� GPRS ID = 4
                                                                              */
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   void (*RestartGPRS)(void);
   int (*GetSesInfo)(int Now, int Max, int Sr);
   int (*GetSessionTraffic)(int blur);
   int (*GetAllTraffic)(int blur);
   char *(*GetCharTraffic)(int Traffic, int MB, int Text);
   char *(*GetCharMoney)(int Traffic, int valute);
   char *(*GetSessionTime)(int Secunde, const char *Format);
   int (*CheckLimit)(void);
   void (*CloseLib)();
   int LibID;
}GPRSExecStruct;

typedef struct
{
   int trafic_size;
   int trafic_gold;
   int trafic_silver;
   int trafic_blur;
   char *text_valute;
   int LIMIT_TRAF_ACTIVE;
   int LIMIT_TRAF_KB;
   int LIMIT_TRAF_SEC;  
   int session_time_enable;
   GPRSExecStruct *Struct;
}GPRSParamStruct;

////////////////////////////////////////////////////////////////////////////////
/*
��������� ���������� MSG  ID = 5
                                                                              */
////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   void (*ShowMessage)(const char *Message);
   void (*CloseLib)();
   int LibID;
}MESGExecStruct;

typedef struct
{
   int TypeMes;
   MESGExecStruct *Struct;
}MESGParamStruct;

////////////////////////////////////////////////////////////////////////////////

typedef struct
{
   int (*loadlib)();
   int (*closelib)();
   int *LoadLib;
   STRExecStruct     *STREStruct ;
   DATEExecStruct    *DATEEStruct;
   DBGExecStruct     *DBGEStruct ;
   TYPEExecStruct    *TYPEEStruct;
   GPRSExecStruct    *GPRSEStruct;
   MESGExecStruct    *MESGEStruct;
}LMExecStruct;

typedef struct
{
   int Debug; // �������� �� �������
   char *Path;  // ���� � ����� ����
   int trafic_size; // ������ �������� �������� �� �������
   int trafic_gold; // ���� �������� (������)
   int trafic_silver; //  ���� �������� (������)
   int trafic_blur; // ��������� ������� �� ...
   char *text_valute; // ������������ ������
   int LIMIT_TRAF_ACTIVE; // �������� �� ����������� �� ��������
   int LIMIT_TRAF_KB; // ����������� �������� � ��
   int LIMIT_TRAF_SEC;   // ����������� �������� � ���
   int session_time_enable; // ������� �� ����� ������
   int TypeMes; // ��� ���������
   LMExecStruct *Struct;
}LMParamStruct;

////////////////////////////////////////////////////////////////////////////////

typedef struct
{
  int type; // ��� ������
  int status[20]; // ������ �������������� ��������. ������ �������������, ����� 1, ��� - 0, ���� ������ ������� ��� ������ = -i
  int privat[5];  // ������ �������������� ��������� ��������...
  int countx; // ���������� �������������� ��������
  int (*reconnect)(void);  // ���������������
  int (*connect)(void);  // �����������
  int (*disconnect)(void); // ����������
  int (*ping)(void); // ����
  int (*set_normal_status)(int Id, char *Msg, int Prioritet);  // ���������� ���������� ������
  int (*set_extended_status)(int Id, char *Msg, char *Msg2); // ���������� ����������� ������
  int (*set_private_status)(int Id); // ���������� ��������� ������
  int (*SendMSG)(char *id, char *msg); // ��������� ���������
  int (*get_normal_status)(char * id); // �������� ���������� ������
  int (*get_extended_status)(char * id); // �������� ����������� ������
  int (*get_short_info)(char * id);  // �������� �������� ����������
  int (*get_extra_info)(char * id);  // �������� �������������� ����������
  int (*addcontact2list)(char * id, char * nickname, char * group);  // �������� ������� � ������
} ProtocolEStruct;

typedef struct
{
  char ID[128]; // ������������� ������������
  char PASS[128]; // ������ ������������
  char ClientName[30];   // ��� �������
  unsigned int ClienID; // ������������� �������
  unsigned int AutoGPRS;  // �������������� ���� (�� ���!?)
  STRExecStruct     *STREStruct ; //
  DATEExecStruct    *DATEEStruct; //
  DBGExecStruct     *DBGEStruct ; //  <===  ��������� � ���������
  TYPEExecStruct    *TYPEEStruct; //  <===  �� ���
  GPRSExecStruct    *GPRSEStruct; //
  MESGExecStruct    *MESGEStruct; //
  void (*connected)(void); // - ��� ��������� ��������� �������
  int (*addcontact)(char * id, char * nikename); // - ���������� ��������
  int (*movecontact)(char * id, char * group); // 	- ����������� � ������
  int (*removecontact)(char * id); //  - �������� ��������
  int (*changestatus)(char * id,int status); //  - ��������� ������� ��������
  int (*recvmsg)(char * id,char * msg); //  - ��������� �� ��������
  int (*srvask)(char * id); //  - ��������� ����� �� �������
  int (*clientask)(char * id); //  - ��������� ����� �� ��������
  int (*changenormalstatus)(char * id,int status, char * text); //  - ��������� �������� ������� ��������
  int (*changesextendedstatus)(char * id,int status, char *Msg, char *Msg2); //  - ��������� ��������������� ������� ��������
  int (*privatestatus)(int status); //  - ��������� ���������� �������
  ProtocolEStruct *Struct;  // ��������� �� ���������
} ProtocolPStruct;



////////////////////////////////////////////////////////////////////////////////

extern STRExecStruct     STREStruct ;
extern STRParamStruct    STRPStruct ;
extern DATEExecStruct    DATEEStruct;
extern DATEParamStruct   DATEPStruct;
extern DBGExecStruct     DBGEStruct ;
extern DBGParamStruct    DBGPStruct ;
extern TYPEExecStruct    TYPEEStruct;
extern TYPEParamStruct   TYPEPStruct;
extern GPRSExecStruct    GPRSEStruct;
extern GPRSParamStruct   GPRSPStruct;
extern MESGExecStruct    MESGEStruct;
extern MESGParamStruct   MESGPStruct;

#endif
