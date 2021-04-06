#include <Windows.h>
#include <iostream>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int g_currentX;
int g_currentY;

char g_map[3][4] =
{
	"...",
	"...",
	"..."
};