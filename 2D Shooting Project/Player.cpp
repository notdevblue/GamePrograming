#include "Player.h"
#include <conio.h>

#pragma region Constructor, Destructor

CONSTRUCTOR Player::Player()
{
	// ���߿� �ٲ�� ��
	x = 10;
	y = 10;

	playerPos.init(&x, &y);
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


// TODO : �Լ� �۵��� �ٲ�� ��.
// �ϴ� ��ӵ������ �ۼ��ߴµ�
// ��ӵ������ �ٲ�� ��.
void Player::move()
{
	switch (getInput())
	{
	case 0:
		// Ű ������ �ʾҴٴ� �ǹ�
		break;

	case 'w':
		--y;
		break;
	case 's':
		++y;
		break;
	case 'a':
		--x;
		break;
	case 'd':
		++x;
		break;

	default:
		// ����ó�� (�� �ʿ�� ���� �� ������)
		break;
	}

	

}