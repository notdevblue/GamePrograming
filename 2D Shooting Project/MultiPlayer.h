#pragma once
// Packet serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#include "csession.h"
#include "MoveableObjectPacket.h"

#define BUFFER_SIZE 1024
#define PORT 56789 // 서버개발 노동조합에서 사용하는 포트이기도 합니다. (tmi)

#pragma region 주석들

// Packet(buffer) 구조
/*										
A : B

MSG : BUFFER

MSG		= 프로토콜
BUFFER  = 내용
*/

// Render 와 별개로 돌아가야 함?
// 어케돌리지

// 보내야 하는 것
/*
자신의 위치

자신이 발사한 총알의 위치 <= 이게 여러게면 어케함
또는 자신이 총알을 발사했다는 메세지. <= 이러면 자신 위치에서 위로 쭉 올리기만 하면 되니 간편할거 같기도 한데
		if(발사)
		{
			send(자신 위치);
		}

*/

// 받아야 하는 것
/*
적의 위치

총알들 <= 어케 받지 (보여주기만 해도 됨)




*/

// 서버에서 하는 것
/*



*/

#pragma endregion

class MultiPlayer
{
private:
	WSADATA		wsaData;
	SOCKET		sConnection;
	SOCKADDR_IN clientData;
	SOCKADDR_IN enemyData;
	INT			enemyDataSize;
	CHAR		recvBuffer[BUFFER_SIZE];
	CHAR		sendBuffer[BUFFER_SIZE];
	HANDLE		hRecv;	// 리시브 스레드
	HANDLE		hSend;	// 센드 스레드


	static	DWORD WINAPI	recvThreadLaunch(LPVOID);
	static	DWORD WINAPI	sendThreadLaunch(LPVOID);
			DWORD			recvThread(LPVOID);
			DWORD			sendThread(LPVOID);

	// 보낼 페킷 백터
	std::vector<MoveablePacket> moveablePackets;

	CriticalSession* han_crit;

	// actual msg buffer
	std::stringstream ss;
	// serialization
	boost::archive::text_oarchive* oa;
	// deserialization
	boost::archive::text_iarchive* ia;

	// data => serialization
	void toBuffer(const MoveablePacket&);

	// serialization => data
	void toData(MoveablePacket&);

	// 접속 IP
	//void inputIP();

public:

	// WSAStartup, SOCKADDR_IN
	MultiPlayer();

	// cleanup (obviously)
	~MultiPlayer();

	// creates socket
	void createTCPSocket();

	// connects to server, starts Thread
	// returns -1 when error
	int establishConnection();

	// disconnection, waits threads for shutdown.
	void shutDown();

	// add packet to serialization
	void addPacket(const MoveablePacket& packet);

	// 오버로딩
	//void addPacket(MoveablePacket packet);
};

