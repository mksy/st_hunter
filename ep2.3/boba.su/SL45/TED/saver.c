#include "sl45.h"

#define STKSZ (16384)
#define STKSZ50 (8192)

#pragma class fb=CFAR_SAV
unsigned char far ibuf[STKSZ50];
unsigned char far obuf[STKSZ50];
#pragma default_attributes

extern int far u_disk; //�������� ��������� �������� ����� (� ������ �� STKSZ50)
extern int far d_disk; //�������� ��������� ������� ����� (� ������ �� STKSZ50)
extern unsigned int far usp; //��������� �� ������� ����
extern unsigned int far dsp; //��������� �� ������ ����
extern unsigned char far dbat[256]; //������� ������������� ������ ������� ����� �� ��������� �����
extern unsigned char far ubat[256]; //������� ������������� ������ �������� ����� �� ��������� ����e
extern char far stkfile[];
extern char far filename[];
extern unsigned char far dstk[];
extern unsigned char far ustk[];

extern unsigned char far disk_access;

extern unsigned int bl_ds(unsigned int pos);

extern unsigned int far terminated; //������� �������� �������
extern int far dia_id;
extern volatile unsigned char far draw_mode;

#define flush_obuf(FILEH,P) {if (P>=STKSZ50) {FileWrite(FILEH,obuf,P); P=0;}}

void savetext(void)
{
 int sf;
 int f;
 unsigned int p;
 long ul;
 int i;
 char c;

 f=FileOpen((STR)filename,_O_RDWR+_O_BINARY+_O_CREAT+_O_TRUNC,_S_IREAD); //������� �������� ����
 sf=FileOpen((STR)stkfile,_O_RDONLY+_O_BINARY,0); //���� �������� �����

 i=0;
 while(i<=u_disk)
 {
  //����� ������� ���� ���������������
  p=ubat[i++];
  FileSeek(sf,_mulu32(STKSZ50,p),0,&ul);
  FileRead(sf,ibuf,STKSZ50);
  p=0;
  while(p!=STKSZ50)
  {
   if (!ibuf[p]) ibuf[p]=0x0D;
   p++;
  }
  FileWrite(f,ibuf,STKSZ50);
 }
 //����� ������� ���� �� ���
 p=0;
 i=0;
 while(p!=usp)
 {
  c=ustk[p];
  if (!c) c=0x0D;
  obuf[i]=c;
  i++;
  flush_obuf(f,i);
  p++;
 }
 p=dsp;
 while(p!=STKSZ)
 {
  //����� ������ ���� �� ���
  c=dstk[p];
  if (!c) c=0x0D;
  obuf[i]=c;
  i++;
  flush_obuf(f,i);
  p++;
 }
 FileWrite(f,obuf,i); //���������
 i=d_disk;
 while(i>=0)
 {
  //����� ������ ����
  p=dbat[i--];
  FileSeek(sf,_mulu32(STKSZ50,p),0,&ul);
  FileRead(sf,ibuf,STKSZ50);
  p=0;
  while(p!=STKSZ50)
  {
   if (!ibuf[p]) ibuf[p]=0x0D;
   p++;
  }
  FileWrite(f,ibuf,STKSZ50);
 }
 FileClose(sf); //����� ������ ����������� � ������� �����
 FileClose(f);
 disk_access=0;
 draw_mode=1; //��������������
 if (!terminated) SendMessage((void far *)0x3B5E8,0xF8,dia_id);
}

