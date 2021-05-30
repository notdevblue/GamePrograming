#include "Player.h"
#include <conio.h>

#pragma region Constructor, Destructor

CONSTRUCTOR Player::Player()
{
	// 나중에 바꿔야 함
	x = 10;
	y = 10;

	playerPos.init(&x, &y);
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


// TODO : 함수 작동을 바꿔야 함.
// 일단 등속도운동으로 작성했는데
// 등가속도운동으로 바꿔야 함.
void Player::move()
{
	switch (getInput())
	{
	case 0:
		// 키 누르지 않았다는 의미
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
		// 예외처리 (할 필요는 없는 듯 하지만)
		break;
	}

	

}