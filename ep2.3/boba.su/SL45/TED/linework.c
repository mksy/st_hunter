#include "sl45.h"

#define STKSZ (16384)

extern unsigned int far usp; //��������� �� ������� ����
extern unsigned int far dsp; //��������� �� ������ ����
extern unsigned char far dstk[];
extern unsigned char far ustk[];

unsigned int bl_us(unsigned int p)
{
 if (!p) return(p);
 do
 {
  if (!(--p)) break;
 }
 while(ustk[p-1]);
 return(p);
}

unsigned int bl_ds(unsigned int p)
{
 if (p==STKSZ) return(p);
 do
 {
  p++;
 }
 while(dstk[p-1]);
 return(p);
}

//������� �� �������� ����� � ������ (�� ������ �����)
void move_up(void)
{
 unsigned int s=usp;
 unsigned int d=dsp;
 unsigned char c;
 if (!s) return;
 dstk[--d]=ustk[--s]; //��������� 0
 if (s>256)
 {
  while((c=ustk[--s])) dstk[--d]=c;
  s++;
 }
 else
 {
  while(s)
  {
   if (!(c=ustk[s-1])) break;
   s--;
   dstk[--d]=c;
  }
 }
 usp=s;
 dsp=d;
}

//������� �� ������� ����� � ������� (�� ������ ����)
void move_dw(void)
{
 unsigned int s=dsp;
 unsigned int d=usp;
 if (s==STKSZ) return;
 while((ustk[d]=dstk[s]))
 {
  d++;
  s++;
 }
 d++;
 s++;
 dsp=s;
 usp=d;
}