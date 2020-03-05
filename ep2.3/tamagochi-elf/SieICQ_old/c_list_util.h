#ifndef _C_LIST_UTIL_H
#define _C_LIST_UTIL_H

typedef struct
{
  int y_disp; // ����� �� ����� ������
  unsigned int max_nums; //������������ ���������� ���������
  unsigned int n_contacts; //����� ���������, ������ �� ������
  unsigned int n_groups; // ����� ����� �����
  
  int items_font;
  int items_font_type;

}CONTACT_LIST_DESC;

// ������� ������ � ������������� ������ ���������

void CList_MoveCursorHome();
void CList_MoveCursorEnd();
void OnRedraw_C_List();
int MoveCursor_C_List(int mode_key, int type_key);
void Init_C_List();


#endif
