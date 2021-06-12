#pragma once
#include <queue>
#include <Windows.h>
#include "Han.h"

class SoundPlayer
{
private:
	std::queue<SOUNDTYPE> soundQueue;
	
	HANDLE hThread;

public:

	inline static SoundPlayer& instance()
	{
		static SoundPlayer* soundPlayer = new SoundPlayer();
		return *soundPlayer;
	}

	void addToSoundQueue(SOUNDTYPE type);
	void playSound(SOUNDTYPE type);


	~SoundPlayer();

private:
	SoundPlayer();


	static	DWORD WINAPI	launchSoundPlayerThread(LPVOID lpParam);
			DWORD			soundPlayerThread(LPVOID lpParam);
};

