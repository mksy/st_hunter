#ifndef _STRING_UTIL_H_
  #define _STRING_UTIL_H_

/*
  �������������� ������ ������ �� ��������� UTF-8 � ANSI
IN:
  - tmp_out: ���� �������� ���������. ����� ��� ������ ������������
             � � ��� ������ ���� ���������� �����
  - UTF8_str: ������ ����� ������ ��� ��������������
  - size: ������� ����� ������ ��� �������������� (UTF8_str)
  - fact - ���� �������� �������� ������ ������ � ������

OUT:  �������������� �����.
*/
void * convUTF8_to_ANSI(char* tmp_out, char *UTF8_str, unsigned int size, int* fact);

char * convUTF8_to_ANSI_STR(char *UTF8_str);

void ascii2ws(WSHDR * ws, const char * s);

unsigned int char8to16(int c);


// ������� �� ���������. UTF16->UTF8
char *utf16_to_utf8(char **s, size_t *len);

// ������� �� ���������. UTF8->UTF16
int utf8_to_utf16(char *utf8, int cc, char *unicode16);

// UTF8 ��� ��������
char* Correct_UTF8_String(char* utf8_jid);

// � ��� ������ ����� ���� ���� ������ (�) �������� �.�.
char* ANSI2UTF8(char* ansi_str, unsigned int maxlen);


// ������ strstr, �� ��� ���������������� � ��������
char *stristr(const char *s, const char *find);

// ������ strcmp, �� ��� ���������������� � ��������
int stricmp(const char *s, const char *d);

unsigned int char16to8(unsigned int c);
void utf82win(char*d,const char *s);

int strcmp_nocase(const char *s, const char *d);

//������� �������
long GetIDLETime(TTime intime, TDate indate);

void del_ext(char *source);

void remove_bad_chars(char *s);

int str2int(const char *str);

char *MakeGlobalString(const char *first, int breakchar, const char *last);


void _WriteLog(char *buf);
#endif
