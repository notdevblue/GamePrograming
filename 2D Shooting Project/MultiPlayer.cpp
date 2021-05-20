#include "MultiPlayer.h"
#include <iostream>

#pragma region Constructor, Destructor

MultiPlayer::MultiPlayer(bool isHost)
{
	this->isHost = isHost;

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

	if (isHost) // ���� ȣ��Ʈ���� �Ǵ�
	{
		// ����ü ������ �־���
		clientData.sin_addr.s_addr	= INADDR_ANY;
		clientData.sin_family		= AF_INET;
		clientData.sin_port			= htons(PORT);

		// accept ���� �ʿ���
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
		// �̰ź��� �� ���� ����� ���� ��.
		scanf_s("%ws", addr, 16);

		// �˻�
		try
		{
			for (WCHAR item : addr)
			{
				if (!(item >= '0' && item <= '9') || !(item == '.'))
				{
					throw "0 ~ 9 �� ������ \'.\' �� �Է��� �� �ֽ��ϴ�.";
				}
			}
		}
		catch (const char* str)
		{
			std::cerr << str << std::endl;
			continue;
		}
	}
	

	INT addrSize = 0; // index ��ȣ�� + 1 ����� ��
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
		// �����
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
				// ����
				throw "Client socket Invalid";
			}
			
			isOK = bind(sPlayer, (SOCKADDR*)&clientData, sizeof(clientData));
			
			if (isOK)
			{
				throw "bind error";
			}



			break;

		default:
			// ����
			throw "only supports IPv4";
			break;
		}
	}
	catch (const char* e)
	{
		std::cerr << e << " " <<  WSAGetLastError() << std::endl;
	}
	
}