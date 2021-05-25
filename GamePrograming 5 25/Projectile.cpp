#include <iostream>
#include "Projectile.h"
#include "Console.h"



Projectile::Projectile()
{
	srand(unsigned(time(NULL)));
}

void Projectile::setMissile(int _y)
{
	if (_y == -1)
	{
		x = 59;
		y = rand() & 20;

		bMoveLeft = true;
	}
	else
	{
		x = 3;
		y = _y;
		bMoveLeft = false;
	}
	
}

void Projectile::moveMissile()
{
	if (bMoveLeft)
	{
		--x;
	}
	else
	{
		++x;
	}
	
}

void Projectile::drawMissile()
{
	if (x < 1 || x > 58) return;

	gotoXY(x, y);

	if(bMoveLeft)
	{
		setTextColor(1);
		std::cout << "¢·";
		setTextColor(15);
	}
	else
	{
		setTextColor(14);
		std::cout << "¡æ";
		setTextColor(15);
	}


}

bool Projectile::checkCollision(Projectile other)
{
	if ((this->x <= other.x + 1 && this->x >= other.x - 1) && (this->y <= other.y + 1 && this->y >= other.y - 1))
	{
		return true;
	}

	return false;
}

bool Projectile::checkEnd()
{
	if (bMoveLeft)
	{
		if (x < 1)
		{
			return true;
		}
	}
	else
	{
		if (x > 58)
		{
			return true;
		}
	}

	

	return false;
}