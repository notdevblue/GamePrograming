#include "MultiPlayer.h"
#include <iostream>

#pragma region Constructor, Destructor

MultiPlayer::MultiPlayer()
{
	// vector 크기 미리 잡아줌
	// TODO : 총알 나오면 이제 클난다
	moveablePackets.reserve(2);

	// TODO : 같은 sstream 버퍼를 쓰는 것이 맞나?
	// WARN : Thread unsafe
	oa = new boost::archive::text_oarchive(ss);
	ia = new boost::archive::text_iarchive(ss);
	
	// sstream 클리어
	ss.str() = "";

	han_crit = new CriticalSession();


	try
	{
		int isOK = 0;

		isOK = WSAStartup(MAKEWORD(2, 2), &wsaData); // WSA 초기화
		if (isOK)
		{
			throw isOK;
		}
	}
	catch(int e)
	{
		// 예외
		std::cerr << e << " catched at " << __FUNCTION__ << " at Line: " << __LINE__ << std::endl;
	}

	// 소켓 정보 채워줌
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
//		// 이거보다 더 좋은 방법이 있을 것.
//		scanf_s("%ws", addr, 16);
//
//		// 검사
//		try
//		{
//			for (WCHAR item : addr)
//			{
//				if (!(item >= '0' && item <= '9') || !(item == '.'))
//				{
//					throw "0 ~ 9 의 정수와 \'.\' 만 입력할 수 있습니다.";
//				}
//			}
//		}
//		catch (const char* e)
//		{
//			// 예외
//			std::cerr << e << std::endl;
//			continue;
//		}
//	}
//	
//
//	INT addrSize = 0; // index 번호니 + 1 해줘야 함
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
//		// 복사앍
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
				// 에외
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
		// 예외
		std::cerr << e << " " <<  WSAGetLastError() << std::endl;
	}
	
}

int MultiPlayer::establishConnection()
{
	int isOK = 0;

	printf("사람을 찾아보고 있어요...\r\n");

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
		// 예외
		std::cerr << "Connect error at " << __FUNCTION__ << " , line: " << __LINE__ << std::endl << "Error: " << WSAGetLastError() << std::endl;
		return(-1);
	}

	try
	{
		if (sConnection == SOCKET_ERROR)
		{
			throw "연결에 실패하였습니다...";
		}
	}

	catch (const char* e)
	{
		// 예외
		std::cerr << e << std::endl;
		return(-1);
	}

	// recv 쓰레드
	hRecv = CreateThread(NULL, 0, recvThreadLaunch, this, 0, NULL);
	// send 쓰레드
	hSend = CreateThread(NULL, 0, sendThreadLaunch, this, 0, NULL);

	std::cout << "눈앞에 적이 었네요." << std::endl;

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
		// 예외
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
		// 예외
		std::cerr << "Thread shutdown error at " << __FUNCTION__ << " , line: " << __LINE__ << std::endl;
		return;
	}
}

void MultiPlayer::addPacket(const MoveablePacket& packet)
{
	moveablePackets.push_back(packet);
}