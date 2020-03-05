#define NULL    0x00000

//===============================================================================
struct DIALOG
{
 void huge *onKeyPress;
 void huge *onInit;
 void huge *onExit1;
 void huge *onExit2;
 void huge *onCreate;
 unsigned int buf_size1;
 unsigned int dummy1;
};

struct DIALOG_WSK
{
 void huge *onKeyPress;
 void huge *onCreate;
 void huge *onClose;
 unsigned int datasize; //Min 0x2C
 unsigned int tablesize;
 const unsigned int far *table;
};

typedef struct
{
 void huge *proc;
 unsigned int unk1;
 unsigned int unk2;
} PID_DESC;

typedef struct
{
 void far *unk;
 PID_DESC far *desc;
} PID;

struct MSG
{
        PID far *SenderPid;    // process which sent this MSG
        int Msg;
        int Param[6];
};

// kbd msg:
#define KEY_DOWN        0xE9
#define KEY_UP          0xEA 
#define LONG_PRESS      0xEB
// EC - sent 1 second after last key release, but not always?
// ED - ? unknown kbd msg
// EE - ? unknown kbd msg

// For kbd msg:
// P0 - scan Code:
#define LEFT_SOFT       0x01
#define RIGHT_SOFT      0x04
#define RECORD_BUTTON   0x06
#define GREEN_BUTTON    0x0B
#define RED_BUTTON      0x0C
#define VOL_UP_BUTTON   0x0D
#define VOL_DOWN_BUTTON 0x0E
#define UP_BUTTON       0x3B
#define DOWN_BUTTON     0x3C
#define LEFT_BUTTON     0x3D
#define RIGHT_BUTTON    0x3E
#define PLAY_BUTTON     0x3F
// '*', '#', '0'-'9'
// P1 - 0 or garbage
// P2 - scan code (if >80h, the key is releeased, if 7B - long press)
// P3 - 
// P4 - scan code with high byte == ??? or FF
// P5 - unknown

//====================================================================================
// Menus
//====================================================================================
extern void GeneralFunc(int Unk);
extern int DoEscape(void);

struct MENUHEADER
{
 int Unk1;
 int Unk2;
 int Unk3;
 int Unk4;
 char far* pMenuIconID;
 int header_string_ID;
 int end_of_data; // 0x7FFF
};

struct ITEMSDATA
{
 char far* pUnk1;
 int StringID1; // for big screen, 
 int StringID2; // and for normal screen 
 int Zero1;
 char far* pUnk2;
 int ItemType;
 int ItemConditionCode;
};

struct ITEMSHNDL
{
 void huge* proc;
};

struct MENUSTRUCT
{
 void huge *pUnk1; //Unk1-Unk4 - handler_info
 void huge *pUnk2;
 void huge *pUnk3;
 void huge *pUnk4;
 char far* pUnkData1; 
 char far* pUnkData2;
 int Unk1;
 int Unk2;
 void huge* MenuHandler;   //button handler?
 struct ITEMSDATA far* ItemsData;
 struct ITEMSHNDL far* ItemsHandler;
 int ItemsCount;
};

#define menu_full       0x00
#define menu_options    0x01
extern void CreateMenu02(int Style, int Zero1, int Zero2, struct MENUSTRUCT far *, struct MENUHEADER far *, char far* Zero3,  char far* Zero4, void far* procZero5, char far* Zero6);

extern void SetMenuItemIcon(char far* Unk1, int Item, int Unk2, int Unk3);
extern void RefreshMenuItem(char far* Unk1);
extern int GetCurrentMenuItem(char far* Unk1);

//--------------------------------------------------------------------------

extern void doIDLE(void);

//1 - ���� �� �������������
extern int GetKeyLockState1(void);
extern void turnLightON(void);

extern void pShowDialog(const struct DIALOG far *,char far *);

extern int CreateDialogWithSoftKeys(const struct DIALOG_WSK far *, void far *, int flag);
extern void CloseDialogWithSoftKeys(int ID);

extern int GetBotDialogWSK_ID(void);

extern void doBack0A(void);
extern void DrawString(int x,int y,int w,int h,const char far *str,int font);
extern void FillRect(int x,int y,int w,int h,int color); 
extern void OnTimer(unsigned long ms,void huge *);
extern void OnTimer1(void);
extern void OnTimer2(void);
extern void DisableTimer(void);

extern void StartTimer2(unsigned long *tmr, unsigned long step, void huge *);
extern void DisableTimerX(unsigned long *tmr);

extern int xsprintf(char far *, const char far *, ... );
extern int strlen(const char far *);
extern void strcpy(char far *d,const far char *s);

extern int strcmp(const char far *,const char far *);
extern int strncmp(const char far *,const char far *, int);

extern void memcpy(void far *d,const far void *s,int siz);
extern void memmove(void far *d,const far void *s,int siz);
extern void *memset(void far *d,int what,int siz);
extern void *memcpyW(void far *d,const void far *s,unsigned long siz);
extern int memcmp(void far *,void far *,unsigned int siz);

//====================================================================================
//������ � �����
//====================================================================================
struct _heap_
{
 void far *constr_data;
 void far *begin;
 unsigned int dummy;
 unsigned int free;
 void far *p2;
};

extern struct _heap_ *AllHeapsPointers[];

//extern void *FarMemAlloc(struct _heap_ far * _heap_pnt,unsigned int siz);
//extern void FarMemFree(struct _heap_ far * _heap_pnt,void far *mem);
struct PVARD
{
 struct _heap_ far ** pp_heap;
 unsigned int siz;
 char name[8];
};

//��������� ������ � ����
struct VAR_HEAP_HDR
{
 struct VAR_HEAP_HDR far * next;
 unsigned int siz;
 char name[8];
};

extern void *HeapMalloc(struct _heap_ far * _heap_pnt,unsigned int siz);
extern void HeapFree(struct _heap_ far * _heap_pnt,void far *mem);

extern void *EX_heap_malloc_with_lock(unsigned int siz);
extern void EX_heap_free_with_lock(void far *mem);
extern void* MMIMalloc(unsigned int sz);
extern void MMIHeapFree(void far *mem);

extern struct VARS far * GetVars(const struct PVARD far *p);
extern void FreeVars(const struct PVARD far *p);



//====================================================================================
//EEPROM
//====================================================================================
extern void WriteEEPROMData(int Block, void far *Data,unsigned int Offset, unsigned int Size, void far *PID, int Mess);
extern void ReadEEPROMData(int Block, void far *Data,unsigned int Offset, unsigned int Size, void far *PID, int Mess);

//====================================================================================
struct ImageHdr
{
 char W;
 char H;
 int Flags;      // 0x1
 void far* Ptr;
};

extern void drawImage(char x,char y,char w,char h,void far *);
//====================================================================================
// ����������/���������� ������������
//====================================================================================
extern void AcquireGbsLock(void);
extern void FreeGbsLock(void);
//====================================================================================

extern int ReceiveMessage(struct MSG far *msg, int doaccept);

extern void SendMessage(PID far *pid_to, unsigned int mess, unsigned int param1);
extern void SendMessage4(PID far *pid_to, 
                         unsigned int mess,
                         unsigned int p1,
                         void far *p2, 
                         void far *p3);

#define pid_DIALER_PROCESS ((PID far *)(0xE*0x4000L+0x3788))
#define pid_NETCORE_PROCESS ((PID far *)(0xE*0x4000L+0x3780))
#define pid_INET_TEST_PROCESS ((PID far *)(0xE*0x4000L+0x3778))

#define pid_MMI ((PID far *)(0xE*0x4000L+0x35E8))

#define pid_MMC_FILE_SYSTEM ((PID far *)(0xE*0x4000L+0x3870))
#define pid_MMC_EXPLORER ((PID far *)(0xE*0x4000L+0x3878))

//------------------------------------------------------------------------------------

extern int GBSS_po_open(const char far *name,unsigned int flag1, int flag2, void far *gbss_buf);
extern int GBSS_po_read(int handle, void far *buf, int bnum, void far *gbss_buf);
extern int GBSS_po_write(int handle, void far *buf, int bnum, void far *gbss_buf);
extern int GBSS_po_close(int handle, void far *gbss_buf);

extern int FileOpen(char far *name,unsigned int flag1,int flag2);
//oflag is an Integer constant combinations defined in FCNTL.H:
#define _O_RDONLY       0x0000  /* open for reading only */
#define _O_WRONLY       0x0001  /* open for writing only */
#define _O_RDWR         0x0002  /* open for reading and writing */
#define _O_APPEND       0x0008  /* writes done at eof */
#define _O_CREAT        0x0100  /* create and open file */
#define _O_TRUNC        0x0200  /* open and truncate */
#define _O_EXCL         0x0400  /* open only if file doesn't already exist */
#define _O_TEXT         0x4000  /* file mode is text (translated) */
#define _O_BINARY       0x8000  /* file mode is binary (untranslated) */
#define _O_NOINHERIT    0x0080  /* child process doesn't inherit file */
#define _O_TEMPORARY    0x0040  /* temporary file bit */
#define _O_SHORT_LIVED  0x1000  /* temporary storage file, try not to flush */
#define _O_SEQUENTIAL   0x0020  /* file access is primarily sequential */
#define _O_RANDOM       0x0010  /* file access is primarily random */
//The pmode argument is required only when _O_CREAT is specified.
//If the file already exists, pmode is ignored.
//Otherwise, pmode specifies the file permission settings,
//which are set when the new file is closed the first time.
#define _S_IREAD        0000400         /* read permission, owner */
#define _S_IWRITE       0000200         /* write permission, owner */
#define _S_IEXEC        0000100         /* execute/search permission, owner */

extern int FileSeek(int handle,long pos, int ref,long far *result);
extern int FileRead(int handle,void far *buf, int bnum);
extern int FileWrite(int handle,void far *buf, int bnum);
extern int FileClose(int handle);
extern int FileErase(char far *);

extern void FilesysICall(void huge *proc);
extern void FilesysICall_I(void huge *proc, int i);
extern void FilesysICall_UI(void huge *proc, unsigned int i);
extern void FilesysICall_L(void huge *proc, long i);
extern void FilesysICall_UL(void huge *proc, unsigned long i);
extern void FilesysICall_FP(void huge *proc, void far *fp);

extern const unsigned long FAM3_sig;

extern const unsigned int _binfile;

extern unsigned int _hour;
extern unsigned int _minute;
extern unsigned int _day;
extern unsigned int _month;
extern unsigned int _year;

struct Time
{
 unsigned int hour;
 unsigned int minute;
 unsigned int second;
};

extern void CopyTime(struct Time far*);

#define HOOK_IDLE 0x10C60

extern char keybQueneIdx;
extern char keybQueneBuf[];
extern int GbsLock_ifNZ;
extern int GbsLock_ifZ;
extern void far *PidAct;

extern unsigned int NETMON_CI;
extern unsigned int NETMON_LAC;

struct CELLDATA
{
 unsigned int CH;
 unsigned int field2;
 unsigned int field4;
 unsigned int field6;
 unsigned int field8;
 unsigned char fieldA;
 unsigned char fieldB;
 unsigned int fieldC;
 unsigned int fieldE;
 unsigned int field10;
 unsigned int field12;
 unsigned int field14;
 unsigned int LAC;
 unsigned int CI;
};

extern struct CELLDATA far *CELL6_PNT[];
extern struct CELLDATA far *CURCELL_PNT;

extern struct
{
 unsigned int CH;
 unsigned char RXLVL;
 unsigned char C1;
 unsigned char C2;
 unsigned char N;
 unsigned char B;
 unsigned char dummy;
} NETMON7_TAB[7];

// 1 - 900
// 2 - 1800
// 3 - auto
extern void SetBAND(unsigned int band);
// ���������� ������� ������ � ������ ch
extern unsigned int GetRXLVL_by_CH(unsigned int ch);
//=======================================================================
struct rectXYXY
{
 unsigned int X1;
 unsigned int Y1;
 unsigned int X2;
 unsigned int Y2;
};
typedef char far * STR;
typedef unsigned int far * WSTR;

extern STRtoWSTRP(WSTR *,STR);
extern DrawObject(void far *);

extern InvalidateScreenRect(unsigned int x,unsigned int y,unsigned int w,unsigned int h);
/*extern PrepDrawObj_type02(
 void far *drwobj,
 struct rectXYXY far *,
 unsigned int flag1,
 WSTR *,
 unsigned int font,
 unsigned int dat1,
 unsigned int flag2);*/

extern PrepDrawObj_type01(
 void far *drwobj,
 struct rectXYXY far *,
 //0x80 - ���. ����� ��� ������
 unsigned int flag1,
 WSTR *,
 unsigned int font,
 //0 - �� ����������, 1 - ����������
 unsigned int flag2);

extern void ResetStringID(unsigned int idx,unsigned int zzz);
extern void StoreTextAsAStringID(unsigned int idx,char far *s,unsigned int zzz);
extern void DisplayMessageBoxV(unsigned int t,unsigned int idx);
extern void setExtSIDTable(void far *);

//======================================================================
// TCP/IP
//======================================================================
extern int CreateSocketAndConnect(unsigned long prot, unsigned long ip, unsigned int port);
extern int recv(int socket, void far *buf, int len, int flags);
extern int send(int socket, void far *buf, int len, int flags);
extern void shutdown(int socket, int how);
extern void closesocket(int socket);
extern void LoadJavaNETprofile(void);
extern int UpNETCORE(void);
extern int Send7_to_NETCORE_PROCESS(void);
extern int Send8_to_NETCORE_PROCESS(void);
extern int Send9_to_NETCORE_PROCESS(void);
extern void far * gethostbyname(STR name, void far *result, int far *siz, void far *zero1, void far *zero2);

extern int socklasterr;

typedef struct
{ 
 unsigned int far* wstr;
 int maxlen;
 int len;
} WS_HDR;

extern void ClearWideString(WS_HDR far*, unsigned int far*, int size);
extern void AddCharToWSTR(WS_HDR far*, unsigned int wchar);
extern void InsertCharToWSTR(WS_HDR far*, unsigned int wchar, unsigned int pos); //first=1
extern void ConcatWSTR(WS_HDR far*str1, WS_HDR far*str2);
extern void ConvLangSTRToWS_HDR(WS_HDR far*dest, char far* in, int flag1, int flag2); //flag1-#1;flag2-#0
extern WS_HDR far* AllocWSTR(unsigned int sz, void huge*);
extern void CutWSTR(WS_HDR far*,unsigned int newlen);
extern void GetStringByID(unsigned int id,WS_HDR far*, int zero);
extern void AsciizToWSTR(WS_HDR far*, char far*);

extern unsigned int WString_GetChar(WS_HDR far *, int);

extern unsigned int WSTR_Len(WS_HDR far*);
typedef struct {
 int type;
 void far* Zero1;
 int Zero2;
 int Zero3;
 char flag;//2
 char len;
 void far* Zero4;
 WS_HDR far* ws_hdr;
 int Zero5;
} INPUT_DATA;

extern void ClearInputData(INPUT_DATA far*);
extern void SetInputData(INPUT_DATA far*,WS_HDR far*,int maxlen);
extern void SetInputType(INPUT_DATA far*, int type); 
//0-no show
//1-only show
//2-digit,*,#
//3-text
//6-only show cursor ?
//5-number(invert, fulllen)
//6-number with dot(on *)
//7-"<text>" not editable
//8-invert,  not editable
extern void AddInputToWSTR(WS_HDR far*,INPUT_DATA far*);

extern int sub_E70BAC(void far*);
extern void far* GetDataPointer_ITEM04(void far*);
extern void sub_F07A66(void far*, int ,WS_HDR far*);

extern int FindSUBSTRinESTR(void far *data, int n);
extern void far *Find_Pointer0A_ItemInMenuITEMSQ_by_ID(void far *data, int id);

typedef struct {
 int flag1;
 int flag2;
 void huge* do1;
 void huge* OnKeyPress; //0xDB9118 - SendMessage(pid_MMI,0xAC,0x17,WS_HDR far*)
 void huge* do3;
 char far* Unk;
 char far* ButtonDefinitions;
 unsigned int x; //0
 unsigned int y; //15
 unsigned int w; //101
 unsigned int h; //55
 int flag3;
 int flag4;
 int Zero1;
 int Zero2;
 int Zero3;
 int Zero4;
 int Zero5;
 int Zero6;
} INPUTDIA_HDNL;

typedef struct {
 unsigned int x; //0
 unsigned int y; //0
 unsigned int w; //101
 unsigned int h; //15
 char far* pMenuIconID; //0xBAFB8A = dw pict, 0
 int header_string_ID;
 int end_of_data; // 0x7FFF
} DIALOG_HEADER; //=MENUHEADER

extern void CreateInputTextDialog(INPUTDIA_HDNL far* inputdia_hdnl, DIALOG_HEADER far* header, WS_HDR far*, int flag);

extern void SetSoftKeyID(void far *data,
   unsigned int softkeytable_element, //����� �������� � ������� softkey
   unsigned int softkey //����� softkey, 1 - ������, 0 - �����
   );