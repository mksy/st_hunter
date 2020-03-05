//Release 2.10.2006

#ifndef _CBNLIB_H
#define _CBNLIB_H

/////////////mylib.h////////


//#ifdef NEWSGOLD
//#else
int fread32(int fh, void *buf, int len, unsigned int *err);
int fwrite32(int fh, void *buf, int len, unsigned int *err);
//#endif

//#ifdef GRAPH
char *loadgraph(char *filename); // ��������� ������� (������������� � ������������) #define HIGHCOLOR ������
//#endif





int iszero(void *mem, int dsize);

int savefile(char *fname, char *buf, int size);
char *loadfile(char *filename); // ��������� ����, �����������, ����� � loadfilesize
//int fgets(char *buf,int size,int fh);
//char toupper(char c);
char *toup(char *str);			// � �������� ��������
char *todown(char *str);		// � ������� ��������
int  isalth (unsigned char sym);	// ���������� ������ ?
int  isval (char sym);		// ������ �������� ������ ?
int strchrpos(const char *s, int c);	// ������� ������� � ������ (1-N, 0=���)
int emptystr(char *str);		// ������ �� ������
char  *alltrim (char *str);		// ������� ������� �� ����� ������
int   strcmpsize (const char *s1,const char *s2,int size); // �������� ������ ����� size
int getint(void *ptr); // �������� int
short getshort(void *ptr); // �������� short
void putint(void *ptr, int data); // �������� int
void putshort(void *ptr, short data); // �������� short
void bitblt(void *screen, void *bmp, int x, int y, int sizex, int sizey, int x0, int y0,  int colormask, int flags);
char *loadgraph(char *filename); // ��������� ������� (������������� � ������������)


#endif
