#pragma once

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#define BUFFER_SIZE 1024
#define PORT 56789 // �������� �뵿���տ��� ����ϴ� ��Ʈ�̱⵵ �մϴ�. (tmi)

class MultiPlayer
{
private:
	WSADATA		wsaData;
	SOCKET		sListening;
	SOCKET		sEnemy;
	SOCKADDR_IN clientData;
	SOCKADDR_IN enemyData;
	INT			enemyDataSize;
	LPWCH		ipAddr;
	CHAR		recvBuffer[BUFFER_SIZE];
	CHAR		sendBuffer[BUFFER_SIZE];
	BOOL		isHost; // ���� ���� ������� �Ǻ���
	HANDLE		hRecv;	// ���ú� ������
	HANDLE		hSend;	// ���� ������


	static	DWORD WINAPI	recvThreadLaunch(LPVOID);
	static	DWORD WINAPI	sendThreadLaunch(LPVOID);
			DWORD			recvThread(LPVOID);
			DWORD			sendThread(LPVOID);


public:

	// ȣ��Ʈ���� �Ǻ�, WSAStartup, SOCKADDR_IN �Է� ����
	MultiPlayer(bool isHost);

	// ���� ���� (�翬������)
	~MultiPlayer();

	// ���� IP
	void inputIP();

	// Ŭ���̾�Ʈ ���� -> ���� ���ε����� ����
	void createTCPSocket();

	// Ŭ���̾�Ʈ�� ������ -> ���� ���� -> ������ ���� ���� ����
	// returns -1 when error
	int establishConnection();

	// Ŀ�ؼ� ����, ������ �˴ٿ� ���
	void shutDown();


};

