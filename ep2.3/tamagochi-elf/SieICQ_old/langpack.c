#include "include.h"
#include "langpack.h"


int loaded = NULL;

extern char elf_path[256];

void LoadLanguage()
{
  FreeLanguage();
  loaded = NULL;
  volatile int hFile;
  unsigned int io_error = 0;
  char * buf; // ����� ��� ����
  char line[128]; // ������� ������
  int line_size = 0; // ����� ������� ������
  int cur_id=0; // ������� LGP_ID
  int buf_pos = 0; // ������� � ������
  FSTATS fstat;
  char * lang_file =  malloc(256);
  sprintf(lang_file,"%s\\lang.txt",elf_path);
  if (GetFileStats(lang_file, &fstat, &io_error)!=-1) // �������� ������ �����
  {
    if((hFile=fopen(lang_file, A_ReadOnly + A_BIN, P_READ, &io_error))!=-1) // ��������� ���� ��� ������
    {
      if (buf = malloc(fstat.size+1)) // �������� ������ ��� �����
      {
        buf[fread(hFile, buf, fstat.size, &io_error)]=0; // ������ ���� � �����

        while(buf[buf_pos] && buf_pos < fstat.size && cur_id < LGP_DATA_NUM) // ���� �� ����� ����� � �� ��������� ��� ���� �������
        {
          if (buf[buf_pos]=='\n' || buf[buf_pos]=='\r') // ���� ����� ������
          {
            if (line_size) // ���� ����� ������ > 0
            {
              LangPack[cur_id] =malloc(line_size + 1); // �������� ������ � ������� ��� ������
              memcpy(LangPack[cur_id], line, line_size); // �������� ������ � ������
              LangPack[cur_id][line_size] = NULL; // ����� ������
              cur_id ++;
              line_size = NULL;
            }
          }
          else
            line[line_size++]=buf[buf_pos]; // ��������� � ������ ������� �� ������, ���� �� ����� �����
          buf_pos++;
        }
        if (line_size && cur_id < LGP_DATA_NUM) // eof
        {
          LangPack[cur_id] = malloc(line_size + 1);
          memcpy(LangPack[cur_id], line, line_size);
          LangPack[cur_id][line_size] = NULL;
          cur_id ++;
          line_size = NULL;
        }
        mfree(buf); // ������� �����. �� ��� ��� �� �����������
        loaded = 1;
        fclose(hFile, &io_error);
        for (int i = 0; i < LGP_DATA_NUM; i ++)
        {
          if (!LangPack[i])
          {
            LangPack[i] = malloc(64);
            strcpy(LangPack[i], "Error! Update lang.txt!");
          }
        }
        return;
      }
      fclose(hFile, &io_error);
    }
  }
  mfree(lang_file);
  // ���� �� �����-�� �������� ���� ������ ���������, �� ������������� ���������� �������
// ����  
  LangPack[LGP_Connect] = "Connect";
  LangPack[LGP_SetStatus] = "Change status";
  LangPack[LGP_CList] = "Contact list";
  LangPack[LGP_Option] = "Options";
  LangPack[LGP_About] = "About";
  LangPack[LGP_Exit] = "Exit";
//  


}

void FreeLanguage()
{
  if (loaded)
  {
    for (int i = 0; i < LGP_DATA_NUM; i ++)
      mfree(LangPack[i]);
  }
  else
  {
    for (int i = 0; i < LGP_DATA_NUM; i ++)
       LangPack[i] = NULL;
  }
  loaded = NULL;
}
