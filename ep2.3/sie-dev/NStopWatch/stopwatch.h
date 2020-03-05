#ifndef _STOPWATCH_H_
  #define _STOPWATCH_H_

#define SIX_SEC 1300

typedef struct
{
    TTime *data;
    int total;
}RESULTS;

void StopWatch_Start(void);  //����� �����������
void StopWatch_Stop(void);           //��������� �������
unsigned int IsStart(void);          //�������� �� ����������
void Results_Rem(void);//���������� �����������
void Results_Free(void);   //������� �����������

extern TTime time;
extern RESULTS res;
#endif
