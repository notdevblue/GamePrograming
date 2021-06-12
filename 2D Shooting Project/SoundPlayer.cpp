#include "SoundPlayer.h"

#pragma region Constructor, Destructor

SoundPlayer::SoundPlayer()
{
	hThread = CreateThread(NULL, 0, launchSoundPlayerThread, NULL, 0, NULL);
}

SoundPlayer::~SoundPlayer()
{
	if (WaitForSingleObject(hThread, INFINITE) != WAIT_OBJECT_0)
	{
		printf("Thread shutdown error. SoundPlayer::~SoundPlayer()\r\n");
	}


	// 큐 비움
	while (!soundQueue.empty())
	{
		soundQueue.pop();
	}
}
#pragma endregion

void SoundPlayer::addToSoundQueue(SOUNDTYPE type)
{
	soundQueue.push(type);
}

void SoundPlayer::playSound(SOUNDTYPE type)
{
	switch (type)
	{
	case SOUNDTYPE::FIRE:
		// TODO : 소리 넣어줘야 함
		break;

	case SOUNDTYPE::HIT:

		break;
	}
}

// Thread launcher
DWORD SoundPlayer::launchSoundPlayerThread(LPVOID lpParam)
{
	SoundPlayer* _this = (SoundPlayer*)lpParam;
	return _this->soundPlayerThread(_this);
}

// Thread
DWORD SoundPlayer::soundPlayerThread(LPVOID lpParam)
{
	// queue 안에 있는 요청을 전부 처리

	while (true) // TODO : 조건이 필요함
	{
		if (soundQueue.empty()) continue;

		playSound(soundQueue.front());
		soundQueue.pop();
	}

	return(0);
}