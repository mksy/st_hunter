#ifndef _ITEMS_H_
  #define _ITEMS_H_


enum TypeItem {GROUP, // ������
               BUDDY  // �������
              };

enum TypeHist {
                IN_MESS, // ��������
                OUT_MESS, // ���������
                STATUS,   // ��������� Status
                XSTATUS,   // ��������� XStatus
                AUTREQ,// Authorization request message
	        AUTDEN,// Authorization denied message
	        AUTGIV,// Authorization given message
	        YOUADD// "You-were-added" message
              };

typedef struct
{
  void *next;
  TDate date;
  TTime time;
  int type;
  char *text;
}HIST;

typedef struct
{
  void *next;
  void *prev;
  unsigned int ID;            // ID �������� , ��� ������ = 0
  unsigned int GroupID;       // ID ������ , ��� �������� - � ����� ������
  unsigned int UIN;
  unsigned short Type;
  char Nick[64];
  unsigned short Status;
  char *StatusText;
  unsigned short XStatus;
  char* XStatusText;
  unsigned short isunread;  // ���� �������������
  unsigned short istyping; // �������� ���������  //0x0000 - typing finished
                                                  //0x0001 - text typed
                                                  //0x0002 - typing begun
  unsigned short iscollapsed;
  unsigned short visible;
  unsigned short enable_typing;
  unsigned short client_id;
  
  HIST *history;
  
}ITEM;


extern ITEM *Itemtop;

ITEM *AddItem(unsigned int ID,  unsigned int GroupID, unsigned int UIN, unsigned short Type,  char* Nick);
void DeleteItem(int curitem);

ITEM *GetItem(int curitem);
ITEM *GetItemByID(int ID); // ���������� ������� �� ID
ITEM *GetGroupByGroupID(int GroupID); // ������ �� GroupID
ITEM *GetItemByUIN(int UIN); // ������� �� ��� UIN(�����)
ITEM *GetItemByUINstr(char *UIN); // ������� �� ��� Uin ������
ITEM *GetItemByName(char *name); // �� �����



void GroupCollapsed(int GroupID); // �������� ���������� ������
void GroupVisible(int visible); // ������ ������
void OfflineVisible(int visible); // ������ �������� �� � ����
int CountVisibleItem(); // ���������� ������� ������


int GetContactInGroup(int GroupID);
int TotalItems();
int TotalContact();
int TotalGroup();

//// history
void AddHistory(ITEM* item, TDate date, TTime time, int type, char * text);
void DelHistory(ITEM* item);





//// file CL
void LoadCL(char *pathfile);
void SaveCL(char *pathfile);



void FreeItemsList();

#endif
