#include "Server.h"
#include <iostream>

#pragma region Constructor, Destructor

Server::Server()
{
	std::cout << "Server started." << std::endl;

	// 배열 동적 할당
	clientDataArr	= (SOCKADDR_IN*)malloc(sizeof(SOCKADDR_IN)  * CLIENT_COUNT);
	clientDataSize  = (INT*)		malloc(sizeof(INT)			* CLIENT_COUNT);
	sClients		= (SOCKET*)		malloc(sizeof(SOCKET)		* CLIENT_COUNT);

	// boost lib
	oa = new boost::archive::text_oarchive(ss);
	ia = new boost::archive::text_iarchive(ss);

	// 서버 리스닝 소켓 구조체
	serverData.sin_addr.s_addr	= INADDR_ANY;
	serverData.sin_port			= htons(PORT);
	serverData.sin_family		= AF_INET;


	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cerr << "Winsock Startup error. " << WSAGetLastError() << std::endl;
		exit(-1);
	}

	sListening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(sListening, (SOCKADDR*)&serverData, sizeof(serverData));

	for (int i = 0; i < CLIENT_COUNT; ++i)
	{
		clientDataSize[i] = sizeof(clientDataArr[i]);
	}
}

void Server::listenClients()
{
	for (int i = 0; i < CLIENT_COUNT; ++i)
	{
		listen(sListening, SOMAXCONN);

		sClients[i] = accept(sListening, (SOCKADDR*)&clientDataArr[i], &clientDataSize[i]);
		//inet_ntop(AF_INET, &addr.sin_addr, ip(ip를 담을 char 배열), INET_ADDRSTRLEN);
		// TODO : 스레드 생성
	}

}

DWORD WINAPI Server::clientThreadLaunch(LPVOID lpParam)
{
	Server* _this = (Server*)lpParam;
	return _this->clientThread(_this);	
}

Server::~Server()
{
	if (WaitForSingleObject(hThread, INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "Thread event object error." << std::endl;
	}

	delete ia;
	delete oa;

	free(sClients);
	free(clientDataArr);
	free(clientDataSize);

	std::cout << "Server is offline." << std::endl;

}

#pragma endregion


