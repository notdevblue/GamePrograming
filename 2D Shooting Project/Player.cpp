#include "Player.h"
#include "BulletPool.h"
#include <conio.h>

#pragma region Constructor, Destructor

CONSTRUCTOR Player::Player()
{
	// TODO : ���� ��ġ ���߿� �ٲ�� ��
	pos.x = 10;
	pos.y = 10;

	playerPos.init(&pos.x, &pos.y);

	originalSprite[0] = "#####";
	originalSprite[1] = " ### ";
	originalSprite[2] = "#####";

	sprite.init(2, originalSprite);

	bAPressed = false;
	bDPressed = false;

}

DESTRUCTOR Player::~Player()
{

}

#pragma endregion




char Player::getInput()
{
	char input;

	CSLOCK // ���� �߿� ���Ʊ�ȯ �Ͼ�� �����簡 �Ͼ �� �մϴ�.
	{
		// TODO : GetLock();
		// Render.h �� CriticalSection han_crit �� �־��.
		// �ν��Ͻ� �����ؼ� get �ϰų� staic ���� �����ϸ� �Ǳ� �ѵ� �׷��� ��;

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
		// ������ �˾Ƽ� ��
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
		BulletPool::instance->getBullet();
		// returns Bullet obj. TODO :
		// => Render �� Ǫ��
		// => �� ������ ���� �浹 üũ
		// => ���� �Ӿ� �̰� ������

		break;
	}

}