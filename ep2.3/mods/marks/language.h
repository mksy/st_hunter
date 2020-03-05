#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

#define LG_COPYRIGHT "Marks v0.1\n(c)kluchnik"
//��������� ������ ���� ������ ����� ����� ����
#define LANG_RU
//#define LANG_EN

#ifdef LANG_RU
#define LG_CHANGE      "��������"
#define LG_SAVE        "���������"
#define LG_SET         "���������"
#define LG_ABOUT       "�� �����"
#define LG_EXIT        "�����"
#define LG_MENU        "����"

#define LG_SELECT      "�������"
#define LG_CLOSE       "�������"
#define LG_PATHFILE    "���� � �����: "
#define LG_DELFILE     "���� %s ������!"
#define LG_DELETE      "�������"

#define LG_FILESAVE    "���� ��������!!!"
#define LG_NOTSAVE     "�� ���� ���������!:("

#define LG_NEW_FILE    "����� ������"
#define LG_CREATE      "�������"
#endif

#ifdef LANG_EN
#define LG_SAVE        "Save"
#define LG_SET         "Setting"
#define LG_ABOUT       "About"
#define LG_EXIT        "Exit"
#define LG_MENU        "Menu"

#define LG_SELECT      "Select"
#define LG_CLOSE       "Close"
#define LG_PATHFILE    "Path to file: "
#define LG_DELFILE     "File %s delete!"

#define LG_FILESAVE    "File save!!!"
#define LG_NOTSAVE     "Can't save!:("

#define LG_NEW_FILE    "New file"
#define LG_CREATE      "Create"
#endif

#endif

 
