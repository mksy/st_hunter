#include <swilib.h>
#include <conf_loader.h>
#include <cfg_items.h>

/** ��������� ������� ��� ���
 * (�) Z.Vova
 */

// �� ������ ���� ��������� ��������
//__CFG_BEGIN(1)
//__CFG_BEGIN(2)
// � ��� �����

__CFG_BEGIN(0)

 __root const CFG_HDR cfghdr0 = {CFG_STR_UTF8, "��������� �", 3, 127};
 __root const char save_to[128]="0:\\Misc\\class\\";

 __root const CFG_HDR cfghdr1 = {CFG_UINT, "������", 0, 0xFFFFFFFF};
 __root const int key_hot = 13;

 __root const CFG_HDR cfghdr2 = {CFG_CHECKBOX, "������� �������", 0, 2};
 __root const unsigned int islong = 0;

 __root const CFG_HDR cfghdr3={CFG_CBOX, "������", 0, 2};
 __root const int format = 0;
 __root const CFG_CBOX_ITEM cfgcbox1[2]={"png","jpeg"};

 __root const CFG_HDR cfghdr4 = {CFG_UINT, "�������� jpeg", 0, 100};
 __root const unsigned int quality = 100;

 __root const CFG_HDR cfghdr5={CFG_CBOX, "����������", 0, 5};
 __root const int notification = 0;
 __root const CFG_CBOX_ITEM cfgcbox2[5]={"����","���������", "�����", "�������� ����������", "������"};

 __root const CFG_HDR cfghdr6 = {CFG_CHECKBOX, "���������� � ����", 0, 2};
 __root const unsigned int is_idle_save = 0;


__CFG_END(0)



/** ������ ������ �� config_data.c
  * Properties -> Advanced -> Use custom command to build this file
  * ������ �������
  * ��������� ���� $compiler $options -xc $includes -c $file -o $object -O0
*/
