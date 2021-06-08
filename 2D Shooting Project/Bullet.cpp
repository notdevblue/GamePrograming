#include "Bullet.h"

#pragma region Constructor Destructor

// �߻� �� �� new �� ������
CONSTRUCTOR Bullet::Bullet(short x, bool isRemote) : x(x), isRemote(isRemote)
{
	
}

DESTRUCTOR Bullet::~Bullet()
{
	
}

#pragma endregion

Vector2 Bullet::getVector()
{
	return pos;
}

void Bullet::move()
{
	*pos.x = x;

	switch(isRemote)
	{
	case true:
		++*pos.y;
		break;

	case false:
		++*pos.y;
		break;
	}
}