#ifndef _ICQSOCKET_H
#define _ICQSOCKET_H

//#include "include.h"
#include "mem.h"
#include "socket.h"
#include "dns.h"
#include "log.h"

class SocketAbstract;

class SocketDNR: public DNR
{
public:
  virtual void onResolve(DNR_RESULT_MSG result_msg, int value);
  void Bind(SocketAbstract * sock);
  SocketDNR();
private:
  SocketAbstract * Callback;
};

class SocketAbstract: public Socket
{
public:
  virtual void onCreate(); // �������� ������
  virtual void onDataRead(); // ��������� ������
  virtual void onConnected(); // ����������
  virtual void onClose(); // �������� ������
  virtual void onRemoteClose(); // ��������� ��������
  virtual void onError(SOCK_ERROR err); // ���������� ������
  
 
//  virtual void onSocketConnect() = 0; // ���������� ��� ����������
//  virtual int onSocketHeaders() = 0; // ��������� ��������� HTTP
//  virtual void onSocketData(char * data, int size) = 0; // ��������� ��������� ������ (���������� � ����)
//  virtual void onSocketStopped() = 0; // ���������
//  virtual void onSocketFinish() = 0; // ��������� �������
  
  void onResolve(DNR_RESULT_MSG result_msg, int value);
  
  void Start(int ip, short port); // ���������� �� IP
  void Start(const char * host, short port); // ���������� �� ����� �����
  
  void doConnect();
  
  SocketAbstract();
  ~SocketAbstract();
  
  Buffer * req_buf; // ����� �������
  
private:
  int ip; // IP
  short port; // ����
  Buffer * recv_buf; // ����� ������
  SocketDNR * Resolver; // ��������
};





#endif 

