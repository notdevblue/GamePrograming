#pragma once
// serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <sstream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#define BUFFER_SIZE 1024
#define PORT 56789 // 서버개발 노동조합에서 사용하는 포트이기도 합니다. (tmi)

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

class MultiPlayer
{
private:
	WSADATA		wsaData;
	SOCKET		sConnection;
	SOCKADDR_IN clientData;
	SOCKADDR_IN enemyData;
	INT			enemyDataSize;
	LPWCH		ipAddr;
	CHAR		recvBuffer[BUFFER_SIZE];
	CHAR		sendBuffer[BUFFER_SIZE];
	HANDLE		hRecv;	// 리시브 쓰레드
	HANDLE		hSend;	// 센드 쓰레드


	static	DWORD WINAPI	recvThreadLaunch(LPVOID);
	static	DWORD WINAPI	sendThreadLaunch(LPVOID);
			DWORD			recvThread(LPVOID);
			DWORD			sendThread(LPVOID);

	// Packet list
	std::vector</*TODO : DATATYPE*/> sendlist;

	// serialization
	std::stringstream ss;
	boost::archive::text_oarchive oa;

	// unserialization
	boost::archive::text_iarchive ia;
public:

	// 호스트인지 판별, WSAStartup, SOCKADDR_IN 입력 해줌
	MultiPlayer();

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

	// data => serialization
	void toBuffer();

	// serialization => data
	void toData();


	// add packet to serialization
	// TODO : PacketType
	void addPacket();
};

