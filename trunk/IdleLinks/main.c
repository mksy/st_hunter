#include <swilib.h>
#include "conf_loader.h"
#include "nsd.h"
#include "conf_ex.h"

void ElfKiller(void)
{
	kill_elf();
}

int main(void)
{
	if (CreatePathToBcfgs() == 1) // ���� ���� (���  ���������) �������� � etc
	{
		InitConfig(); // ��������� �������� ������
		LoadBcfgs(); // ��������� ������� � ���������
		NSD_Create(); // ������� NSD ������
	}
	else
	{
		ShowMSG(1, (int)"Error creating '?:\\Zbin\\etc\\IdleLinks' folder!"); // ��������� ���������
	}
	return 0;
}
