#include <iostream>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int		g_curX;
int		g_curY;
int		g_totalfill;
char	g_fillstatus[3][4]	= { "   ","   ","   " };
char	g_map[10][10]		=
{
	"+++++++++",
	"+++++++++",
	"++.|.|.++",
	"++-----++",
	"++.|.|.++",
	"++-----++",
	"++.|.|.++",
	"++-----++",
	"+++++++++",
	"+++++++++"
};

void	gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}


void	render();
void	move(int dir);
bool	userSelect();
void	aiSelect();
void	endResult(int gameEnd);
// 0 not ended, 1 win, 2 lose, 3 draw
int		checkGame();

int main()
{
	int ch			= 0;
	int gameEnd		= 0; // 0 not ended, 1 win, 2 lose, 3 draw
		g_curX		= 2;
		g_curY		= 3;
		g_totalfill = 0;

	srand((unsigned)time(NULL));

	do
	{
		render();
		ch = _getch();
		if (ch == 0xE0 || ch == 0) { move(_getch()); }
		else
		{
			bool breakWhile = false;

			ch = tolower(ch);

			switch (ch)
			{
			case 'o':
				system("cls");
				return(0);
				break;

			case 'z':

				// 유저 입력 게임종료 체크
				if (!userSelect()) continue;
				render();
				gameEnd = checkGame();

				if (gameEnd != 0) { breakWhile = true; break; }

				// 컴퓨터 입력 게임종료 체크
				aiSelect();
				render();
				gameEnd = checkGame();
				
				if (gameEnd != 0) { breakWhile = true; break; }
				
				break;
			}

			if (breakWhile) break;
		}

	} while (!gameEnd);
	
	
	endResult(gameEnd);



	return(0);
}

void render()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			gotoxy(x, y);
			_putch(g_map[y][x]);
		}
	}

	gotoxy(g_curX, g_curY);
	_putch('^');


	gotoxy(12, 2);
	puts("Z: 선택");

	gotoxy(12, 4);
	puts("^: 위치");

	gotoxy(12, 6);
	puts("O: 종료");

	gotoxy(12, 12);
}

void move(int dir)
{
	int dirX = 0;
	int dirY = 0;

	switch (dir)
	{
	case LEFT:
		dirX = -2;
		break;

	case RIGHT:
		dirX = 2;
		break;

	case UP:
		dirY = -2;
		break;

	case DOWN:
		dirY = 2;
		break;

	default:
		break;
	}

	if (g_map[g_curY + dirY][g_curX + dirX] == '-')
	{
		g_curY += dirY;
		g_curX += dirX;
	}
}

bool userSelect()
{
	int x;
	int y;

	x = g_curX / 2 - 1;					// 2 4 6 => 0 1 2
	y = g_curY / 2 - 1;					// 3 5 7 => 0 1 2

	if (g_fillstatus[x][y] == ' ')
	{
		g_fillstatus[x][y] = '1';	// 맵[y][x] 대부분[x][y]
		g_map[g_curY - 1][g_curX] = '0';
		return true;
	}
	return false;
}

void aiSelect()
{
	int x;
	int y;

	do
	{
		x = rand() % 3;
		y = rand() % 3;
	} while (g_fillstatus[x][y] != ' ');

	g_curX = (x + 1) * 2;		// 0 1 2 => 2 4 6	
	g_curY = (y + 1) * 2 + 1;	// 0 1 2 => 3 5 7
	g_fillstatus[x][y]			= '2';
	g_map[g_curY - 1][g_curX]	= 'X';
}

// 0 not ended, 1 win, 2 lose, 3 draw
int checkGame()
{
	++g_totalfill;

	for (int x = 0; x < 3; ++x)
	{
		if (g_fillstatus[0][x] == '1' && g_fillstatus[1][x] == '1' && g_fillstatus[2][x] == '1') return(1);
		if (g_fillstatus[x][0] == '1' && g_fillstatus[x][1] == '1' && g_fillstatus[x][2] == '1') return(1);
		if (g_fillstatus[0][0] == '1' && g_fillstatus[1][1] == '1' && g_fillstatus[2][2] == '1') return(1);
		if (g_fillstatus[2][0] == '1' && g_fillstatus[1][1] == '1' && g_fillstatus[0][2] == '1') return(1);

		if (g_fillstatus[0][x] == '2' && g_fillstatus[1][x] == '2' && g_fillstatus[2][x] == '2') return(2);
		if (g_fillstatus[x][0] == '2' && g_fillstatus[x][1] == '2' && g_fillstatus[x][2] == '2') return(2);
		if (g_fillstatus[0][0] == '2' && g_fillstatus[1][1] == '2' && g_fillstatus[2][2] == '2') return(2);
		if (g_fillstatus[2][0] == '2' && g_fillstatus[1][1] == '2' && g_fillstatus[0][2] == '2') return(2);
	}

	if (g_totalfill == 9)
		return(3);
	return(0);
}

void endResult(int gameEnd)
{
	gotoxy(10, 8);

	switch (gameEnd)
	{
	case 1:
		puts("당신이 이겼습니다.");
		break;

	case 2:
		puts("당신이 졌습니다.");
		break;

	case 3:
		puts("비겼습니다.");
		break;

	default:
		puts("?");
		break;
	}
}