#ifndef _LANG_H
#define _LANG_H

#include "lib.h"

extern int InitLgp(char *lang, void *lng);	// ���� ���� ���������
extern int InitLgp_2(char *lang, void **array);	// ���� ���� ������
extern int CreateLgp(char *lang,  int build, int type, int count, int size, char *cright, void *lng);	// ���� ���������
extern int CreateLgp_2(char *lang,  int build, int type, int count, int size, char *cright, void **array);	// ���� ������
extern int GetLgpInfo(char *lang, LANGH *head);	// ��������� ���������� � �����

#endif
