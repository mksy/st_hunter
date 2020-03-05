#include "..\inc\cfg_items.h"
#include "..\inc\swilib.h"

#ifdef NEWSGOLD
#define DEFAULT_DISK "4"
#else
#define DEFAULT_DISK "0"
#endif

//����������
__root const CFG_HDR cfghdr0 = {CFG_RECT, "Data Area", 0, 0};
__root const RECT DATA_AREA = {0,180,180,280};

__root const CFG_HDR cfghdr61={CFG_CHECKBOX,"Show City",0,0};
__root const int SHOW_CITY = 0;

__root const CFG_HDR cfghdr62={CFG_CHECKBOX,"Show Area",0,0};
__root const int SHOW_AREA = 0;

__root const CFG_HDR cfghdr66={CFG_CHECKBOX,"Show Country",0,0};
__root const int SHOW_COUNTRY = 0;
