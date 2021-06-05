#include "MultiPlayer.h"



#pragma region ThreadLaunch

DWORD WINAPI MultiPlayer::recvThreadLaunch(LPVOID lpParam)
{
	MultiPlayer* _this = (MultiPlayer*)lpParam;


	return _this->recvThread(_this);
}

DWORD WINAPI MultiPlayer::sendThreadLaunch(LPVOID lpParam)
{
	MultiPlayer* _this = (MultiPlayer*)lpParam;

	return _this->sendThread(_this);
}

#pragma endregion

#pragma region Serialization

void MultiPlayer::toBuffer(const MoveablePacket& packet)
{
	*oa << packet;	
}

// ���� �߸� �ۼ���
void MultiPlayer::toData(MoveablePacket& out)
{
	*ia >> out;
}

#pragma endregion



DWORD MultiPlayer::recvThread(LPVOID lpParam)
{
	// Boost serialization
	// (���� ���� �ȵ�) ��� �Ѿ� ��ġ ��� class
	
	CSLOCK
	{
		GetLock lock(*han_crit);
		
		// WARN : �̷��� �ۼ��ϸ� �ȵ�.
		// recv �� ��Ŷ�� �ѹ��� ���� ���� ����
		// recv returns ���� ��Ŷ ������
		recv(sConnection, recvBuffer, BUFFER_SIZE, 0);
		ss.str() = recvBuffer;
	}
	// TODO : �� ��Ŷ �����ؾ� ��
	//toData(enemyPacket);

	return(0);
}

// ���� ������
// ���� ������ ����?
DWORD MultiPlayer::sendThread(LPVOID lpParam)
{
	for (MoveablePacket packet : moveablePackets) CSLOCK
	{
		GetLock lock(*han_crit);
		toBuffer(packet);

		// WARN : �̷��� �ۼ��ϸ� �ȵ�.
		// send �� recv �� ���� ����
		send(sConnection, ss.str().c_str(), BUFFER_SIZE, 0);
	}

	return(0);
}