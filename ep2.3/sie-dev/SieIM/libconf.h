
typedef struct
{
// dbg lib
   const int Debug;	// ������� �� ����� ����
   const char  Path[128];	// ���� � ����� ����
// gprs lib
   const int trafic_size;		//
   const int trafic_gold;		//
   const int trafic_silver;	//
   const int trafic_blur;		//
   const char text_valute[64];	//  ������������ ������
   const int LIMIT_TRAF_ACTIVE;	// �������� �� ����������� �������
   const int LIMIT_TRAF_KB;	//  ����������� ������� � ��
   const int LIMIT_TRAF_SEC;  // ����������� ������� � ��������
   const int session_time_enable;	// ������� �� ����� ������
// mes lib
   const int TypeMes;	// ��� ���������
}


