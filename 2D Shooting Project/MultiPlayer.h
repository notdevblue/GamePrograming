#pragma once

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#define BUFFER_SIZE 1024
#define PORT 56789 // 서버개발 노동조합에서 사용하는 포트이기도 합니다. (tmi)

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
	BOOL		isHost; // 서버 여는 사람인지 판별용
	HANDLE		hRecv;	// 리시브 쓰레드
	HANDLE		hSend;	// 센드 쓰레드


	static	DWORD WINAPI	recvThreadLaunch(LPVOID);
	static	DWORD WINAPI	sendThreadLaunch(LPVOID);
			DWORD			recvThread(LPVOID);
			DWORD			sendThread(LPVOID);


public:

	// 호스트인지 판별, WSAStartup, SOCKADDR_IN 입력 해줌
	MultiPlayer(bool isHost);

	// 정리 해줌 (당연하지만)
	~MultiPlayer();

	// 접속 IP
	void inputIP();

	// 클라이언트 생성 -> 소켓 바인딩까지 해줌
	void createTCPSocket();

	// 클라이언트를 리스닝 -> 접속 수락 -> 쓰레드 생성 까지 해줌
	// returns -1 when error
	int establishConnection();

	// 커넥션 해제, 쓰래드 셧다운 대기
	void shutDown();


};

