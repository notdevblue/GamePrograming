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



	static	DWORD WINAPI	clientThreadLaunch(LPVOID lpParam); // <= TODO : 스레드 헨들을 배열로 만들었으니 이 함수를 같이 사용하게 할 수 있을까
			DWORD			clientThread(LPVOID lpParam);


public:
	Server();
	~Server();

	void listenClients();


	

};
