//////////////////// ��������� ���������� /////////////////////////

#define idlegui_id (((int *)data)[DISPLACE_OF_IDLEGUI_ID/4])
#define SCREENSIZE ScreenH()*ScreenW()
#define HSIZE YDISP*ScreenW()
const int minus11=-11;

const char ipc_my_name[]=IPC_FASTRUN_NAME;

const IPC_REQ my_ipc={
  ipc_my_name,
  ipc_my_name,
  NULL
};

int FASTRUNMENU_GUI_ID;// �� ���
extern const char *successed_config_filename;
            
extern void kill_data(void *p, void (*func_p)(void *));

//CSM_DESC icsmd;

//GUI *igui;
#define TMR_SECOND 216// �������
GBSTMR idle_timer;

extern const int IDLE_CALL_BUTTON;// ������ ��������� ������ FastRun
extern const int IDLE_EXIT_BUTTON;// ������ �������� ������ FastRun
int mode_enter;
int idle_pic_size;
int fr_pic_size;
int ConfigUpdated;
extern const int IDLE_PIC_SIZE;
extern const int ENA_IDLE_LONGPRESS;

extern const unsigned int LEN_ID;
extern const unsigned int LEN;
extern const unsigned int BEGIN;
extern const int DRAW_MODE;
extern const int IDLE_ENA;
extern const unsigned int TEXT_FONT;
int IDLE_KEYHOOK_ENA;

char* percent_t="%t";

int NumOfItems_idle;// ����� ������ ���� 
int Selected_idle;// ������� �������
int IdleMenuActive;
extern const unsigned int x1;
extern const unsigned int y1;
unsigned char scrH, scrW;

void EditConfig()
{
  extern const char *successed_config_filename;
  WSHDR *ws;
  ws=AllocWS(150);
  str_2ws(ws,successed_config_filename,128);
  ExecuteFile(ws,0,0);
  FreeWS(ws);
}


extern const char cfgPanBGCol_ID_ena[4];
extern const char cfgPanBGCol_ID_dis[4];
extern const char cfgBookBorderCol_ID[4];
extern const char cfgBookBGCol_ID[4];
extern const char cfgFontCol_ID[4];

extern const char BM1PIC_ID[128];
extern const char BM2PIC_ID[128];
extern const char BM3PIC_ID[128];
extern const char BM4PIC_ID[128];
extern const char BM5PIC_ID[128];
extern const char BM6PIC_ID[128];
extern const char BM7PIC_ID[128];
extern const char BM8PIC_ID[128];
extern const char BM9PIC_ID[128];
extern const char BM10PIC_ID[128];
extern const char BM11PIC_ID[128];
extern const char BM12PIC_ID[128];
extern const char BM13PIC_ID[128];
extern const char BM14PIC_ID[128];
extern const char BM15PIC_ID[128];

extern const char BM1FILE_ID[128];
extern const char BM2FILE_ID[128];
extern const char BM3FILE_ID[128];
extern const char BM4FILE_ID[128];
extern const char BM5FILE_ID[128];
extern const char BM6FILE_ID[128];
extern const char BM7FILE_ID[128];
extern const char BM8FILE_ID[128];
extern const char BM9FILE_ID[128];
extern const char BM10FILE_ID[128];
extern const char BM11FILE_ID[128];
extern const char BM12FILE_ID[128];
extern const char BM13FILE_ID[128];
extern const char BM14FILE_ID[128];
extern const char BM15FILE_ID[128];

extern const char BM1NAME[32];
extern const char BM2NAME[32];
extern const char BM3NAME[32];
extern const char BM4NAME[32];
extern const char BM5NAME[32];
extern const char BM6NAME[32];
extern const char BM7NAME[32];
extern const char BM8NAME[32];
extern const char BM9NAME[32];
extern const char BM10NAME[32];
extern const char BM11NAME[32];
extern const char BM12NAME[32];
extern const char BM13NAME[32];
extern const char BM14NAME[32];
extern const char BM15NAME[32];


//////////////////////////////////////////////////////////
