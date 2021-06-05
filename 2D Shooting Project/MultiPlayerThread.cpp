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

// 뭔가 잘못 작성함
void MultiPlayer::toData(MoveablePacket& out)
{
	*ia >> out;
}

#pragma endregion



DWORD MultiPlayer::recvThread(LPVOID lpParam)
{
	// Boost serialization
	// (아직 구현 안됨) 모든 총알 위치 담긴 class
	
	CSLOCK
	{
		GetLock lock(*han_crit);
		
		// WARN : 이렇게 작성하면 안됨.
		// recv 는 페킷을 한번에 전부 받지 않음
		// recv returns 받은 페킷 사이즈
		recv(sConnection, recvBuffer, BUFFER_SIZE, 0);
		ss.str() = recvBuffer;
	}
	// TODO : 적 페킷 구현해야 함
	//toData(enemyPacket);

	return(0);
}

// 본인 포지션
// 본인 포지션 전부?
DWORD MultiPlayer::sendThread(LPVOID lpParam)
{
	for (MoveablePacket packet : moveablePackets) CSLOCK
	{
		GetLock lock(*han_crit);
		toBuffer(packet);

		// WARN : 이렇게 작성하면 안됨.
		// send 도 recv 와 같은 이유
		send(sConnection, ss.str().c_str(), BUFFER_SIZE, 0);
	}

	return(0);
}