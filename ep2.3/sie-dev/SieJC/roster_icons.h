/*
    SieNatJabber Project
    ������� ��������� ������ �������
*/


// ������ �������� � ������� �� �������� �����������
void Roster_DrawIcon(unsigned short x, unsigned short y, unsigned int img_num);
// ������ "�������" � ����������� �������
int Roster_getIconWidth(char* path_to_pic);
int Roster_getIconHeight(char* path_to_pic);

// �������� ����� ��������
void Roster_getIcon(char* path_to_pic, CLIST* ClEx, TRESOURCE* resEx);
//�������� �������� �� png
void Roster_fillIcons();

//������ ����� �������� �� �������
char* Roster_getIconByStatus(char* path_to_pic, char status);
