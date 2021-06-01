#include "Enemy.h"
#include "Console.h"
#include "Missile.h"
#include <iostream>


void Enemy::setEnemy()
{
	x = rand() % 20;
	y = 0;
}

void Enemy::drawEnemy()
{
	gotoXY(x, y);
	setTextColor(4);
	std::cout << "¡ä";
	SetTextColor(15);
	++y;
}

bool Enemy::checkEnd()
{
	if (y > 39)
	{
		return true;
	}

	return false;						
}