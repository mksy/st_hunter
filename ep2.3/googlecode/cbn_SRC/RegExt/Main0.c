
// RegExt 0.1
// ��������� ���������� � extension open

#include "E:\ARM\swilib.h"


#define nameoff 12
const char cfg[32]="0:\\ZBin\\etc\\open.cfg";

void ElfKiller(void){
extern void *ELF_BEGIN;
((void (*)(void *))(mfree_adr()))(&ELF_BEGIN);
}
//11
const char msg[]="����������     ���������";

int main(char *exename, char *fname){ //fname=���������� 
  unsigned int err;
  int i=0, f;
  char cr[2]={0xd,0xa};
  if(fname){
  while((f=fopen(cfg,A_ReadOnly+A_BIN,P_READ,&err))==-1){
    switch(++i){
    case 1: *(char*)cfg='4'; break;
    case 2: *(char*)cfg='0'; memcpy((char*)cfg+nameoff,"extension.cfg",14); break;
    case 3: *(char*)cfg='4'; break;
    default: goto lex;
    }
  }
  fclose(f,&err);
  if((f=fopen(cfg,A_ReadWrite+A_BIN,P_READ+P_WRITE,&err))==-1) goto lex;
  lseek(f,0,2,&err,&err);
  fwrite(f,cr,2,&err);
  fwrite(f,fname,strlen(fname),&err);
  fclose(f,&err);
  i=11;
  while(*fname!=':' && *fname!='/')
    *(char*)(msg+i++)=*fname++;
  ShowMSG(1,(int)msg);
}
lex:  
  SUBPROC((void *)ElfKiller);
  return (0);
}  


/*
int main2(char *exename, char *fname)
{
  char out[3]="0";
  unsigned int err;
  int f=-1, size=0;
  char *buf=0, *file;
  do{
    if(!fname){*out='1'; break;}
    if((f=fopen(fname,A_ReadOnly+A_BIN,P_READ,&err))==-1){*out='2'; break;}//error 0 here
    file=fname+strlen(fname); 
    while(*--file!='.');
    *file=0;
    size=lseek(f,0,2,&err,&err);
    if(!size){*out='3'; break;}
    if(!(buf=malloc(size))){*out='4'; break;}
    lseek(f,0,0,&err,&err);
    if(fread(f,buf,size,&err)!=size){ *out='5'; break;}
    fclose(f,&err);
    f=-1;
    if((f=fopen(fname,A_WriteOnly+A_BIN+A_Create,P_WRITE,&err))==-1){*out='6'; break;}
//    lseek(f,0,0,&err,&err);
    fwrite(f,buf,size,&err);
    *out='8'; //all ok
 }while(0);
 if(buf) mfree(buf);
 if(f!=-1) fclose(f,&err);
////log
 if((f=fopen("0:\\ZBin\\log",A_ReadWrite+A_BIN+A_Create,P_READ+P_WRITE,&err))!=-1){
   fwrite(f,out,1,&err);
   fclose(f,&err);
 }
 SUBPROC((void *)ElfKiller);
 return (0);
}

//��������
int main(char *exename, char *fname)
{
  char out[3]="0";
  unsigned int err;
  int f=-1, size=0;
  char *buf=0, *file;
  do{
    if(!fname){*out='1'; break;}
    if((f=fopen(fname,A_ReadWrite+A_BIN+A_Create,P_READ+P_WRITE,&err))==-1)
      {*out='9'; break;}
//    if((f=fopen(fname,A_ReadOnly+A_BIN,P_READ,&err))==-1){*out='2'; break;}//error 0 here
    file=fname+strlen(fname);
    while(*--file!='.');
    *file=0;
    size=lseek(f,0,2,&err,&err);
    if(!size){*out='3'; break;}
    if(!(buf=malloc(size))){*out='4'; break;}
    lseek(f,0,0,&err,&err);
    if(fread(f,buf,size,&err)!=size){ *out='5'; break;}
    fclose(f,&err);
    f=-1;
    if((f=fopen(fname,A_ReadWrite+A_BIN+A_Create,P_READ+P_WRITE,&err))==-1){*out='6'; break;}
    lseek(f,0,0,&err,&err);
    fwrite(f,buf,size,&err);
    *out='8'; //all ok
 }while(0);
 if(buf) mfree(buf);
 if(f!=-1) fclose(f,&err);
////log
 if((f=fopen("0:\\ZBin\\log",A_ReadWrite+A_BIN+A_Create,P_READ+P_WRITE,&err))!=-1){
   fwrite(f,out,1,&err);
   fclose(f,&err);
 }
 SUBPROC((void *)ElfKiller);
 return (0);
}
*/
