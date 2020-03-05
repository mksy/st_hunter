// ��������

int RunAction(int bm, int mode)//bm-����� ��������, mode-��� (0-FastRun, 1-IDLE, 2-FastRun 2 panel,3-ThirdPanel)
{
 const char *s;
 if (mode==0) 
 {
  FASTRUN_1 *fl;
  fl=FindByN_1(bm);
  s=fl->action;
 }
 
 if (mode==1) 
 {
  FASTRUN_IDLE *fl;
  fl=FindByN_IDLE(bm);
  s=fl->action;
 }
 
 if (mode==2)
 {
  FASTRUN_2 *fl;
  fl=FindByN_2(bm);
  s=fl->action;
 } 
 if (mode==3)
 {
  FASTRUN_3 *fl;
  fl=FindByN_3(bm);
  s=fl->action;
 }
  
 if((s)&&strlen(s))
 {
  if ((s[2]=='\\')&&((s[(strlen(s))-3]=='.')||//��������� ������ �� ������� �������� '\\' � '.'
     (s[(strlen(s))-4]=='.')||(s[(strlen(s))-5]=='.')))
     /* ���� � ������ ���� ������� '\\' � '.', �� ��������� ��� ������� ����*/
      {
        WSHDR *ws;
        ws=AllocWS(256);
        str_2ws(ws,s,256);
        CutWSTR(ws,strlen(s)-1);//���� � ������� �������,������� ���������� ������ ��� ���� ���...
        ExecuteFile(ws,0,0);
        FreeWS(ws);
        return(1);
       }
  if ((s[2]!='\\')&&(s[(strlen(s))-3]!='.')&&
     (s[(strlen(s))-4]!='.')&&(s[(strlen(s))-5]!='.')&&
     (s[0]!='a')&&(s[0]!='A')&&(s[1]!='0'))
    /* ���� � ������ ��� �������� '\\' � '.' � ������ ��� ������� �� �0,
       �� ��������� ������� */
      {
        /*typedef void (*voidfunc)(); 
        voidfunc pp=(voidfunc)GetFunctionPointer((char*)s); 
        if(pp!=0) SUBPROC((void*)pp);*/
        unsigned int* addr = (unsigned int*)GetFunctionPointer((char*)s); 
        if (addr)
        {
          typedef void (*voidfunc)(); 
          #ifdef NEWSGOLD 
            voidfunc pp=(voidfunc)*(addr+4);
          #else 
            voidfunc pp=(voidfunc)addr; 
          #endif 
            SUBPROC((void*)pp);
        }
      }
  if ((s[2]!='\\')&&(s[(strlen(s))-3]!='.')&&
     (s[(strlen(s))-4]!='.')&&(s[(strlen(s))-5]!='.')&&
     ((s[0]=='a')||(s[0]=='A'))&&(s[1]=='0'))
    /* ���� � ������ ��� �������� '\\' � '.' � ������ ��� ������� �0,
       �� ��������� ���������� */
      {
        int entry;
        sscanf(s,"%08X",&entry);
        SUBPROC((void*)entry);
      }
 }
 return(0);
}

