#include "Bullet.h"

#pragma region Constructor Destructor

// 발사 할 시 new 로 생성함
CONSTRUCTOR Bullet::Bullet()
{
	isEnabled = false;
}

DESTRUCTOR Bullet::~Bullet()
{
	
}

#pragma endregion

Vector2 Bullet::getVector()
{
	return pos;
}

void Bullet::disable()
{
	if (true) // TODO : 특정한 조건이 필요함
	{
		this->isEnabled = false;
	}
}

void Bullet::move(int x, bool isRemote)
{
	*pos.x = x;

	switch(isRemote)
	{
	case true:
		++*pos.y;
		break;

	case false:
		--*pos.y;
		break;
	}
}