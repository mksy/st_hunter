#include "../inc/swilib.h"
#include "List.h"
#include "File.h"

char *mas[4];

void WriteTime(CFile *file)
{
  TTime t;
  char s[32];
  GetDateTime(0,&t);
  sprintf(s,"%d:%d\n",t.sec,t.millisec);
  file->write(s,strlen(s));  
}

int main()
{
  CList *list = new CList;//������� ��� ����
  CFile *file = new CFile("4:\\time_test.txt");// ����, � �������� ��������� ��� �����
  file->open(A_Create+A_Truncate+A_WriteOnly);//��������� ����,� �������� ��������� ����� �������
    
  mas[0] = "1.fisrt";
  mas[1] = "2.second";
  mas[2] = "3.text";
  mas[3] = "4.ibibibi";
  
  //�� ��������� �����
  list->add("1.fisrt");
  list->add("2.second");
  list->add("3.text");
  list->add("4.ibibibi");  
  
  WriteTime(file);  

  for(int i = 0 ; i<4; i++)
  {
    file->write(mas[i],strlen(mas[i]));
    file->write("\n",1);
  }    
   
  
  WriteTime(file);  
  
  //���������� � ���� ��� �����������
  for(int i = 0 ; i<list->Count(); i++)
  {
    file->write(list->Items(i)->name,strlen(list->Items(i)->name));
    file->write("\n",1);
  }  
  
  WriteTime(file);  
  
  file->close();//��������� �����, ��� �� ����� ������������ ��� �������� � �����������,����� ������ =)
  file->execute();//��������� ����
  
  //�������...:)
  delete list;
  delete file;  
  return 0;
}
