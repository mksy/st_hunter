#include <swilib2.h>
#include "../../../libsiemens/files.h"
#include "../../../libsiemens/lang.h"
#include "../../../libsiemens/graphics.h"
#include "../../../libsiemens/other.h"
#include "../../../libshell/plugins.h"
#include "../../../libshell/other.h"
#include "../../../libshell/menu.h"
#include "../../../libshell/graphics.h"
#include "../../../libshell/conf_loader.h"
#include "../../../libshell/skin_utils.h"
#include "../../../libshell/config_coord.h"
#include "../../../libshell/conf_loader.h"
#include "conf_loader.h"
#include "config_data.h"

#define MENU1_ITEMS 0x05
#define MENU2_ITEMS 0x09

MENU *menu1, *menu2;

IMGHDR *menu1_icons[MENU1_ITEMS];
IMGHDR *menu2_icons[MENU2_ITEMS];
WSHDR *menu1_ws1[MENU1_ITEMS], *menu1_ws2[MENU1_ITEMS];
WSHDR *menu2_ws1[MENU2_ITEMS], *menu2_ws2[MENU2_ITEMS];

enum
{
	lgpHeader,
	lgpLeftSoftkey,
	lgpRightSoftkey
};

char **lgp;

WSHDR *ws;

unsigned int *desk_id_ptr;
unsigned int plugin_id;

void menu2_func1(void){ExecShortcut("SETUP_RINGTONES");}
void menu2_func2(void){ExecShortcut("SETUP_DISPLAY");}
void menu2_func3(void){ExecShortcut("VIBRA_LIGHT");}
void menu2_func4(void){ExecShortcut("SETUP_CNCT");}
void menu2_func5(void){ExecShortcut("SETUP_CALL");}
void menu2_func6(void){ExecShortcut("SETUP_PHONE");}
void menu2_func7(void){ExecShortcut("SETUP_CLOCK");}
void menu2_func8(void){ExecShortcut("SETUP_SECURITY");}
void menu2_func9(void){ExecShortcut("SETUP_NETWORK");}

void *menu2_procs[MENU2_ITEMS]=
{
	menu2_func1,
	menu2_func2,
	menu2_func3,
	menu2_func4,
	menu2_func5,
	menu2_func6,
	menu2_func7,
	menu2_func8,
	menu2_func9
};

void menu1_func1(void)
{
	menu2 = CreateSMenu(menu2_ws1, menu2_ws2, menu2_icons, MENU_MANY_ICONS, menu2_procs, 
		ICONBAR_H + img[imgHeader]->h + cfg_coord_menu1_off_y, cfg_coord_max_menu1_items, MENU2_ITEMS);
	DirectRedrawGUI_ID(shell_gui_id);
}
void menu1_func2(void){ExecFile(cfg_path);}
void menu1_func3(void){ExecFile(cfg_col_path);}
void menu1_func4(void){ExecFile(cfg_coord_path);}
void menu1_func5(void){ExecFile(cfg_font_path);}

void *menu1_procs[MENU1_ITEMS]=
{
	menu1_func1,
	menu1_func2,
	menu1_func3,
	menu1_func4,
	menu1_func5
};

void OnRedraw(void)
{
	DrawText(ws, lgp[lgpHeader], GetFont(fontHeader1), TEXT_ALIGNMIDDLE, GetColor(colorHeader), TEXT_TYPE_HEADER);
	DrawText(ws, lgp[lgpLeftSoftkey], GetFont(fontSoftkeys), TEXT_ALIGNLEFT, GetColor(colorSoftkeys), TEXT_TYPE_SOFTKEY);
	if (menu2 == NULL)
	{
		DrawSMenu(menu1);
	}
	else
	{
		DrawText(ws, lgp[lgpRightSoftkey], GetFont(fontSoftkeys), TEXT_ALIGNRIGHT, GetColor(colorSoftkeys), TEXT_TYPE_SOFTKEY);
		DrawSMenu(menu2);
	}
}

void Destroy(void)
{
	if (lgp)
		FreeLang(&lgp);
	int i = 0;
	while(i < MENU1_ITEMS)
	{
		if (menu1_ws1[i]) FreeWS(menu1_ws1[i]);
		if (menu1_ws2[i]) FreeWS(menu1_ws2[i]);
		FreeIMGHDR(menu1_icons[i++]);
	}
	i = 0;
	while(i < MENU1_ITEMS)
	{
		if (menu2_ws1[i]) FreeWS(menu2_ws1[i]);
		if (menu2_ws2[i]) FreeWS(menu2_ws2[i]);
		FreeIMGHDR(menu2_icons[i++]);
	}
	if (menu1)
		DestroySMenu(menu1);
	if (menu2)
		DestroySMenu(menu2);
	if (ws)
		FreeWS(ws);
}

void OnKey(unsigned int key, unsigned int type)
{
	if (type == KEY_DOWN)
	{
		if (key == UP_BUTTON)
		{
			goto UP;
		}
		else if (key == DOWN_BUTTON)
		{
			goto DOWN;
		}
		else if (key == ENTER_BUTTON)
		{
			keyblock_id = plugin_id;
			goto ACTION;
		}
		else if (key == LEFT_SOFT)
		{
			ACTION:
				if (menu2 == NULL)
					ActionSMenu(menu1);
				else
					ActionSMenu(menu2);
		}
		else if (key == RIGHT_SOFT)
		{
			if (menu2 != NULL)
			{
				DestroySMenu(menu2);
				menu2 = NULL;
				DirectRedrawGUI_ID(shell_gui_id);
			}
		}
	}
	else if (type == LONG_PRESS)
	{
		if (key == UP_BUTTON)
		{
			UP:
				keyblock_id = plugin_id;
				if (menu2 == NULL)
					OnKeySMenu(menu1, MENU_UP);
				else
					OnKeySMenu(menu2, MENU_UP);
		}
		else if (key == DOWN_BUTTON)
		{
			DOWN:
				keyblock_id = plugin_id;
				if (menu2 == NULL)
					OnKeySMenu(menu1, MENU_DOWN);
				else
					OnKeySMenu(menu2, MENU_DOWN);
		}
	}
	else if (type == KEY_UP)
	{
		if (key == UP_BUTTON || key == DOWN_BUTTON || key == ENTER_BUTTON)
			keyblock_id = 0;
	}
}

void OnMessage(CSM_RAM *data, GBS_MSG *msg)
{
	if (msg->msg == MSG_RECONFIGURE_REQ)
	{
		if (strcmp(successed_config_filename, (char*)msg->data0) == 0)
		{
			InitPlgConfig(successed_config_filename);
			*desk_id_ptr         = cfg_desk_id;
		}
		else if (strcmp(cfg_coord_path, (char*)msg->data0) == 0)
		{
			DestroySMenu(menu1);
			menu1 = CreateSMenu(menu1_ws1, menu1_ws2, menu1_icons, MENU_MANY_ICONS, menu1_procs,
				ICONBAR_H + img[imgHeader]->h + cfg_coord_menu1_off_y, cfg_coord_max_menu1_items, MENU1_ITEMS);
		}
	}
}

int main(PLUGIN_S4T *plg)
{
	//чтение конфига
	char path[128];
	sprintf(path, "%s%s%s", conf_dir, plg->fname, ".bcfg");
	InitPlgConfig(path);
	
	
	plg->Destroy   = (void*)Destroy;
	plg->OnRedraw  = (void*)OnRedraw;
	plg->OnKey     = (void(*)(unsigned int, unsigned int))OnKey;
	plg->OnMessage = (void(*)(CSM_RAM*, GBS_MSG*))OnMessage;
	
	//загрузка ленгпака
	sprintf(path, "%s%s", lang_dir, "settab.txt");
	if (InitLang(path, &lgp) == -1) return -1;
	
	unsigned int i      = 0;
	unsigned int lgp_id = 3;
	while(i < MENU1_ITEMS)
	{
		menu1_ws1[i] = AllocWS(128);
		wsprintf(menu1_ws1[i], "%t", lgp[lgp_id]);
		menu1_ws2[i] = AllocWS(128);
		wsprintf(menu1_ws2[i], "%t", lgp[lgp_id + 1]);
		sprintf(path, "%s%s%d%s", img_dir, "settab\\01_", i + 1, ".png");
		menu1_icons[i++] = CreateIMGHDRFromPngFile(path, 0);
		lgp_id += 2;
	}
	i = 0;
	while(i < MENU2_ITEMS)
	{
		menu2_ws1[i] = AllocWS(128);
		wsprintf(menu2_ws1[i], "%t", lgp[lgp_id]);
		menu2_ws2[i] = AllocWS(128);
		wsprintf(menu2_ws2[i], "%t", lgp[lgp_id + 1]);
		sprintf(path, "%s%s%d%s", img_dir, "settab\\02_", i + 1, ".png");
		menu2_icons[i++] = CreateIMGHDRFromPngFile(path, 0);
		lgp_id += 2;
	}
	
	menu1 = CreateSMenu(menu1_ws1, menu1_ws2, menu1_icons, MENU_MANY_ICONS, menu1_procs,
		ICONBAR_H + img[imgHeader]->h + cfg_coord_menu1_off_y, cfg_coord_max_menu1_items, MENU1_ITEMS);
	
	ws  = AllocWS(128);
	
	plg->desk_id = cfg_desk_id;
	desk_id_ptr  = &plg->desk_id;
	plugin_id    = plg->id;
	
	return 0;
}
