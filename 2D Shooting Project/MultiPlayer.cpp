#include "MultiPlayer.h"
#include <iostream>

#pragma region Constructor, Destructor

MultiPlayer::MultiPlayer()
{
	// vector ũ�� �̸� �����
	// TODO : �Ѿ� ������ ���� Ŭ����
	moveablePackets.reserve(2);

	// TODO : ���� sstream ���۸� ���� ���� �³�?
	// WARN : Thread unsafe
	oa = new boost::archive::text_oarchive(ss);
	ia = new boost::archive::text_iarchive(ss);
	
	// sstream Ŭ����
	ss.str() = "";

	han_crit = new CriticalSession();


	try
	{
		int isOK = 0;

		isOK = WSAStartup(MAKEWORD(2, 2), &wsaData); // WSA �ʱ�ȭ
		if (isOK)
		{
			throw isOK;
		}
	}
	catch(int e)
	{
		// ����
		std::cerr << e << " catched at " << __FUNCTION__ << " at Line: " << __LINE__ << std::endl;
	}

	// ���� ���� ä����
	clientData.sin_family	= AF_INET;
	clientData.sin_port		= htons(PORT);
	InetPton(clientData.sin_family, TEXT("127.0.0.1"), &clientData.sin_addr);
}

#pragma endregion

MultiPlayer::~MultiPlayer()
{
	closesocket(sConnection);

	WSACleanup();

	delete han_crit;
	delete oa;
	delete ia;
}

//void MultiPlayer::inputIP()
//{
//	WCHAR addr[16];
//
//	while (true)
//	{
//		// �̰ź��� �� ���� ����� ���� ��.
//		scanf_s("%ws", addr, 16);
//
//		// �˻�
//		try
//		{
//			for (WCHAR item : addr)
//			{
//				if (!(item >= '0' && item <= '9') || !(item == '.'))
//				{
//					throw "0 ~ 9 �� ������ \'.\' �� �Է��� �� �ֽ��ϴ�.";
//				}
//			}
//		}
//		catch (const char* e)
//		{
//			// ����
//			std::cerr << e << std::endl;
//			continue;
//		}
//	}
//	
//
//	INT addrSize = 0; // index ��ȣ�� + 1 ����� ��
//	for (int i = 0; i < 16; ++i)
//	{
//		if (addr[i] == '\0')
//		{
//			addrSize = i + 1;
//		}
//	}
//
//	ipAddr = (LPWCH)malloc(sizeof(WCHAR) * addrSize);
//	for (int i = 0; i < addrSize; ++i)
//	{
//		// �����
//		ipAddr[i] = addr[i];
//	}
//}

void MultiPlayer::createTCPSocket()
{
	int isOK = 1;

	try
	{
		switch (clientData.sin_family)
		{
		case AF_INET:
			sConnection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sConnection == INVALID_SOCKET)
			{
				// ����
				throw "Client socket Invalid";
			}
			break;

		default:
			
			throw "only supports IPv4";
			break;
		}
	}
	catch (const char* e)
	{
		// ����
		std::cerr << e << " " <<  WSAGetLastError() << std::endl;
	}
	
}

int MultiPlayer::establishConnection()
{
	int isOK = 0;

	printf("����� ã�ƺ��� �־��...\r\n");

	try
	{
		// TODO : connect
		isOK = connect(sConnection, (SOCKADDR*)&clientData, sizeof(clientData));

		if (isOK == SOCKET_ERROR)
		{
			throw isOK;
		}
	}
	catch(int e)
	{
		// ����
		std::cerr << "Connect error at " << __FUNCTION__ << " , line: " << __LINE__ << std::endl << "Error: " << WSAGetLastError() << std::endl;
		return(-1);
	}

	try
	{
		if (sConnection == SOCKET_ERROR)
		{
			throw "���ῡ �����Ͽ����ϴ�...";
		}
	}

	catch (const char* e)
	{
		// ����
		std::cerr << e << std::endl;
		return(-1);
	}

	// recv ������
	hRecv = CreateThread(NULL, 0, recvThreadLaunch, this, 0, NULL);
	// send ������
	hSend = CreateThread(NULL, 0, sendThreadLaunch, this, 0, NULL);

	std::cout << "���տ� ���� ���׿�." << std::endl;

	return(0);
}

void MultiPlayer::shutDown()
{
	int isOK = 1;

	try
	{
		isOK = WaitForSingleObject(hRecv, INFINITE);


		if (isOK != WAIT_OBJECT_0)
		{
			throw isOK;
		}
	}
	catch(int e)
	{
		// ����
		std::cerr << "Thread shutdown error at " << __FUNCTION__ << " , line: " << __LINE__ << std::endl;
		return;
	}


	try
	{
		isOK = WaitForSingleObject(hSend, INFINITE);


		if (isOK != WAIT_OBJECT_0)
		{
			throw isOK;
		}
	}
	catch (int e)
	{
		// ����
		std::cerr << "Thread shutdown error at " << __FUNCTION__ << " , line: " << __LINE__ << std::endl;
		return;
	}
}

void MultiPlayer::addPacket(const MoveablePacket& packet)
{
	moveablePackets.push_back(packet);
}