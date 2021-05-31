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


// 적 포지션
DWORD MultiPlayer::recvThread(LPVOID lpParam)
{


	return(0);
}

// 본인 포지션
DWORD MultiPlayer::sendThread(LPVOID lpParam)
{


	return(0);
}