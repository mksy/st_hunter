#include "../inc/swilib.h"
#include "List.h"
#include "File.h"
#include "mlist.h"
#include "csm.h"
#include "dialog.h"

//CList *qlist;
//DialogCSM *csm;


int main()
{
  MainDialog* dialog = new MainDialog();
  StandartList *l = new StandartList;
  CList *list = new CList;
  //l->Show("Left","RIGHT");

   
  // csm->SetName("Mark");
//   csm->Create();
//   qlist = new CList;//������� ��� ����
  //CFile *file = new CFile("4:\\classlist.txt");// ����, � �������� ��������� ��� �����
 // file->open(A_Create+A_Truncate+A_WriteOnly);//��������� ����,� �������� ��������� ����� �������
  
  //�� ��������� �����
  list->add("1.fisrt");
  list->add("2.second");
  list->add("3.text");
  list->add("4.ibibibi");  
  list->add("5.)))))))");

  l->list = list;
  dialog->list = l;
  dialog->Show();  
  //for(int i=0 ; i<qlist->Count(); i++) ShowMSG(1,(int)qlist->Items(i)->name);
  
//  StandartList *l = new StandartList;
  //l->Show("Left","RIGHT");

  
  
  /*
  //���������� � ���� ��� �����������
  for(int i=0 ; i<list->Count(); i++)
  {
    file->write(list->Items(i)->name,strlen(list->Items(i)->name));
    file->write("\n",1);
  }
  
  //� �������� ������� ��������� -1, ��� ����� ������������� ����� ������ strlen � ������� write
  file->write("--------------------\n",-1);

  //������� ������ ������� � ������ ("2.second");
  list->Delete(0,1);
  
  //����� ���������
  LIST_STRUCT *ls = new LIST_STRUCT();
    ls->next = 0;
    ls->name = "2.Insert item =)";
  list->Insert(ls,1); //��������� ��������� �� ������ ������� 
 
  LIST_STRUCT *ch = new LIST_STRUCT();
    ch->next = 0;
    ch->name = "3.This is change text =)";  
  list->Change(ch,2);//�������� ��������� � ������� �������
  
  
  LIST_STRUCT *ls2 = new LIST_STRUCT();
    ls2->next = 0;
    ls2->name = "NEw items in end";
  list->Insert(ls2,list->Count());//��������� � ����� ����� �������,������������ add, ������ ��� ����� =)

  //���� ����� ���� ����� ���������� �������...
  list->Insert("NEw items in end22",list->Count());

  //���������� � ������ ������
  list->Insert("NEw items in start",0);
  
  //���������� � ���� ��� �����������
  for(int i = 0 ; i<list->Count(); i++)
  {
    file->write(list->Items(i)->name,strlen(list->Items(i)->name));
    file->write("\n",1);
  }  

  file->close();//��������� �����, ��� �� ����� ������������ ��� �������� � �����������,����� ������ =)
  file->execute();//��������� ����
  */
  //�������...:)
  //delete qlist;
//  delete l;
  //delete file;  
  return 0;
}
