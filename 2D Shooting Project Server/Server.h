#pragma once
#include <Windows.h>

#define CLIENT_COUNT 2

class Server
{
private:

	HANDLE* hThreads;
	SOCKET* sClients;


public:


	Server();
	~Server();



	

};
