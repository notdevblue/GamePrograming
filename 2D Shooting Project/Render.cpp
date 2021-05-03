#include "Render.h"

void Render::gotoxy(SHORT x, SHORT y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Render::Render()
{
	renderIndex = 0;
	hRender = CreateThread(NULL, 0, renderThread, NULL, 0, NULL);
}

Render::~Render()
{
	CloseHandle(hRender);
}


DWORD WINAPI Render::renderThread(LPVOID lpParam)
{
	while (true)
	{
		//renderObject[renderIndex++ % renderObject.Count].Render();
	}


	return(0);
}