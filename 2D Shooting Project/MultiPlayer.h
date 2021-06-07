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
#define PORT 56789 // �������� �뵿���տ��� ����ϴ� ��Ʈ�̱⵵ �մϴ�. (tmi)

#pragma region �ּ���

// Packet(buffer) ����
/*										
A : B

MSG : BUFFER

MSG		= ��������
BUFFER  = ����
*/

// Render �� ������ ���ư��� ��?
// ���ɵ�����

// ������ �ϴ� ��
/*
�ڽ��� ��ġ

�ڽ��� �߻��� �Ѿ��� ��ġ <= �̰� �����Ը� ������
�Ǵ� �ڽ��� �Ѿ��� �߻��ߴٴ� �޼���. <= �̷��� �ڽ� ��ġ���� ���� �� �ø��⸸ �ϸ� �Ǵ� �����Ұ� ���⵵ �ѵ�
		if(�߻�)
		{
			send(�ڽ� ��ġ);
		}

*/

// �޾ƾ� �ϴ� ��
/*
���� ��ġ

�Ѿ˵� <= ���� ���� (�����ֱ⸸ �ص� ��)




*/

// �������� �ϴ� ��
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
	HANDLE		hRecv;	// ���ú� ������
	HANDLE		hSend;	// ���� ������


	static	DWORD WINAPI	recvThreadLaunch(LPVOID);
	static	DWORD WINAPI	sendThreadLaunch(LPVOID);
			DWORD			recvThread(LPVOID);
			DWORD			sendThread(LPVOID);

	// ���� ��Ŷ ����
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

	// ���� IP
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

	// �����ε�
	//void addPacket(MoveablePacket packet);
};

