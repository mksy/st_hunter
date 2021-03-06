

// VM  mapped files
// ��������� ����� �������

//#include "..\mylib.h"
#include "defs.h"
//#include "..\random.h"

//extern unsigned int randseed;
//extern unsigned char USERAM, SGOLD2;

//#define pagesize 0x8000
//#define pagemask 0x7FFF
//#define pageshift 15

#define pagesize 0x4000
#define pagemask 0x3FFF
#define pageshift 14


/*
struct fmapst{
  FILE* f; //handle
  char **mem; //���� �����. ���-� 
  int pages; //����� ������� � �����
  int allocpages; //�������� ������ ��� ������� � �����
};
*/
struct fmapst fmap;


//extern int fmapopen(char *fname, struct fmapst *fmap, int freepages); //������� ���� � ������������� �� ������ ������� maxpages
//extern void fmapread(struct fmapst *fmap, int page); // "����������" ��������
//extern void fmapclose(struct fmapst *fmap); //������� ����

#define ffopen fopen
#define ffclose fclose
#define ffread fread
#define llseek lseek


int fmapopen(char *fname, struct fmapst *fmap, int freepages){ //������� ���� � ������������� �� ������, �������� ����. free �������
  int i, pages;
  int f;
  char **mem;
  if((fmap->f=f=ffopen(fname,A_ReadOnly+A_BIN,P_READ,&err))==-1) return 2; //no open
  loadfilesize=llseek(f,0,2,&err,&err);
  llseek(f,0,0,&err,&err);
  if(!(pages=fmap->pages=(loadfilesize>>pageshift))) return 3; //file empty
  if(!(mem=fmap->mem=(char**)malloc(pages<<2))) return 4; //no mem
  memset(mem,0,pages<<2);

  for(i=0;i<pages;i++)
    if(!(*mem++=(char*)malloc(pagesize))){
      while(--freepages>=0){ mfree(*--mem); *mem=0; --i;}
      break;
    }
  *mem=0;
  fmap->allocpages=i;
  //cache
  mem=fmap->mem;
  while(--i>=0)
    ffread(f,*mem++,pagesize,&err);
  return 0;
}

void fmapclose(struct fmapst *fmap){ //������� ����
  char **mem=fmap->mem;
  int i=fmap->pages;
  while(--i>=0){
    if(*mem) mfree(*mem);
    ++mem;
  }
  mfree(fmap->mem);
  if(fmap->f>0){ ffclose(fmap->f,&err); fmap->f=0;}
//  memset(&fmap,0,sizeof(struct fmapst));
}

void readfile(int f, char *buf, int n){//������ ������
  llseek(f,n<<pageshift,0,&err,&err);
  ffread(f,buf,pagesize,&err);
}


//int random(){ return 1;}//FAKE!!! //������ �����. 2 �����!!!
extern unsigned int randint( int max );

void fmapread(struct fmapst *fmap, int page){ // "����������" ��������
  int n;
  if(fmap->mem[page]) return;
  char **mem=fmap->mem+1;//+1 ������!!!
  //�����. �� ������ ��� �� ������� n=random/pageees
//   n=rand()%(fmap->allocpages-1);
   n=randint(fmap->allocpages-1);
  while(n>=0) if(*mem++) --n; //>=0????
  //������ ������
  readfile(fmap->f, fmap->mem[page]=*--mem, page);
  *mem=0; //���������� �����
}


//������ ������ �������
//  if(!mem[j=i>>pageshift]) fmapread(f,mem,j);
//  return mem[j][i&pagemask];

//�������� ������
//if((i&pagemask)<pagesize-4)

//�������� �-�
//if((f=fmapopen(fname,getfreeram()*3/4))<0) error
//fmapclose();

//��� �����
//char *mem2[100]; //100 4 �� �������
//ramalloc(mem2,100);

//////////

//void Killer(void){
//extern void *ELF_BEGIN;
//((void (*)(void *))(mfree_adr()))(&ELF_BEGIN);
//}

//void tmp(){
//  if(fmapopen("11", &fmap, 0)) return;
//  fmapclose(&fmap);
//}
