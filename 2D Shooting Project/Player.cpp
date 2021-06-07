#include "Player.h"
#include <conio.h>

#pragma region Constructor, Destructor

CONSTRUCTOR Player::Player()
{
	// TODO : ���� ��ġ ���߿� �ٲ�� ��
	pos.x = 10;
	pos.y = 10;

	playerPos.init(&pos.x, &pos.y);

	originalSprite[0] = " # # ";
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
	if (!isRemote)
	{
		switch (getInput())
		{
		case 0:
			// Ű ������ �ʾҴٴ� �ǹ�
			break;

			/*case 'w':
				--y;
				break;
			case 's':
				++y;
				break;*/
		case 'a':

			--pos.x;
			break;
		case 'd':

			++pos.x;
			break;
		}
	}
	else
	{
		// ������ �˾Ƽ� ��
	}

}