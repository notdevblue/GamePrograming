#include "GameLogic.h"



#pragma region gotoxy

void GameLogic::gotoxy(SHORT x, SHORT y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void GameLogic::gotoxy(Vector2 vectorPos)
{
	COORD pos = { *vectorPos.x, *vectorPos.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#pragma endregion

#pragma region Constructor, Destructor

CONSTRUCTOR GameLogic::GameLogic()
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

DESTRUCTOR GameLogic::~GameLogic()
{
	delete han_crit;

	//vector subscript out of range 1508
	if (WaitForSingleObject(hRender, INFINITE) == WAIT_OBJECT_0)
	{
		printf("성공\r\n");
	}

	CloseHandle(hRender);
	CloseHandle(hThreadEndEvent);
}

#pragma endregion

const HANDLE GameLogic::getEventHandle()
{
	return hThreadEndEvent;
}

void GameLogic::addRenderPos(const Vector2& pos)
{
	// 설계 미스
	renderData.renderObjs.push_back(pos);
	++renderData.renderIndex;
}

void GameLogic::addRenderStr(const Sprite& sprite)
{
	// 설계 미스
	renderData.renderStr.push_back(sprite);
}