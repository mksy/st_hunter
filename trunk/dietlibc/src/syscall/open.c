
/**
    * 2011
    * (c) Z.Vova
*/


#include <fcntl.h>
#include <swilib.h>
#include <errno.h>


static inline int getfilesize(const char *file)
{
    FSTATS ft;
    if(GetFileStats(file, &ft, 0)  == -1) return -1;
    return ft.size;
}


int open(const char *file, int flags, ...)
{
    int flag = 0, mode = P_READ, i = 0, sgold = (isnewSGold() == 0), fsz = 0;
    unsigned int err;

    /* ������� ��� ������-�����-���, � ������ �������� �� ������������ ������� ����� */
    /* ���� ������ ������������ ��������� ���� */
    fsz = getfilesize(file);

    /* ������ ������ */
    if( flags & O_WRONLY ) flag |= A_WriteOnly;

    //���� MMC � SGold-���������, �� ������/������ � ����� ������
    if( sgold && file[0] == '4' ) flag = A_ReadWrite;

    /* ������/������ */
    //���� MMC � SGold-���������, �� ������ ������� �� �����
    if( flags & O_RDWR ) flag |= A_ReadWrite;

    /* ������� ���� ���� �� ���������� */
    if( flags & O_CREAT ) flag |= A_Create;

    /* �� :-D */
    if( flags & O_EXCL ) flag |= A_Exclusive;

    /* �������� ���� */
    if( flags & O_TRUNC && fsz > 0 ) flag |= A_Truncate;

    /* ���������� � ����� */
    if( flags & O_APPEND ) flag |= A_Append;

    if( flag & A_WriteOnly || flag & A_ReadWrite ) mode |= P_WRITE;

    if( !(flags & A_TXT) )
        flag |= A_BIN;

    i = _open(file, flag, mode, &err);
    if(i == -1)
    __set_errno(ENOENT);
    //errno = 0;
    return i;
}




