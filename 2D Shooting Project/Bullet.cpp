#include "Bullet.h"

#pragma region Constructor Destructor

// �߻� �� �� new �� ������
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
	if (true) // TODO : Ư���� ������ �ʿ���
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