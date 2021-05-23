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



DWORD MultiPlayer::recvThread(LPVOID lpParam)
{


	return(0);
}

DWORD MultiPlayer::sendThread(LPVOID lpParam)
{


	return(0);
}