#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#pragma region Define

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

#define SIZEY 10
#define SIZEX 16

#pragma endregion

#pragma region 변수
char g_stage[SIZEY][SIZEX] =
{
	"+++++++++++++++",
	"+++++++++++++++",
	"++++&  ++++++++",
	"++++ OO++++++++",
	"++++ O ++++.+++",
	"++++++ ++++.+++",
	"++++++     .+++",
	"+++++    +  +++",
	"+++++    ++++++",
	"+++++++++++++++"
};
char g_bgMap[SIZEY][SIZEX];

int g_curX;
int g_curY;
int g_totalMove;

#pragma endregion


#pragma region 함수 선언
void gotoXY(int x, int y);
void initScreen();
void findPlayer();
void move(int);
bool checkEnd();
#pragma endregion


int main()
{
	memcpy(g_bgMap, g_stage, sizeof(g_bgMap));

	
	findPlayer();
	initScreen();

	gotoXY(20, 20);

	return(0);
}



#pragma region 함수 정의



void initScreen()
{
	for (int y = 0; y < SIZEY; ++y)
	{
		for (int x = 0; x < SIZEX - 1; ++x)
		{
			gotoXY(x, y);
			_putch(g_bgMap[y][x]);
		}
	}

	gotoXY(g_curX, g_curY);
	_putch('&');
}

void findPlayer()
{
	for (int y = 0; y < SIZEY; ++y)
	{
		for (int x = 0; x < SIZEX - 1; ++x)
		{
			if (g_stage[y][x] == '&')
			{
				g_curX = x;
				g_curY = y;
				g_bgMap[y][x] = ' ';
			}
		}
	}
}

void move(int dir)
{
	int dirX = 0;
	int dirY = 0;

	switch (dir)
	{
	case LEFT:
		dirX = -1;
		break;

	case RIGHT:
		dirX = 1;
		break;

	case UP:
		dirY = -1;
		break;

	case DOWN:
		dirY = 1;
		break;

	default:
		break;
	}

	if (g_bgMap[g_curY + dirY][g_curX + dirX] != '+')
	{
		if (g_bgMap[g_curY + dirY][g_curX + dirX] == '0')
		{
			if (g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] == ' ' || g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] == '.')
			{
				if (g_stage[g_curY + dirY][g_curX + dirX] == ' ')
				{
					g_bgMap[g_curY + dirY][g_curX + dirX] = ' ';
				}
				else if (g_stage[g_curY + dirY][g_curX + dirX] == '.')
				{
					g_bgMap[g_curY + dirY][g_curX + dirX] = '.';
				}

				g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] = '0';
			}
		}
		g_curX += dirX;
		g_curY += dirY;
	}
}

bool checkEnd()
{
	for (int y = 0; y < SIZEY; ++y)
	{
		for (int x = 0; x < SIZEX - 1; ++x)
		{
			if (g_stage[y][x] == '.' && g_bgMap[y][x] != '0')
			{
				return false;
			}
		}
	}
	return true;
}

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

#pragma endregion
