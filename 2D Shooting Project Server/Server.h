#pragma once
#include <Windows.h>

#define CLIENT_COUNT 2
#define PORT 56789

class Server
{
private:
	WSADATA wsaData;


	HANDLE*		 hThreads;
	SOCKET		 sListening;
	SOCKET*		 sClients;
	INT*		 clientDataSize;
	SOCKADDR_IN  serverData;
	SOCKADDR_IN* clientDataArr;



	static	DWORD WINAPI	clientThreadLaunch(LPVOID lpParam); // <= TODO : ������ ����� �迭�� ��������� �� �Լ��� ���� ����ϰ� �� �� ������
			DWORD			clientThread(LPVOID lpParam);


public:
	Server();
	~Server();

	void listenClients();


	

};
