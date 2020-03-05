#include "inc\swilib.h"
#include "lang.h"

/*

��� ����������� �������� �� ������/������ ������ �����. �� ���� ��������� ��������,
��� ��� ����� �������� �� ������������ ����������� ������ �����!!

*/

int GetFileSize(const char * fname)	// ������ ����� MC(�)
{
  unsigned int io_error;
  FSTATS fs;
  if (GetFileStats(fname, &fs, &io_error)==-1)
    return 0;
  return (fs.size);
}

int InitLgp(char *lang, void *lng)	// ���� ���� ���������
{
	int f;
	int i = 1;
	unsigned err;
	LANGH head;
  
  if ((f=fopen(lang,A_ReadOnly+A_BIN,P_READ,&err))!=-1)
  {
    fread(f,&head,sizeof(head),&err);
	if (sizeof(head)+head.size == GetFileSize(lang))	// ���� ������ ���������
		fread(f,lng,head.size,&err);	// ������ ���������
	else	// �����
		i = 0;	// ���� ���
    fclose(f,&err);
  }
	else
		i = 0;
  
	return i;	// ��������� ������ ����� (1 - �������, 0 - ������)
}

int InitLgp_2(char *lang, void **array)	// ���� ���� ������
{
	int f;
	int i = 1;
	unsigned err;
	LANGH head;
  
  if ((f=fopen(lang,A_ReadOnly+A_BIN,P_READ,&err))!=-1)
  {
    fread(f,&head,sizeof(head),&err);
	if (sizeof(head)+head.size == GetFileSize(lang))	// ���� ������ ���������
	{
		array = malloc(4*head.count);	// ����������� ����� ��� ������
		for (register int i = 0;i <= head.count; i++)	// ��������� ������
		{
			int size = 0;	// ������ �������
			
			fread(f,&size,sizeof(size),&err);	// ��������� ������
			array[i] = malloc(size);	// ����������� ����� ��� ������
			fread(f,array[i],size,&err);	// ���� �������
		}
	}
	else
		i = 0;
    fclose(f,&err);
  }
	else
		i = 0;
  
	return i;	// ��������� ������ ����� (1 - �������, 0 - ������)
}

int CreateLgp(char *lang,  int build, int type, int count, int size, char *cright, void *lng)	// ���� ���������
{
	int f;
	int i = 1;
	unsigned err;
	LANGH head;
	// ������� ������
	head.build = build;	// ������
	head.type = type;	// ��� �����
	head.count = count;	// ���������� �����
	snprintf(head.cright,64,cright);	// ���������
	head.size = sizeof(head) + size;	// ������ �����
  
  if ((f=fopen(lang,A_WriteOnly+A_BIN+A_Create,P_WRITE,&err))!=-1)
  {
    fwrite(f,&head,sizeof(head),&err);
    fwrite(f,&lng,head.size,&err);
    fclose(f,&err);
  }
	else
	i = 0;
  
	return i;	// ��������� ������ ����� (1 - �������, 0 - ������)
}

int CreateLgp_2(char *lang,  int build, int type, int count, int size, char *cright, void **array)	// ���� ������
{
	int f;
	int i = 1;
	unsigned err;
	LANGH head;
	// ���������� ����������
	head.build = build;	// ������
	head.type = type;	// ��� �����
	head.count = count;	// ���������� �����
	snprintf(head.cright,64,cright);	// ���������
	head.size = sizeof(head) + size + count * sizeof(int);	// ���� �������� �� ���� �������,
								// �.�. ����� ������ � ����������
  
  if ((f=fopen(lang,A_WriteOnly+A_BIN+A_Create,P_WRITE,&err))!=-1)
  {
    fwrite(f,&head,sizeof(head),&err);	// ����� ���������
		
	for (register int i = 0; i <= count; i++)	// ���������� ���� ������
	{
		int str_size = 0;	// ����� ������
		
		str_size = strlen(array[i]);
		// ��� �����, ����������
		fwrite(f,&str_size,sizeof(int),&err);	//	������ �������
		fwrite(f,array[i],str_size,&err);	// ���� �������
	}
    fclose(f,&err);
  }
	else
	i = 0;
  
	return i;
}

int FreeLgp()
{
	return 0;	// � ��� ��� �� �����
}

int GetLgpInfo(char *lang, LANGH *head)	// ��������� ���������� � �����
{
	int f;
	int i = 1;
	unsigned err;
  
  if ((f=fopen(lang,A_ReadOnly+A_BIN,P_READ,&err))!=-1)
  {
    fread(f,&head,sizeof(head),&err);
    fclose(f,&err);
  }	
  else
		i = 0;

		return i;	// ���� 1 - �� ���������, ����� - 0
}
