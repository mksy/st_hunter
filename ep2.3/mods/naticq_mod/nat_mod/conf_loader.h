/*
��������� ������������
(c) Rst7, Kibab
 ������������ �������� ������� � ������������� ������� �������������
*/
#ifndef _CONFLOADER_H_
  #define _CONFLOADER_H_

// ������� ����������� ����� ���������� � ���������� ������������
//void InitConfig();
int InitConfig(void* cfgstruct, int len, char *name,int disk);

extern const char *successed_config_filename;
int SaveConfigData(const char *fname);

#endif
