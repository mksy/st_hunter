// ������������ ���� ;)

void RunIdlePanel()
{
  if ( NumOfItems_idle > 0)
  {
    IdleMenuActive=1;
    DrawIdleMenu();
  }
  else EditConfig();
}

int IDLE_KeyHook(int submsg, int msg)// ��� ���, ����������� �� IDLE.
{
  CSM_RAM *data=FindCSMbyID(CSM_root()->idle_id);
  if(IsGuiOnTop(idlegui_id)) //���� IdleGui �� ����� �����
  {
    GUI *igui=GetTopGUI();
    if (igui) //� �� ����������
    {
#ifdef ELKA
      {
#else
      void *idata=GetDataOfItemByID(igui,2);
      if (idata)
      {
#endif
        if((IsUnlocked())&&(!FastRunMenuActive))
        {
          if((!IDLE_CALL_BUTTON)&&(!IDLE_EXIT_BUTTON))
          {
            if ((msg==KEY_DOWN)||(msg==LONG_PRESS))// ���� ������� ������ ��� ������
            {
              switch(submsg)
              {
                case UP_BUTTON:// ���� �����
                   if (!IDLE_GORIZ) {
                  Selected_idle--;// ������ �����
                  if(Selected_idle<0)
                    Selected_idle=NumOfItems_idle-1; // ���� ������ � ������, ������������ � �����
                  DrawIdleMenu(); // � �������������� ���� ������
                   }
                  return (2); 
       
                case DOWN_BUTTON:// ���� ������
                   if (!IDLE_GORIZ) {
                  Selected_idle++;// ������ ������
                  if(Selected_idle >= NumOfItems_idle)
                    Selected_idle=0;// ���� ��������� � �����, ������� � ������
                  DrawIdleMenu(); // ����� ��������������
                   }
                  return (2);
                  
                  case LEFT_BUTTON:// ���� �����
                   if (IDLE_GORIZ) {
                  Selected_idle--;// ������ �����
                  if(Selected_idle<0)
                    Selected_idle=NumOfItems_idle-1; // ���� ������ � ������, ������������ � �����
                  DrawIdleMenu(); // � �������������� ���� ������
                   }
                  return (2); 
       
                case RIGHT_BUTTON:// ���� ������
                   if (IDLE_GORIZ) {
                  Selected_idle++;// ������ ������
                  if(Selected_idle >= NumOfItems_idle)
                    Selected_idle=0;// ���� ��������� � �����, ������� � ������
                  DrawIdleMenu(); // ����� ��������������
                   }
                  return (2);
                case ENTER_BUTTON:// ������ �� ����
                  IdleMenuActive=0;
                  RunAction(Selected_idle,1);// � ��������� ���������� ��������
                  return (2);
              }
            }
          }
          else
          {
            if(IdleMenuActive)
            {
              if (!CONFMenuActive) {
              if ((msg==KEY_DOWN)||(msg==LONG_PRESS))// ���� ������� ������ ��� ������
              {
              if (submsg==IDLE_EXIT_BUTTON)// ������ �������� ������. ��� ��� ��� ����
              {
                switch (msg)
                {
                  case KEY_DOWN:
                    IdleMenuActive=0;
                    PendedRedrawGUI();
                    DrawIdleMenu();
                    return (2);
                    
                  case LONG_PRESS:
                    return (2);
                }
              }
                
                
                switch(submsg)
                {
                  case UP_BUTTON:// ���� �����
                  case '2':
                     if (!IDLE_GORIZ) {
                    Selected_idle--;// ������ �����
                    if(Selected_idle<0)
                      Selected_idle=NumOfItems_idle-1; // ���� ������ � ������, ������������ � �����
                    
                    DrawIdleMenu(); // � �������������� ���� ������
                     }
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case DOWN_BUTTON:// ���� ������
                  case '8':
                     if (!IDLE_GORIZ) {
                    Selected_idle++;// ������ ������
                    if(Selected_idle >= NumOfItems_idle)
                      Selected_idle=0;// ���� ��������� � �����, ������� � ������
                    DrawIdleMenu(); // ����� ��������������
                     }
                    return (2);
  
                  case LEFT_BUTTON:// ���� �����
                  case '4':
                     if (IDLE_GORIZ) {
                    Selected_idle--;// ������ �����
                    if(Selected_idle<0)
                      Selected_idle=NumOfItems_idle-1; // ���� ������ � ������, ������������ � �����
                    DrawIdleMenu(); // � �������������� ���� ������
                     }
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case RIGHT_BUTTON:// ���� ������
                  case '6':
                     if (IDLE_GORIZ) {
                    Selected_idle++;// ������ ������
                    if(Selected_idle >= NumOfItems_idle)
                      Selected_idle=0;// ���� ��������� � �����, ������� � ������
                    DrawIdleMenu(); // ����� ��������������
                     }
                    return (2);                    
                    
                  // ������ �� ����
                  case '5':
                  case ENTER_BUTTON:  
                     PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    RunAction(Selected_idle,1);// � ��������� ���������� ��������
                    IdleMenuActive=0;                    
                    return (2);
        
                  case '#':
                     PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    IdleMenuActive=0;
                    EditConfig();
                    return (2);
        
                    case '*':
                     PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    CONFMenuActive=1;

                    return (2);
                    
                  case '0':
                     PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    ShowMSG(2,(int)LG_COPYRIGHT);
                    return (2);
                }
              }

              return (2);
              } else {
                
              if (msg==KEY_DOWN){// ���� ������� ������
             
                
                switch(submsg)
                {
                  case UP_BUTTON:// ���� �����
                    ClearIdleMenu();
                    if (y1>0) y1=y1-1;          
                    DrawIdleMenu(); // � �������������� ���� ������
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case DOWN_BUTTON:// ���� ������
                    ClearIdleMenu();
                    y1=y1+1;                   
                    DrawIdleMenu(); // ����� ��������������
                    return (2);
  
                  case LEFT_BUTTON:// ���� �����
                    ClearIdleMenu();
                    if (x1>0) x1=x1-1;   
                    DrawIdleMenu(); // � �������������� ���� ������
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case RIGHT_BUTTON:// ���� ������
                    ClearIdleMenu();
                    x1=x1+1;                    
                    DrawIdleMenu(); // ����� ��������������
                    return (2);                    
                    
                  // ������ �� 5
                  case '5': 
                    ClearIdleMenu();                    
                    if (IDLE_GORIZ) IDLE_GORIZ=0; else IDLE_GORIZ=1;
                    DrawIdleMenu();
                    return (2);                    
                   case '1': 
                    ClearIdleMenu();                    
                    if (!P) K++; else K--;
                    DrawIdleMenu();
                    return (2);                     
                   case '3': 
                    ClearIdleMenu();                    
                    if (!P) K--; else K++;
                    DrawIdleMenu();
                    return (2);   
                    case '4': 
                    ClearIdleMenu();                    
                    if (!P) M++; else M--;
                    DrawIdleMenu();
                    return (2);                     
                   case '6': 
                    ClearIdleMenu();                    
                    if (!P) M--; else M++;  
                    DrawIdleMenu();
                    return (2);     
                   case '2': 
                    ClearIdleMenu();                    
                    N--; if (N>255) N=255;
                    DrawIdleMenu();
                    return (2);                     
                   case '8': 
                    ClearIdleMenu();                    
                    N++; if (N>255) N=255;
                    DrawIdleMenu();
                    return (2); 
                    
                    
                    
                    
                  case '*':
                    PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    CONFMenuActive=0;
                    IdleMenuActive=0;    
                    saveconf();
                    return (2);
                }
              } 
              if (msg==LONG_PRESS)// ���� ������� ������
              {
             
                
                switch(submsg)
                {
                  case UP_BUTTON:// ���� �����
                    ClearIdleMenu();
                    
                    if (y1>4) y1=y1-5;  
                    DrawIdleMenu(); // � �������������� ���� ������
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case DOWN_BUTTON:// ���� ������
                    ClearIdleMenu();
                    y1=y1+5;                   
                    DrawIdleMenu(); // ����� ��������������
                    return (2);
  
                  case LEFT_BUTTON:// ���� �����
                    ClearIdleMenu();
                    if (x1>4) x1=x1-5;        
                    DrawIdleMenu(); // � �������������� ���� ������
                    return (2); // ���������� 2, ����� ������ ������ ������ �� ���������...
       
                  case RIGHT_BUTTON:// ���� ������
                    ClearIdleMenu();
                    x1=x1+5;                    
                    DrawIdleMenu(); // ����� ��������������
                    return (2);                    
                   case '1': 
                    ClearIdleMenu();                    
                    if (!P) K++; else K--;
                    DrawIdleMenu();
                    return (2);                     
                   case '3': 
                    ClearIdleMenu();                    
                    if (!P) K--; else K++;
                    DrawIdleMenu();
                    return (2);   
                    case '4': 
                    ClearIdleMenu();                    
                    if (!P) M++; else M--;
                    DrawIdleMenu();
                    return (2);                     
                   case '6': 
                    ClearIdleMenu();                    
                    if (!P) M--; else M++; 
                    DrawIdleMenu();
                    return (2);  
                    case '2': 
                    ClearIdleMenu();                    
                    N--; if (N>255) N=255;
                    DrawIdleMenu();
                    return (2);                     
                   case '8': 
                    ClearIdleMenu();                    
                    N++; if (N>255) N=255;
                    DrawIdleMenu();
                    return (2); 
                  // ������ �� ����
  
                  case '*':
                    PlaySound(1 ,0 ,0 ,SOUND_11,0);// ��� n- ����� �����.�����
                    CONFMenuActive=0;
                    IdleMenuActive=0;                    
                    return (2);
                }
              }

              return (2);
              }
              
            }
            else
            {
              if (submsg==IDLE_CALL_BUTTON)
              {
                switch(msg)
                {
                  case KEY_DOWN:
                    if (!ENA_IDLE_LONGPRESS)
                      RunIdlePanel();
                    else
                    {
                      if (mode_enter==2)
                      {
                        GBS_SendMessage(MMI_CEPID,KEY_UP,IDLE_CALL_BUTTON);
                        return (0);
                      }
                      mode_enter=0;
                    }
                    return (2);
                    
                  case KEY_UP:
                    if (ENA_IDLE_LONGPRESS)
                    {
                      if (mode_enter==0)
                      {
                        mode_enter=2;
                        GBS_SendMessage(MMI_CEPID,KEY_DOWN,IDLE_CALL_BUTTON);
                        return (2);
                      }
                      if (mode_enter==2)
                      {
                        mode_enter=0;
                        return (0);
                      }
                      mode_enter=0;
                    }
                    return (2);
                  case LONG_PRESS:
                    if (ENA_IDLE_LONGPRESS)
                    {
                      mode_enter=1;
                      RunIdlePanel();
                    }
                    break;
                }
              }
            }
          }
        }
      }
    }
  }
  return (0);
}

int FastRun_KeyHook(int submsg, int msg)// ����� ������ FastRun
{
if((IsUnlocked())&&(!FastRunMenuActive))
{
    if (submsg==FR_CALL_BUTTON)
    {
      switch(msg)
      {
        case KEY_DOWN:
          if (!ENA_FR_LONGPRESS)
          {
            RunFastRunPanel();//RunFastRunPanel();
            return(2);
          }
          else
          {
            if (mode_enter==2)
            {
              GBS_SendMessage(MMI_CEPID,KEY_UP,FR_CALL_BUTTON);
              return (0);
            }
            mode_enter=0;
            return (2);
          }
          
        case KEY_UP:
          if (ENA_FR_LONGPRESS)
          {
            if (mode_enter==0)
            {
              mode_enter=2;
              GBS_SendMessage(MMI_CEPID,KEY_DOWN,FR_CALL_BUTTON);
              return (2);
            }
            if (mode_enter==2)
            {
              mode_enter=0;
              return (0);
            }
            mode_enter=0;
            return (2);
          }
          
        case LONG_PRESS:
          if (ENA_FR_LONGPRESS)
          {
            mode_enter=1;
            RunFastRunPanel();//RunFastRunPanel();
          }
          break;
      }
    }
  }
return(0); 
}
