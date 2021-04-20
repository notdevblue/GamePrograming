/* (우엽 주석)

와 잠시만요 이거 가독성 왜이레요
죄송합니다.

 * 사실 다시 묶어서 정리해보려고 지난주에 마음을 먹었지만
	코감기인줄 알았으나 무지 심한 몸살에 걸려서 건강상태가 좋지 못했스빈다.

	* 코드를 작성하고 있는 지금은 기침만 어떻게 하면 건강한거 같스빈다.


	과제 코드 위치에
		기본 n번 과제
		심화 n번 과제

		// 기본 1번 과제
		// 심화 2번 과제

		처럼 주석을 남겨 놨어요.
		(빠른 과제 탐색)

*/

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

char g_stage[10][16] =
{
	"+++++++++++++++",
	"+++++++++++++++",
	"++++&  ++++++++",
	"++++ OO++++++++",
	"++++ O ++++.+++",
	"++++++ ++++.+++",
	"++++++     .+++",
	"+++++    +  +++",
	"++++@    @+++++",
	"+++++++++++++++"
};

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
	system("cls");
}

char g_bgMap[10][16];
int g_curX, g_curY;
int totalMove;

bool bPull;
bool bUpPull;
bool bDownPull;
bool bLeftPull;
bool bRightPull;
bool bIsSingle;

void initScreen()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			gotoXY(x, y);
			_putch(g_bgMap[y][x]);
		}
	}

	gotoXY(g_curX, g_curY);
	_putch('&');

	gotoXY(20, 2);
	puts("PushPush");

	gotoXY(20, 4);
	puts("Q : 종료");

	gotoXY(20, 6);
	printf("이동 횟수 : %d", totalMove);
}

bool checkEnd()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (g_stage[y][x] == '.' && g_bgMap[y][x] != 'O')
			{
				return false;
			}
		}
	}

	return true;
}

void move(int dir)
{
	int dirX = 0, dirY = 0;

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
	}

	if (g_bgMap[g_curY + dirY][g_curX + dirX] != '+')
	{
		if (g_bgMap[g_curY + dirY][g_curX + dirX] == 'O')
		{
			if (g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] == ' ' || g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] == '.')
			{
				if (g_stage[g_curY + dirY][g_curX + dirX] == '.')
				{
					g_bgMap[g_curY + dirY][g_curX + dirX] = '.';
				}
				else
				{
					g_bgMap[g_curY + dirY][g_curX + dirX] = ' ';
				}

				g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] = 'O';
			}
			else if (g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] == '@') // 기본 1번 과제	
			{
				
				for (int y = 0; y < 10; ++y)
				{
					for (int x = 0; x < 15; ++x)
					{
						if ((g_bgMap[y][x] == '@')   &&
							((y != g_curY + dirY * 2) || (x != g_curX + dirX * 2)))
						{
							Beep(1000, 50);
							g_bgMap[g_curY + dirY][g_curX + dirX] = ' ';
							g_bgMap[y][x] = 'O';
							g_bgMap[g_curY + dirY * 2][g_curX + dirX * 2] = ' ';
							break;
						}
					}
				}
			}
			else
			{
				return;
			}
		}

		if (bPull) // 기본 2번 과제
		{
			
			if (bUpPull)
			{
				if (g_stage[g_curY - 1][g_curX] == '.')
				{
					g_bgMap[g_curY - 1][g_curX] = '.';
				}
				else
				{
					g_bgMap[g_curY - 1][g_curX] = ' ';
				}
				g_bgMap[g_curY - 1 + dirY][g_curX + dirX] = '8';
			}
			if (bDownPull)
			{
				if (g_stage[g_curY + 1][g_curX] == '.')
				{
					g_bgMap[g_curY + 1][g_curX] = '.';
				}
				else
				{
					g_bgMap[g_curY + 1][g_curX] = ' ';
				}
				g_bgMap[g_curY + 1 + dirY][g_curX + dirX] = '8';
			}
			if (bRightPull)
			{
				if (g_stage[g_curY][g_curX + 1] == '.')
				{
					g_bgMap[g_curY][g_curX + 1] = '.';
				}
				else
				{
					g_bgMap[g_curY][g_curX + 1] = ' ';
				}
				g_bgMap[g_curY + dirY][g_curX + 1 + dirX] = '8';
			}
			if (bLeftPull)
			{
				if (g_stage[g_curY][g_curX - 1] == '.')
				{
					g_bgMap[g_curY][g_curX - 1] = '.';
				}
				else
				{
					g_bgMap[g_curY][g_curX - 1] = ' ';
				}
				g_bgMap[g_curY + dirY][g_curX - 1 + dirX] = '8';
			}


		}

		g_curX = g_curX + dirX;
		g_curY = g_curY + dirY;
		totalMove++;
	}
}

int main()
{
	int ch;

	memcpy(g_bgMap, g_stage, sizeof(g_bgMap));

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (g_bgMap[y][x] == '&')
			{
				g_curX = x;
				g_curY = y;
				g_bgMap[y][x] = ' ';
			}
		}
	}

	clrscr();

	totalMove = 0;
	bPull = false;

	while (true)
	{
		initScreen();

		ch = _getch();

		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();

			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);

			if (ch == 'q')
			{
				clrscr();
				exit(0);
			}
			else if (ch == 'p')
			{
				if (bPull)
				{
					if (bUpPull)
					{
						g_bgMap[g_curY - 1][g_curX] = 'O';
						bUpPull = false;
					}
					if (bDownPull)
					{
						g_bgMap[g_curY + 1][g_curX] = 'O';
						bDownPull = false;
					}
					if (bRightPull)
					{
						g_bgMap[g_curY][g_curX + 1] = 'O';
						bRightPull = false;
					}
					if (bLeftPull)
					{
						g_bgMap[g_curY][g_curX - 1] = 'O';
						bLeftPull = false;
					}
					bPull = false;
				}
				else // 심화 2번 과제
				{
					int objCount = 0;

					if (g_bgMap[g_curY - 1][g_curX] == 'O')
					{
						bUpPull = true;
						++objCount;
					}
					if (g_bgMap[g_curY + 1][g_curX] == 'O')
					{
						bDownPull = true;
						++objCount;
					}
					if (g_bgMap[g_curY][g_curX - 1] == 'O')
					{
						++objCount;
						bLeftPull = true;
					}
					if (g_bgMap[g_curY][g_curX + 1] == 'O')
					{
						++objCount;
						bRightPull = true;
					}
					

					bIsSingle = (objCount > 1) ? false : true;

					if (bIsSingle)
					{
						if (bUpPull)
						{
							g_bgMap[g_curY - 1][g_curX] = '8';
							bPull = true;
						}
						if (bDownPull)
						{
							g_bgMap[g_curY + 1][g_curX] = '8';
							bPull = true;
						}
						if (bRightPull)
						{
							g_bgMap[g_curY][g_curX + 1] = '8';
							bPull = true;
						}
						if (bLeftPull)
						{
							g_bgMap[g_curY][g_curX - 1] = '8';
							bPull = true;
						}
					}
					else
					{
						bUpPull = false;
						bDownPull = false;
						bRightPull = false;
						bLeftPull = false;
					}
				}
			}
		}

		if (checkEnd())
		{
			clrscr();

			gotoXY(10, 4);
			printf("CLEAR");

			_getch();
			clrscr();
			exit(0);
			break;
		}
	}

	return 0;
}