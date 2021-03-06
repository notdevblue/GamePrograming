#include <Windows.h>
#include <conio.h>
#include <iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define SIZEY 21
#define SIZEX 20
#define PLUSNUM 10

#pragma region 전역변수
int g_curX;
int g_curY;
int g_befX;
int g_befY;

char g_map[SIZEX][SIZEY] =
{
	"++++++++++++++++++++",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"++++++++++++++++++++"
};
#pragma endregion

#pragma region 함수 선언

void gotoxy(int, int);
void display(bool b = false);
void move(int);
void generatePlus(); // 2번
void erasePlus(); // 3번
void eraseMirror(); // 심화 1번
#pragma endregion

int main()
{
	int ch;
	g_curX = 1;
	g_befX = 1;
	g_curY = 1;
	g_befY = 1;

	generatePlus();
	display(true);
	while (true)
	{
		display();
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
			switch(ch)
			{
			case 'q':
				system("cls");
				exit(0);
			case 'a':
				erasePlus();
				break;
			case 'b':
				eraseMirror();
				break;
			}
			
		}
	}
	

	return(0);
}

#pragma region 함수 정의

void gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(hOut, cur);
}

void display(bool isInit)
{
	if (isInit)
	{
		int x;
		int y;
		for (y = 0; y < SIZEX; ++y)
		{
			for (x = 0; x < SIZEY; ++x)
			{
				gotoxy(x, y);
				_putch(g_map[y][x]);
			}
		}
		
		
		gotoxy(25, 10);
		std::cout << "Q: 종료";
	}
	else
	{
		gotoxy(g_befX, g_befY);
		_putch('.');
	}
	gotoxy(g_curX, g_curY);
	_putch('O');
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

#pragma region 심화 2번
	if (g_curX + dirX == -1)
	{
		g_curX = SIZEY - 2;
		return;
	}
	if (g_curX + dirX == SIZEY - 1)
	{
		g_curX = 0;
		return;
	}

	if (g_curY + dirY == -1)
	{
		g_curY = SIZEX - 1;
		return;
	}
	if (g_curY + dirY == SIZEX)
	{
		g_curY = 0;
		return;
	}
#pragma endregion




	if (g_map[g_curY + dirY][g_curX + dirX] != '+')
	{
		g_befX = g_curX;
		g_befY = g_curY;
		g_curX += dirX;
		g_curY += dirY;
	}
	else
	{
		return;
	}

}

void generatePlus() // 2번
{
	srand(unsigned(time(NULL)));

	for (int i = 0; i < PLUSNUM; i)
	{
		int x = rand() % (SIZEY - 1);
		int y = rand() % SIZEX;

		if (g_map[y][x] != '+')
		{
			g_map[y][x] = '+';
			++i;
		}
	}
}

void erasePlus() // 3번
{
	bool leftXPossible = g_curX - 1 > 0;
	bool RightXPossible = g_curX + 1 < SIZEY - 2;
	bool UpYPossible = g_curY - 1 > 0;
	bool DownYPossible = g_curY + 1 < SIZEX - 1;


	if (g_curX != 0 && g_curX != SIZEY - 2) // 좌표 태두리일때 안 되게
	{
		if (UpYPossible)
		{
			g_map[g_curY - 1][g_curX] = '.';
		}
		if (DownYPossible)
		{
			g_map[g_curY + 1][g_curX] = '.';
		}
	}

	if (g_curY != 0 && g_curY != SIZEX)
	{
		if (leftXPossible)
		{
			g_map[g_curY][g_curX - 1] = '.';
		}
		if (RightXPossible)
		{
			g_map[g_curY][g_curX + 1] = '.';
		}
	}
}

void eraseMirror() // 심화 1번
{
	if (g_curY - 1 == 0 || g_curY + 1 == SIZEX - 1)
	{
		g_map[0][g_curX] = '.';
		g_map[SIZEX - 1][g_curX] = '.';
	}

	if (g_curX - 1 == 0 || g_curX + 1 == SIZEY - 2)
	{
		g_map[g_curY][0] = '.';
		g_map[g_curY][SIZEY - 2] = '.';
	}


}
#pragma endregion

