#include "Missile.h"

#include <iostream>
#include "Console.h"

void Missile::setMissile(int _x, int _y, bool isEnemy)
{
	this->isEnemy = isEnemy;

	x = _x;
	y = _y;
}


void Missile::drawMissile()
{
	gotoXY(x, y);
	setTextColor(2);
	std::cout << "¡Ü";
	setTextColor(15);
	if (!isEnemy)
	{
		--y;
	}
	else
	{
		++++y;
	}
}

bool Missile::checkEnd()
{
	if (y < 0)
	{
		return true;
	}
	if (y > 39)
	{
		return true;
	}
	return false;
}

bool Missile::checkCollision(const int _x, const int _y)
{
	if (x == _x && (y == _y || y - 1 == _y || y - 2 == _y))
	{
		return true;
	}

	return false;
}
