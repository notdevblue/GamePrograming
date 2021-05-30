#include "Render.h"



#pragma region gotoxy

void Render::gotoxy(SHORT x, SHORT y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Render::gotoxy(Vector2 vectorPos)
{
	COORD pos = { *vectorPos.x, *vectorPos.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#pragma endregion

#pragma region Constructor, Destructor

CONSTRUCTOR Render::Render()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = FONT_SIZE;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	renderData.renderIndex = 0;
	renderData.renderObjs.reserve(10);
	renderData.renderStr.reserve(10);

	hThreadEndEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	han_crit = new CriticalSection();

	hRender = CreateThread(NULL, 0, logicThreadLaunch, this, 0, NULL);
}

DESTRUCTOR Render::~Render()
{
	delete han_crit;

	//vector subscript out of range 1508
	if (WaitForSingleObject(hRender, INFINITE) == WAIT_OBJECT_0)
	{
		printf("¼º°ø\r\n");
	}

	CloseHandle(hRender);
	CloseHandle(hThreadEndEvent);
}

#pragma endregion

const HANDLE Render::getEventHandle()
{
	return hThreadEndEvent;
}

void Render::addRenderObj(const Vector2& pos, const Sprite& sprite)
{
	renderData.renderStr.push_back(sprite);
	renderData.renderObjs.push_back(pos);
	++renderData.renderIndex;
}