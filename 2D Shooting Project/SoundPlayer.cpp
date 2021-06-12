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


	// ť ���
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
		// TODO : �Ҹ� �־���� ��
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
	// queue �ȿ� �ִ� ��û�� ���� ó��

	while (true) // TODO : ������ �ʿ���
	{
		if (soundQueue.empty()) continue;

		playSound(soundQueue.front());
		soundQueue.pop();
	}

	return(0);
}