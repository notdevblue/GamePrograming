#pragma once

// Packet serialization
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>

#include <WS2tcpip.h>
#include <Windows.h>

#pragma comment(lib, "ws2_32")

#define CLIENT_COUNT 2
#define BUFFER_SIZE 1024
#define PORT 56789

class Server
{
private:
	WSADATA		 wsaData;

	HANDLE		 hThread;
	HANDLE		 hSendThread;
	SOCKET		 sListening;
	SOCKET*		 sClients;
	INT*		 clientDataSize;
	SOCKADDR_IN  serverData;
	SOCKADDR_IN* clientDataArr;
	
	boost::archive::text_iarchive* ia;
	boost::archive::text_oarchive* oa;
	std::stringstream ss;



	static	DWORD WINAPI	clientThreadLaunch(LPVOID lpParam); // <= TODO : ������ ����� �迭�� ��������� �� �Լ��� ���� ����ϰ� �� �� ������
			DWORD			clientThread(LPVOID lpParam);


public:
	Server();
	~Server();

	void listenClients();


	

};
