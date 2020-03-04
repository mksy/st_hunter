#ifndef _MAIN_H_
  #define _MAIN_H_

// ����� ������� ������ MAIN.C
void SendAnswer(int dummy, TPKT *p);
void CreateEditChat(CLIST *t);
void set_my_status(void);
void set_my_xstatus(void);
void set_my_xstatus2(void);

void RequestXText(unsigned int uin);

void ReadDefSettings(void);
void WriteDefSettings(void);
extern int connect_state;

int GetIconIndex(CLIST *t);


void FreeLOGQ(LOGQ **pp);

void Get_Online_total();
void DrwImage(IMGHDR *img, int x, int y, char *pen, char *brush);

typedef struct
{
  CLIST *ed_contact;
  GUI *ed_chatgui;
  int ed_answer;
  int requested_decrement_total_unread;
  int loaded_templates;
}EDCHAT_STRUCT;

#pragma pack(push)
#pragma pack(1)
typedef struct{
  unsigned char
  vibra_status:1,
  sound_status:1,
  off_contacts,
  show_groups;
  char def_status;
  char def_xstatus;
#ifdef ELKA
  unsigned char sli_state:1;
#endif
  unsigned char smartcpu_state;
  unsigned char inc_state:1;
  unsigned char ilu_state:1;
  unsigned char remind_state;
  unsigned char ping_state;
  unsigned char uptime_state;
#ifdef NEWSGOLD
  unsigned char Id3tag_status;
#endif
  unsigned char isXTX;//show x-status or online/offline time
}DEF_SETTINGS;
#pragma pack(pop)

#pragma pack(push)
#pragma pack(1)
typedef struct{
  unsigned char
  vibra_status:1,
  sound_status:1,
  off_contacts,
  show_groups;
#ifdef ELKA
  unsigned char sli_state:1;
#endif
  unsigned char smartcpu_state;
  unsigned char inc_state:1;
  unsigned char ilu_state:1;
  unsigned char remind_state;
  unsigned char ping_state;
  unsigned char uptime_state;
#ifdef NEWSGOLD
  unsigned char Id3tag_status;
#endif
  unsigned char isXTX;//show x-status or online/offline time
}DEF_SETTINGS2;
#pragma pack(pop)

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

extern unsigned long  strtoul (const char *nptr,char **endptr,int base);


//void patch_header(HEADER_DESC* head);
//void patch_input(INPUTDIA_DESC* inp);


#define PL_ALL_CAN_SEE 0
#define PL_NOBODY_CAN_SEE 1
#define PL_VISLIST_CAN_SEE 2
#define PL_INVISLIST_CANNOT_SEE 3
#define PL_CONTACTLIST_CAN_SEE 4


// ��������� �������� (�������������� � �������� �����)
#define T_REQLOGIN 1
#define T_SENDMSG 2
#define T_RECVMSG 3
#define T_LOGIN 4
#define T_ERROR 6
#define T_CLENTRY 7
#define T_STATUSCHANGE 9
#define T_AUTHREQ 10
#define T_REQINFOSHORT 11
#define T_ADDCONTACT 12
#define T_SSLRESP 13
#define T_AUTHGRANT 14
#define T_MY_STATUS_CH 15   // ��������� ����� �������
//������ (���) ������� ���������
#define T_SRV_ACK 16
//������ ������� ���������
#define T_CLIENT_ACK 17

#define T_ECHO 18
#define T_ECHORET 19

#define T_GROUPID 20
#define T_GROUPFOLLOW 21

#define T_MY_XSTATUS_CH 22

//��� ����� ���������� (������������� ��������)
#define T_MSGACK 23

#define T_XTEXT_REQ 24
#define T_XTEXT_ACK 25
#define T_XTEXT_SET 26

#define T_ADDCONTACT_WITH_GRP 27

#define T_ADDGROUP 28
#define T_ADDIGNORE 29
#define T_SETPRIVACY 30
#define T_LASTPRIVACY 31

#define T_SETCLIENT_ID 32


#endif
