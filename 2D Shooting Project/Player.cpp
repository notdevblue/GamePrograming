#include "Player.h"
#include "BulletPool.h"
#include "SoundPlayer.h"
#include <conio.h>

#pragma region Constructor, Destructor

CONSTRUCTOR Player::Player()
{
	// TODO : 생성 위치 나중에 바꿔야 함
	pos.x = 10;
	pos.y = 20;

	playerPos.init(&pos.x, &pos.y);

	originalSprite[0] = "#####";
	originalSprite[1] = " ### ";
	originalSprite[2] = "#####";

	sprite.init(2, originalSprite);
}

DESTRUCTOR Player::~Player()
{

}

#pragma endregion




char Player::getInput()
{
	char input;

	CSLOCK // 실행 중에 문맥교환 일어나면 대참사가 일어날 듯 합니다.
	{
		// TODO : GetLock();
		// Render.h 에 CriticalSection han_crit 가 있어요.
		// 인스턴스 생성해서 get 하거나 staic 으로 생성하면 되긴 한데 그러면 좀;

		input = _getch_nolock();
		input = tolower(input);
	};

	return input;
}

Vector2* Player::getVector()
{
	return &playerPos;
}

Sprite* Player::getSprite()
{
	return &sprite;
}

MoveablePacket* Player::getPacketData()
{
	return &pos;
}

void Player::move(bool isRemote)
{
	int tx = pos.x;

	if (!isRemote)
	{
		switch (getInput())
		{
		case 'a':

			--tx;
			break;
		case 'd':

			++tx;
			break;
		}

		if (tx < 0)
			tx = 0;
		else if (tx > 100)
			tx = 100;

		pos.x = tx;

	}
	else
	{
		pos.y = 2;
		// 서버가 알아서 함
	}

}

void Player::shoot()
{
	char input = _getch_nolock();
	input = tolower(input);

	switch (input)
	{
	case 'j':
		// TODO : create bullet instance
		
		// TODO : 누르면 풀메니저에서 총알 하나 가져와서 렌더 클레스에 넣어서 돌리게 하고 해야하는데요
		// 아니 시팔 이거 로직 터졌네
		// ㅇ아아아ㅏㄱ
		
		// EXPLAIN : 여기서 해야하는거
		// 
		// 총알을 위로 쭈우욱 올려야함
		// 
		
		// => Render 에 푸쉬
		// => 매 프레임 마다 충돌 체크
		// => 머야 이게 살려줘요

		// WARN : untested code
		Bullet* bullet = BulletPool::instance().getBullet();
		SoundPlayer::instance().addToSoundQueue(SOUNDTYPE::FIRE);
		
		// 음 이제 어쩌지
		bullet->getVector();


		break;
	}

}