#include "Server.h"
#include <iostream>

#pragma region Constructor, Destructor

Server::Server()
{
	std::cout << "Server started." << std::endl;

	hThreads		= (HANDLE*)		malloc(sizeof(HANDLE)		* CLIENT_COUNT);
	clientDataArr	= (SOCKADDR_IN*)malloc(sizeof(SOCKADDR_IN)  * CLIENT_COUNT);
	clientDataSize  = (INT*)		malloc(sizeof(INT)			* CLIENT_COUNT);
	sClients		= (SOCKET*)		malloc(sizeof(SOCKET)		* CLIENT_COUNT);

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
	free(hThreads);
	free(sClients);
	free(clientDataArr);
	free(clientDataSize);

	std::cout << "Server is offline." << std::endl;

}

#pragma endregion


