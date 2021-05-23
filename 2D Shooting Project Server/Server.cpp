#include "Server.h"
#include <iostream>


Server::Server()
{
	std::cout << "Server started." << std::endl;

	hThreads = (HANDLE*)malloc(sizeof(HANDLE) * CLIENT_COUNT);
	sClients = (SOCKET*)malloc(sizeof(SOCKET) * CLIENT_COUNT);
}


Server::~Server()
{
	free(hThreads);
	free(sClients);


	std::cout << "Server is offline." << std::endl;

}