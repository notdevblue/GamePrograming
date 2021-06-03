#pragma once
// serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <sstream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#define BUFFER_SIZE 1024
#define PORT 56789 // �������� �뵿���տ��� ����ϴ� ��Ʈ�̱⵵ �մϴ�. (tmi)

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
	HANDLE		hRecv;	// ���ú� ������
	HANDLE		hSend;	// ���� ������


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

	// ȣ��Ʈ���� �Ǻ�, WSAStartup, SOCKADDR_IN �Է� ����
	MultiPlayer();

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

	// data => serialization
	void toBuffer();

	// serialization => data
	void toData();


	// add packet to serialization
	// TODO : PacketType
	void addPacket();
};

