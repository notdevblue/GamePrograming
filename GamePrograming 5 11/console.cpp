#include "Console.h"
#include <Windows.h>
#include <conio.h>


void gotoxy(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void beep(int tone, int delay)
{
	Beep(tone, delay);
}

void sleep(int delay)
{
	Sleep(delay);
}