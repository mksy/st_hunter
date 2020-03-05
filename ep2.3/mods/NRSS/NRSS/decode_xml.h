#ifndef _DECODE_XML_H_
  #define _DECODE_XML_H_


typedef struct{
  void *next;
  char *name;
  char *param;
}XMLAttr;


typedef struct{
  void *next;
  void *subnode;
  char *name;
  XMLAttr *attr;
  char *value;
}XMLNode;

// ������������ �����
XMLNode *XMLDecode(char *buf, int size);

// ���������� ������
void DestroyTree(XMLNode *tmpp);

enum XML_MAINSTATE{
  MS_BEGIN=1,                 //< ������ ��������
  MS_BEGINTAG,                //< ������� ���
  MS_MIDDLETAG,               //< �������� ����, �� ��� �� �����
  MS_TAGNAME,                 //< ������ ��� ����
  MS_ENDTAGNAME,              //< ��������� ������� ��� ����
  MS_ATTRIBNAME,              //< ������ ��� ���������
  MS_ENDATTRIBNAME,           //< ��������� ��� ���������
  MS_ENDEQUALLY,              //< ������ ���� = ����� ������ ��������� � ���������
  MS_ATTRIBVALUE,             //< ������ �������� ��������� (����� ")
  MS_ENDTAG,                  //< ����� ���� (��� ������������������ ����� /)
  MS_TEXT,                    //< �����
  MS_CHECK_DECL,
  MS_CDATA_SECTION
};

enum XML_TAGSTATE{
  TS_INDEFINITE=1,            //< ��������������, �.�. ��� ������ ������ ������� (���� ������)
  TS_NORMAL,                  //< ������� (��)�������������. ����� �� ����������
  TS_CLOSE,                   //< �������������
  TS_EMPTY,                   //< ��� � �����������
  TS_DECLARATION              //< ����������, ��� ��� XML. ������ ��������� ����������
};

#endif
