#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

typedef enum UI_STATE
{
    NONE,
    BG,
    CUR,
    BG_CUR
} UI_STATE;

extern IMGHDR* background;	//���������
extern IMGHDR* cursor;		//������

extern UI_STATE stateUI;	//��� ������������ �� �������

void setUI();		//����
void freeUI ();		//��������

#endif // GUI_H_INCLUDED
