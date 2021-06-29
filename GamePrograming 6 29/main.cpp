#include <iostream>
#include <time.h>
#include "Console.h"

#define MAP_X 4
#define MAP_Y 2

#define KEY_DIRECTION	224
#define KEY_LEFT		75
#define KEY_RIGHT		77
#define KEY_UP			72
#define KEY_DOWN		80

int g_board[4][4] =
{
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
};

bool g_bGameOver = false;


void setConsoleView();
void initData();
void initDraw();

void drawGame();
void createNum();
void getKey();
bool moveNumber(int sX, int sY, int tX, int tY);
void checkGameover();

int main()
{
	srand((unsigned)time(NULL));

	setNoCursor();
	setConsoleView();

	initData();
	initDraw();

	createNum();
	createNum();

	
	while (true)
	{
		getKey();
		checkGameover();
	}
}


void setConsoleView()
{
	system("mode con:cols=32 lines=26");
	system("title 2048 Game");
}

void initData()
{
	setTextColor(15);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			g_board[i][j] = 0;
		}
	}

	g_bGameOver = false;
}

void initDraw()
{
	gotoXY(MAP_X - 2, MAP_Y - 1);
	std::cout << "|---------------------|" << '\n';
	
	for (int i = 0; i < 12; ++i)
	{
		gotoXY(MAP_X - 2, MAP_Y + i);
		std::cout << "|                     |" << '\n';
	}

	gotoXY(MAP_X - 2, MAP_Y + 12);
	std::cout << "|---------------------|" << '\n';

	gotoXY(MAP_X - 1, MAP_Y + 14);
	std::cout << "¡æ, ¡ç, ¡è, ¡é : ÀÌµ¿";
}

void drawGame()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (g_board[i][j] == 0)
			{
				setTextColor(8);
				gotoXY(MAP_X + j * 5, MAP_Y + i * 3);
				std::cout << "     ";
				gotoXY(MAP_X + j * 5, MAP_Y + i * 3 + 1);
				std::cout << "  +  ";
				gotoXY(MAP_X + j * 5, MAP_Y + i * 3 + 2);
				std::cout << "     ";
			}
			else
			{
				int sum = 1;
				int num = g_board[i][j] > 10000 ? g_board[i][j] - 10000 : g_board[i][j];
				for (int k = 0; k < 12; k++)
				{
					sum *= 2;

					if (sum == num)
					{
						if (g_bGameOver)
						{
							setTextColor(8);
						}
						else
						{
							setTextColor(k + 1);
						}
						break;
					}
				}

				gotoXY(MAP_X + j * 5, MAP_Y + i * 3);
				std::cout << "|---|";
				gotoXY(MAP_X + j * 5, MAP_Y + i * 3 + 1);
				printf("%4d ", num);
				gotoXY(MAP_X + j * 5, MAP_Y + i * 3 + 2);
				std::cout << "|---|";

				if (g_bGameOver) Sleep(200);
			}
		}
	}

	Sleep(50);
}

void createNum()
{
	int* empty[16] = { 0 };
	int count = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (g_board[i][j] == 0)
			{
				empty[count++] = &g_board[i][j];
			}
		}
	}

	int rnd = rand() % count;
	int num = rand() % 100 < 20 ? 4 : 2;

	*empty[rnd] = num;
	drawGame();
	*empty[rnd] = 0;
	drawGame();
	*empty[rnd] = num;
	drawGame();
}

void getKey()
{
	bool bMove = false;
	bool bChange = false;

	int key = _getch();

	if (key == KEY_DIRECTION)
	{
		key = _getch();

		switch(key)
		{
		case KEY_LEFT:
			do
			{
				bMove = false;

				for (int i = 0; i < 4; ++i)
				{
					for (int j = 1; j < 4; ++j)
					{
						if (moveNumber(j, i, j - 1, i))
						{
							bMove = true;
							bChange = true;
						}
					}
				}

				if (bMove) drawGame();
			} while (bMove);
			break;

		case KEY_RIGHT:
			do
			{
				bMove = false;

				for (int i = 0; i < 4; ++i)
				{
					for (int j = 2; j >= 0; --j)
					{
						if (moveNumber(j, i, j + 1, i))
						{
							bMove = true;
							bChange = true;
						}
					}
				}

				if (bMove) drawGame();
			} while (bMove);
			break;

		case KEY_UP:
			do
			{
				bMove = false;

				for (int i = 1; i < 4; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						if (moveNumber(j, i, j, i - 1))
						{
							bMove = true;
							bChange = true;
						}
					}
				}

				if (bMove) drawGame();
			} while (bMove);
			break;

		case KEY_DOWN:
			do
			{
				bMove = false;

				for (int i = 2; i >= 0; --i)
				{
					for (int j = 0; j < 4; ++j)
					{
						if (moveNumber(j, i, j, i + 1))
						{
							bMove = true;
							bChange = true;
						}
					}
				}

				if (bMove) drawGame();
			} while (bMove);
			break;
		}
	}


	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (g_board[i][j] > 10000)
			{
				g_board[i][j] -= 10000;
			}
		}
	}

	if (bChange)
	{
		createNum();
	}
}

bool moveNumber(int sX, int sY, int tX, int tY)
{
	if (g_board[sY][sX] == 0 || g_board[sY][sX] > 10000) return false;
	if (g_board[tY][tX] != 0 && g_board[tY][tX] != g_board[sY][sX]) return false;

	if (g_board[tY][tX] == 0)
	{
		g_board[tY][tX] = g_board[sY][sX];
	}
	else if (g_board[tY][tX] == g_board[sY][sX])
	{
		g_board[tY][tX] *= 2;
		g_board[tY][tX] += 10000;
	}

	g_board[sY][sX] = 0;

	return true;
}

void checkGameover()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (g_board[i][j] == 0) return;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (g_board[i][j] == g_board[i][j + 1] || g_board[i][j] == g_board[i + 1][j]) return;
			
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if (g_board[i][3] == g_board[i + 1][3])return;
		if (g_board[3][i] == g_board[3][i + 1])return;
	}

	gotoXY(MAP_X + 6, MAP_Y + 21);
	setTextColor(15);
	std::cout << "GAME OVER\r\n";
	g_bGameOver = true;
	drawGame();
}