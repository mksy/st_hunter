#include "csgui.h"
#include "cfg_param.h"
#include "print.h"

static const char * const weekdays[7]=	//������ � ������� ���� ������
{
	"�����������",
	"�������",
	"�����",
	"�������",
	"�������",
	"�������",
	"�����������"
};

static const char * const monthes[12]=	//�������� �������
{
	"������",
	"�������",
	"�����",
	"������",
	"���",
	"����",
	"����",
	"�������",
	"��������",
	"�������",
	"������",
	"�������"
};

int isGUI;		//�� ��� ��� ���� ����, ���� ��� ���. ���� ���������
void *canvasdata;

void csGUI::redraw ()	//����������-�� �� ���
{
	DirectRedrawGUI();
}

void csGUI::onRedraw()	//��������� �����
{
	TTime time;
	TDate date;

	WSHDR *date_str=AllocWS(128);
	const char transparent[4]={0,0,0,0};


	if (BG_TYPE==1)	//���� ��� ���� - ��������
	{
		DrawImg(0,0,(int)bg_img);	//�� ������ ��������
	}
	else	//���� ���
	{
		DrawRectangle(0,0,ScreenW()-1,ScreenH()-1,0,bg_col,bg_col);	//�� ������ ������
	}

	if (USE_CLOCK_BG)	//���� ��������?
	{
		DrawImg((ScreenW()-GetImgWidth((int)clock_bg_img))/2,clock_bg_y,(int)clock_bg_img);	//��������
	}

	GetDateTime(&date, &time);	//������� �����/����


	wsprintf(date_str,"%02d %t %d%t\n%t", date.day, monthes[date.month-1], date.year, "�", weekdays[GetWeek(&date)]);			//����������
	DrawString(date_str,0,date_y,ScreenW()-1,date_y+GetFontYSIZE(DATE_FONT_SIZE)*2,DATE_FONT_SIZE,2,date_font_col,transparent);	//� ������ ��

	if (!CLOCK_FONT_TYPE) //���� ���������
	{
		WSHDR *time_str=AllocWS(32);
		wsprintf(time_str,"%02d:%02d",time.hour,time.min);	//�������
		DrawString(time_str,0,clock_y,ScreenW()-1,clock_y+GetFontYSIZE(CLOCK_FONT_SIZE),CLOCK_FONT_SIZE,2,clock_font_col,transparent); //������
		FreeWS(time_str);
	}
	else
	{
		PrintLibInit(1);	//���������� ���� ���-������� �� ������ ������
		FontPathInit((char *)clock_font_path,0);	//���������� �����

		char *clockstr=new char [5];
		sprintf(clockstr,"%02d:%02d", time.hour, time.min);	//��� � �������

		PrintField(ScreenW()/2, clock_y, clockstr, 1, 1, clock_font_gap);	//�������� �� ������
	}

	FreeWS(date_str);
}

void csGUI::onCreate()	//��� �������� �����
{
	isGUI=1;	//�� ����!
}

void csGUI::onFocus()	//���� � ������
{
#ifdef ELKA
	DisableIconBar(1);	//������� ���������
#endif
}

void csGUI::onUnFocus()	//�������� �����
{
#ifdef ELKA
	DisableIconBar(0);	//����� ������� ���������
#endif
	Close();		//� ������� ���
}

void csGUI::onClose()	//��� ��������
{
	isGUI=0;		//��� ���
	SetIllumination(0,1,0,0);	//�������� ����
	extern GBSTMR timer;
	GBS_DelTimer(&timer);	//������ ������
	DrawScreenSaver();
	delete this;		//�� �������� ���������� �� �����
}

int  csGUI::onKey(char key_code, int key_msg, short keys)	//��� ������� ������
{
	if (key_msg==KEY_DOWN)	//���� ������ �������. ������ ����� (����� ������ ������)
	{
		Close();	//���������
		return GUI_RESULT_CLOSE;
	}
	return GUI_RESULT_OK;
}


csGUI::csGUI()
{}
csGUI::~csGUI()
{}
