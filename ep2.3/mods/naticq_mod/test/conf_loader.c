#include "..\inc\swilib.h"
#include "..\inc\cfg_items.h"
#include "conf_loader.h"

const char *successed_config_filename="";




#pragma segment="CONFIG_C"
int SaveConfigData(const char *fname)
{
  int f;
  unsigned int ul;
  int result=-1;
  unsigned int wlen;
  unsigned int len=(char *)__segment_end("CONFIG_C")-(char *)__segment_begin("CONFIG_C");

  if ((f=fopen(fname,A_WriteOnly+A_BIN+A_Create+A_Truncate,P_WRITE,&ul))!=-1)
  {
    wlen=fwrite(f,__segment_begin("CONFIG_C"),len,&ul);
    fclose(f,&ul);
    if (wlen==len) result=0;
  }
  return(result);
}

/*
#pragma segment="CONFIG_C"
int LoadConfigData(const char *fname)
{
  int f;
  unsigned int ul;
  char *buf;
  int result=0;
  void *cfg;
  unsigned int rlen, end;

  extern const CFG_HDR cfghdr0; //first var in CONFIG
  cfg=(void*)&cfghdr0;

  unsigned int len=(int)__segment_end("CONFIG_C")-(int)__segment_begin("CONFIG_C");

  if (!(buf=malloc(len))) return -1;
  if ((f=fopen(fname,A_ReadOnly+A_BIN,P_READ,&ul))!=-1)
  {
    rlen=fread(f,buf,len,&ul);
    end=lseek(f,0,S_END,&ul,&ul);
    fclose(f,&ul);
    if (rlen!=end || rlen!=len)  goto L_SAVENEWCFG;
    memcpy(cfg,buf,len);
  }
  else
  {
  L_SAVENEWCFG:
    result=SaveConfigData(fname);
  }
  mfree(buf);
  if (result>=0) successed_config_filename=fname;
  return(result);
}

void InitConfig()
{
#ifdef kluchnik2
  if (LoadConfigData("4:\\ZBin\\etc\\NATICQMod3.bcfg")<0)
  {
    LoadConfigData("0:\\ZBin\\etc\\NATICQMod3.bcfg");
  }
#else
#ifdef kluchnik
  if (LoadConfigData("4:\\ZBin\\etc\\NATICQMod2.bcfg")<0)
  {
    LoadConfigData("0:\\ZBin\\etc\\NATICQMod2.bcfg");
  }
#else
  if (LoadConfigData("4:\\ZBin\\etc\\NATICQMod.bcfg")<0)
  {
    LoadConfigData("0:\\ZBin\\etc\\NATICQMod.bcfg");
  }
#endif
#endif
}
*/
int LoadConfigData(const char *fname, void* cfg, int len)
{
  int f;
  unsigned int ul;
  int result=-1;
  
  if ((f=fopen(fname,A_ReadOnly+A_BIN,P_READ,&ul))!=-1)
  {
    if (fread(f,cfg,len,&ul)==len)
    {
      fclose(f,&ul);
      result = 0;
    }
    else
    {
      fclose(f,&ul);
    }
  }
#ifdef BCFGGEN
  if (result == -1)
  {
    extern const CFG_HDR cfghdr0; //first var in CONFIG
    void* bcfg=(void*)&cfghdr0;
    unsigned int lenbcfg=(int)__segment_end("CONFIG_C")-(int)__segment_begin("CONFIG_C");
    if ((f=fopen(fname,A_ReadWrite+A_Create+A_Truncate,P_READ+P_WRITE,&ul))!=-1)
    {
      if(fwrite(f,bcfg,lenbcfg,&ul)==len)
      {
        memcpy(cfg,bcfg,len);
        result=0;
      }
      fclose(f,&ul);
    }
  }
#endif
  return(result);
}


char *config_path=":\\zbin\\etc";
int InitConfig(void* cfgstruct, int len, char *name,int disk)
{
  int result;
  char config_name[128];
  sprintf(config_name, "%d%s\\%s.bcfg", disk, config_path,name);
  result = LoadConfigData(config_name,  cfgstruct, len);
  return result;
}
