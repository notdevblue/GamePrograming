#include <iostream>
#include <time.h>
#include <vector>

#include "Console.h"
#include "Enemy.h"
#include "Missile.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


#pragma region global 
int g_x;
int g_y;
int g_missileCount;

std::vector<Enemy> enemies;
std::vector<Missile> myMissiles;
std::vector<Missile> enemyMissiles;
#pragma endregion

#pragma region inits
void setConsoleView();
void initData();
#pragma endregion

#pragma region render
void drawPlayer();

#pragma endregion

void checkDirection();
void checkCollision();

int main()
{
#pragma region init
	setConsoleView();
	initData();
#pragma endregion

	while (true)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 0xE0)
		{
			checkDirection();
		}
		else if (key == 'a')
		{
			if (g_missileCount == 0)
			{
				Missile missile;
				missile.setMissile(g_x, g_y);

				myMissiles.push_back(missile);

				g_missileCount = 3;
			}

			
		}

		if (rand() % 100 < 10)
		{
			Enemy enemy;
			enemy.setEnemy();
			enemies.push_back(enemy);
		}

		if (rand() % 100 < 10)
		{
			if (enemies.size() < 2) continue;
			int rndidx = rand() % ((int)enemies.size() - 1);

			Missile missile;
			missile.setMissile(enemies[rndidx].getX(), enemies[rndidx].getY() + 1, true);
			enemyMissiles.push_back(missile);
		}

		checkCollision();

		for (int i = 0; i < (int)myMissiles.size(); ++i)
		{
			myMissiles[i].drawMissile();
		}
		for (int i = 0; i < (int)enemies.size(); ++i)
		{
			enemies[i].drawEnemy();
		}
		for (int i = 0; i < (int)enemyMissiles.size(); ++i) // <= °úÁ¦
		{
			enemyMissiles[i].drawMissile();
		}

		drawPlayer();

		for (int i = 0; i < (int)myMissiles.size(); ++i)
		{
			if (myMissiles.at(i).checkEnd())
			{
				myMissiles.erase(myMissiles.begin() + i);
				--i;
			}
		}
		for (int i = 0; i < (int)enemyMissiles.size(); ++i)
		{
			if (enemyMissiles.at(i).checkEnd())
			{
				enemyMissiles.erase(enemyMissiles.begin() + i);
				--i;
			}
		}
		for (int i = 0; i < (int)enemies.size(); ++i)
		{
			if (enemies.at(i).checkEnd())
			{
				enemies.erase(enemies.begin() + i);
				--i;
			}
		}

		if (g_missileCount > 0)
		{
			--g_missileCount;
		}
		Sleep(100);
		clrscr();
	}

	return(0);
}


#pragma region inits
void setConsoleView()
{
	system("mode con:cols=40 lines=40");
	system("title SHOOTING GAME #2");
}

void initData()
{
	srand((unsigned)time(NULL));

	g_x = 10;
	g_y = 38;
	g_missileCount = 0;

	enemies.clear();
	myMissiles.clear();
	enemyMissiles.clear();
}
#pragma endregion

#pragma region render
void drawPlayer()
{
	gotoXY(g_x, g_y);
	std::cout << "¡ã";

	gotoXY(19, 39);
}

#pragma endregion

void checkCollision()
{
	bool bCollision = false;

	do
	{
		bCollision = false;
		for (int i = 0; i < (int)myMissiles.size(); ++i)
		{
			for (int j = 0; j < (int)enemies.size(); ++j)
			{
				if (myMissiles[i].checkCollision(enemies[j].getX(), enemies[j].getY()))
				{
					myMissiles.erase(myMissiles.begin() + i);
					enemies.erase(enemies.begin() + j);
					bCollision = true;
					//--i;
					//--j;
					break;
					
				}
			}
			if (bCollision == true) break;
		}
	} while (bCollision);

	do
	{
		bCollision = false;
		for (int i = 0; i < (int)enemyMissiles.size(); ++i)
		{
			for (int j = 0; j < (int)myMissiles.size(); ++j)
			{
				if (enemyMissiles[i].checkCollision(myMissiles[j].getX(), myMissiles[j].getY()))
				{
					//abort();
					enemyMissiles.erase(enemyMissiles.begin() + i);
					myMissiles.erase(myMissiles.begin() + j);
					bCollision = true;
					//--i;
					//--j;
					break;
					
				}
			}
			if (bCollision == true) break;
		}
	} while (bCollision);

	for (int i = 0; i < (int)enemyMissiles.size(); ++i)
	{
		if (enemyMissiles[i].checkCollision(g_x, g_y))
		{
			exit(0);
		}	
	}
}

void checkDirection()
{
	int key = _getch();

	switch (key)
	{
	case UP:
		if (g_y > 0)
		{
			--g_y;
		}
		break;

	case DOWN:
		if (g_y < 39)
		{
			++g_y;
		}
		break;

	case LEFT:
		if (g_x > 0)
		{
			--g_x;
		}
		break;

	case RIGHT:
		if (g_x < 39)
		{
			++g_x;
		}
		break;


	default:
		break;
	}

}