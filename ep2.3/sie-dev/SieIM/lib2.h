#ifndef _LIB2_H_
  #define _LIB2_H_

#include "stdarg.h"
#include "lib.h"

////////////////////////////////////////////////////////////////////////////////
//                            ������� �� ���� lib                             //
//           ������������ ��������� ��������� �� ����������!!                 //
//                             ���� if (LoadLib)                              //
////////////////////////////////////////////////////////////////////////////////
//  API Lib's
extern   void (*WriteStr)(char * msg, char * fn);
extern   int  (*strcmp_nocase2)(const char *s, const char *d);
extern   char *(*MakeGlobalString2)(const char *first, int breakchar, const char *last);
extern   void (*reverse)(char s[]);
extern   int (*InitLgp)(char *lang, void *lng);	// ���� ���� ���������
extern   int (*InitLgp_2)(char *lang, void **array);	// ���� ���� ������
extern   int (*CreateLgp)(char *lang,  int build, int type, int count, int size, char *cright, void *lng);	// ���� ���������
extern   int (*CreateLgp_2)(char *lang,  int build, int type, int count, int size, char *cright, void **array);	// ���� ������
extern   int (*GetLgpInfo)(char *lang, LANGH *head);	// ��������� ���������� � ����� */
extern   char *(*GetDateTimeNow)(void);
extern   void (*WriteDebug)(char * msg);
extern   void (*WriteDebugSf)(char * msg, ...);
extern   int  (*DumpAdr)(const void *source,int cnt);
extern   void (*WriteStr)(char * msg, char * fn); 
extern   void (*vsprintf2)(char *text, const char *msg, va_list param);
extern   char *(*IntToStr)(int i);
extern   void (*itoa)(int n, char s[]);
extern   int (*atoi)(char *attr);
extern   void (*RestartGPRS)(void);
extern   int (*GetSesInfo)(int Now, int Max, int Sr);
extern   int (*GetSessionTraffic)(int blur);
extern   int (*GetAllTraffic)(int blur);
extern   char *(*GetCharTraffic)(int Traffic, int MB, int Text);
extern   char *(*GetCharMoney)(int Traffic, int valute);
extern   char *(*GetSessionTime)(int Secunde, const char *Format);
extern   int (*CheckLimit)(void);
extern   void (*ShowMessage)(const char *Message);
// API Plugin Protocol
extern  int API_reconnect(void);  // ���������������  +
extern  int API_connect(void);  // �����������  +
extern  int API_disconnect(void); // ���������� +
extern  int API_ping(void); // ���� +
extern  int API_set_normal_status(int Id, char *Msg, int Prioritet);  // ���������� ���������� ������ +
extern  int API_set_extended_status(int Id, char *Msg, char *Msg2); // ���������� ����������� ������  +
extern  int API_set_private_status(int Id); // ���������� ��������� ������  +
extern  int API_SendMSG(char *id, char *msg); // ��������� ���������  +
extern  int API_get_normal_status(char * id); // �������� ���������� ������
extern  int API_get_extended_status(char * id); // �������� ����������� ������
extern  int API_get_short_info(char * id);  // �������� �������� ���������� +
extern  int API_get_extra_info(char * id);  // �������� �������������� ���������� -
extern  int API_addcontact2list(char * id, char * nickname, char * group);  // �������� ������� � ������  +
//  API GUI
extern  void (*connected)(void); // - ��� ��������� ��������� �������
extern  int (*addcontact)(char * id, char * nikename); // - ���������� ��������
extern  int (*movecontact)(char * id, char * group); // 	- ����������� � ������
extern  int (*removecontact)(char * id); //  - �������� ��������
extern  int (*changestatus)(char * id,int status); //  - ��������� ������� ��������
extern  int (*recvmsg)(char * id,char * msg); //  - ��������� �� ��������
extern  int (*srvask)(char * id); //  - ��������� ����� �� �������
extern  int (*clientask)(char * id); //  - ��������� ����� �� ��������
extern  int (*changenormalstatus)(char * id,int status, char * text); //  - ��������� �������� ������� ��������
extern  int (*changesextendedstatus)(char * id,int status, char *Msg, char *Msg2); //  - ��������� ��������������� ������� ��������
extern  int (*privatestatus)(int status); //  - ��������� ���������� �������

#endif
