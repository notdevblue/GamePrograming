#include <iostream>
#include <time.h>
#include <vector>
#include "Console.h"
#include "Projectile.h"

void setConsoleView();
bool bMoveDown;
int y;
std::vector<Projectile> projectiles, myProjectiles;


int main()
{
	srand((unsigned)time(NULL));

	bMoveDown = true;
	y = 0;

	projectiles.clear();
	myProjectiles.clear();

	setConsoleView();

	int key;

	while (true)
	{
		key = getKeyDown();
		key = tolower(key);

		if (key == 'a')
		{
			Projectile myProjectile;
			myProjectile.setMissile(y);

			myProjectiles.push_back(myProjectile);
		}

		if (rand() % 100 < 10)
		{
			Projectile projectile;
			projectile.setMissile(-1);

			projectiles.push_back(projectile);
		}

		for (int i = 0; i < (int)projectiles.size(); ++i)
		{
			projectiles[i].moveMissile();
			projectiles[i].drawMissile();
		}

		for (int i = 0; i < (int)myProjectiles.size(); ++i)
		{
			myProjectiles[i].moveMissile();
			myProjectiles[i].drawMissile();
		}


		gotoXY(2, y);
		std::cout << "¢º"; // µÎ Ä­ Â÷Ä¡ÇÔ

		gotoXY(59, 19);
		switch (bMoveDown)
		{
		case true:
			++y;
			if (y > 19)
			{
				y = 19;
				bMoveDown = false;
			}
			break;

		case false:
			--y;
			if (y < 0)
			{
				y = 0;
				bMoveDown = true;
			}
			break;
		}

		for (int i = 0; i < (int)projectiles.size(); ++i)
		{
			if (projectiles[i].checkEnd())
			{
				projectiles.erase(projectiles.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)myProjectiles.size(); ++i)
		{
			if (myProjectiles[i].checkEnd())
			{
				myProjectiles.erase(myProjectiles.begin() + i);
				i--;
			}
		}

		for (int myIdx = 0; myIdx < (int)myProjectiles.size(); ++myIdx)
		{
			for (int enemyIdx = 0; enemyIdx < (int)projectiles.size(); ++enemyIdx)
			{
				if (myProjectiles[myIdx].checkCollision(projectiles[enemyIdx]))
				{
					myProjectiles.erase(myProjectiles.begin() + myIdx);
					--myIdx;

					projectiles.erase(projectiles.begin() + enemyIdx);
					--enemyIdx;
				}
			}
		}


		Sleep(50);
		clrscr();
	}


	return(0);
}


void setConsoleView()
{
	system("mode con:cols=60 lines=20");
	system("title shooting game");
}