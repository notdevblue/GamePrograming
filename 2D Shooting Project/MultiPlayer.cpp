#include "MultiPlayer.h"
#include <iostream>

#pragma region Constructor, Destructor

MultiPlayer::MultiPlayer(bool isHost)
{
	this->isHost = isHost;

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

	if (isHost) // 서버 호스트인지 판단
	{
		// 구조체 데이터 넣어줌
		clientData.sin_addr.s_addr	= INADDR_ANY;
		clientData.sin_family		= AF_INET;
		clientData.sin_port			= htons(PORT);

		// accept 에서 필요함
		enemyDataSize				= sizeof(enemyData);
	}
	else
	{
		inputIP();

		clientData.sin_family	= AF_INET;
		clientData.sin_port		= htons(PORT);
		InetPton(clientData.sin_family, ipAddr, &clientData.sin_addr);
	}



}

#pragma endregion

MultiPlayer::~MultiPlayer()
{
	closesocket(sEnemy);
	closesocket(sPlayer);

	WSACleanup();

	free(ipAddr);
}

void MultiPlayer::inputIP()
{
	WCHAR addr[16];

	while (true)
	{
		// 이거보다 더 좋은 방법이 있을 것.
		scanf_s("%ws", addr, 16);

		// 검사
		try
		{
			for (WCHAR item : addr)
			{
				if (!(item >= '0' && item <= '9') || !(item == '.'))
				{
					throw "0 ~ 9 의 정수와 \'.\' 만 입력할 수 있습니다.";
				}
			}
		}
		catch (const char* str)
		{
			std::cerr << str << std::endl;
			continue;
		}
	}
	

	INT addrSize = 0; // index 번호니 + 1 해줘야 함
	for (int i = 0; i < 16; ++i)
	{
		if (addr[i] == '\0')
		{
			addrSize = i + 1;
		}
	}

	ipAddr = (LPWCH)malloc(sizeof(LPWCH) * addrSize);
	for (int i = 0; i < addrSize; ++i)
	{
		// 복사앍
		ipAddr[i] = addr[i];
	}
}

void MultiPlayer::createTCPSocket()
{
	int isOK = 1;

	try
	{
		switch (clientData.sin_family)
		{
		case AF_INET:
			sPlayer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sPlayer == INVALID_SOCKET)
			{
				// 에외
				throw "Client socket Invalid";
			}
			
			isOK = bind(sPlayer, (SOCKADDR*)&clientData, sizeof(clientData));
			
			if (isOK)
			{
				throw "bind error";
			}



			break;

		default:
			// 예외
			throw "only supports IPv4";
			break;
		}
	}
	catch (const char* e)
	{
		std::cerr << e << " " <<  WSAGetLastError() << std::endl;
	}
	
}