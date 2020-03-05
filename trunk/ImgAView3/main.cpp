#include <swilib.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <conf_loader.h>
#include "krnl.h"

unsigned short maincsm_name_body[140];
unsigned int MAINCSM_ID = 0;
unsigned int MAINGUI_ID = 0;
const int minus11=-11;
int my_csm_id=0;

char *img_start_file=NULL;

typedef struct
{
    CSM_RAM csm;
    int gui_id;
} MAIN_CSM;

typedef struct
{
    GUI gui;
    WSHDR *ws;
} MAIN_GUI;

#define ELF_NAME "ImgAView3"

extern char * successed_config_filename;


/*------------------------------------------------------------------------*/
/*--------------------- �������� ��� �������� � ��� ----------------------*/
/*------------------------------------------------------------------------*/

//char clrWhite[]= {0xFF,0xFF,0xFF,0x64};
char clrBlack[]= {0x00,0x00,0x00,0x64};

//int scr_w,scr_h;


static void OnRedraw(MAIN_GUI *data)
{
#ifdef ELKA
    DisableIconBar(1);
#endif
    //DrawRoundedFrame(0,0,scr_w,scr_h,0,0,0,clrBlack,clrWhite);
    DrawWindow ();

    //wsprintf(data->ws, "%t\nHello World","������ ���");

    //DrawString(data->ws,0,28,scr_w-1,scr_h-1,FONT_SMALL,2+32,GetPaletteAdrByColorIndex(0),GetPaletteAdrByColorIndex(1));
}


static void onCreate(MAIN_GUI *data, void *(*malloc_adr)(int))
{
    //data->ws = AllocWS(128);
    Init(img_start_file);
    data->gui.state=1;
}

static void onClose(MAIN_GUI *data, void (*mfree_adr)(void *))
{
    data->gui.state=0;
    //FreeWS( data->ws );

    ImgAViewOnClose ();
}

static void onFocus(MAIN_GUI *data, void *(*malloc_adr)(int), void (*mfree_adr)(void *))
{
    data->gui.state=2;
    DisableIDLETMR();

}

static void onUnfocus(MAIN_GUI *data, void (*mfree_adr)(void *))
{
#ifdef ELKA
    DisableIconBar(0);
#endif

    if (data->gui.state!=2) return;
    data->gui.state=1;
}


static int OnKey(MAIN_GUI *data, GUI_MSG *msg)
{
    int mess=msg->gbsmsg->msg;
    int key=msg->gbsmsg->submess;

    return ImgAViewOnKey (mess, key);

    /*if ((msg->gbsmsg->msg==KEY_DOWN || msg->gbsmsg->msg==LONG_PRESS))
    {
        switch(msg->gbsmsg->submess)
        {
            case '#':  DoConfig (); break;

            case RIGHT_SOFT:
            return (1);
        }
    }*/

    return(0);
}


void OnDestroy(){
}

int method8(void)
{
    return(0);
}
int method9(void)
{
    return(0);
}

const void * const gui_methods[11]=
{
    (void *)OnRedraw,
    (void *)onCreate,
    (void *)onClose,
    (void *)onFocus,
    (void *)onUnfocus,
    (void *)OnKey,
    0,
    (void *)OnDestroy,
    (void *)method8,
    (void *)method9,
    0
};


const RECT Canvas= {0,0,0,0};
static void maincsm_oncreate(CSM_RAM *data)
{
    //scr_w=ScreenW()-1;
    //scr_h=ScreenH()-1;
    MAIN_CSM*csm=(MAIN_CSM*)data;
    MAIN_GUI *main_gui = new MAIN_GUI [sizeof(MAIN_GUI)];
    zeromem(main_gui,sizeof(MAIN_GUI));
    main_gui->gui.canvas=(RECT *)(&Canvas);
    main_gui->gui.methods=(void *)gui_methods;
    main_gui->gui.item_ll.data_mfree=(void (*)(void *))mfree_adr();
    csm->csm.state=0;
    csm->csm.unk1=0;
    my_csm_id=csm->gui_id=CreateGUI(main_gui);
}

static void maincsm_onclose(CSM_RAM *csm)
{
	free(img_start_file);
    kill_elf();
}

static int maincsm_onmessage(CSM_RAM *data, GBS_MSG *msg)
{
    MAIN_CSM *csm=(MAIN_CSM*)data;
    if ((msg->msg==MSG_GUI_DESTROYED)&&((int)msg->data0==csm->gui_id))
    {
        csm->csm.state=-3;
    }

    if(msg->msg == MSG_RECONFIGURE_REQ)
    {
        if (strncasecmp(successed_config_filename, (char *)msg->data0, strlen(successed_config_filename) ) == 0 )
        {

            InitConfig();
            //IsFontCfgUpdate=1;
            ShowMSG (1, (int)"Config updated!");

        }
    }

    return(1);
}


const struct
{
    CSM_DESC maincsm;
    WSHDR maincsm_name;
} MAINCSM =
{
    {
        maincsm_onmessage,
        maincsm_oncreate,
#ifdef NEWSGOLD
        0,
        0,
        0,
        0,
#endif
        maincsm_onclose,
        sizeof(MAIN_CSM),
        1,
        &minus11
    },
    {
        maincsm_name_body,
        NAMECSM_MAGIC1,
        NAMECSM_MAGIC2,
        0x0,
        139,
        0
    }
};


void UpdateCSMname(void)
{
  WSHDR *wsx=AllocWS(128);
  str_2ws(wsx, GetCurImgName (), 128);
  wsprintf((WSHDR *)(&MAINCSM.maincsm_name),"%s: %w", ELF_NAME, wsx);
  FreeWS(wsx);
}
/*
void UpdateCSMname(void)
{
    wsprintf((WSHDR *)(&MAINCSM.maincsm_name), ELF_NAME);
}
*/

int main (char *exename, char *fname)
{
	InitConfig();

	if(fname){
	img_start_file=(char *)malloc(strlen(fname)+1);
	strcpy(img_start_file,fname);
    MAIN_CSM main_csm;
    LockSched();
    //UpdateCSMname();
    CreateCSM(&MAINCSM.maincsm,&main_csm,0);
    UpdateCSMname();

    UnlockSched();


    //LibWork ();
	}
    return 0;
}
