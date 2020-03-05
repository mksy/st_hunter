#include <swilib.h>


/*

  ���� �� �� ������ ������������ libcrt.a � ������ ����������
  � ��� ����� ������������� ������ ���� ��:

  1. ��� ����������� ������ �������, ������� ����� � ����� �������
  2. ������ main ������������ _start ���� � ��������� ������� �������� -emain
  3. �� ������������ kill_elf(), � ������������ ����������� ������� ��������� ����(����� ��� �� ����)
  4. ������������ ������ __NO_DIRECT_SWI(����� ������������� �������� swi, ����� � ������������ ��� ����� ������������ ���.
          ���� http://team-sc.ru/down/gcc_462_swi_call_siemens2patch_130.zip �� Barracuda)
  5. ������������ ������ __NO_LIBC
  6. ������������ ���� -fno-builtin ( � ���� ������ ��� �� ����� ��������� ������� ���������� �� *.so (memcpy memset etc...) )
  7. �� ������������ ���� --defsym __ex=0

*/


/* ����� �� ��� � ��� kill_data */
__attribute__((naked))
void kill_data(void *p, void (*func_p)(void *))
{
    asm ("bx  %1\n" :: "r"(p), "r"(func_p));
}


void Exit()
{
    /* ����� ����� �� ����� �����, ���������� � ������� */
    extern unsigned __executable_start;

    /*
        ldr r0, =__executable_start
        bx  kill_data
    */
    kill_data(&__executable_start, (void (*)(void *))mfree_adr());
}


int _start(char *exename, char *fname)
{
    char tmp[26];
    int cleaned = 0;

    cleaned = dlclean_cache();

    if(cleaned == -1)
        sprintf(tmp, "��� ����", cleaned);
    else
        sprintf(tmp, "������� %d ���������", cleaned);
    ShowMSG(1, (int)tmp);

    SUBPROC(Exit);
    return 0;
}
