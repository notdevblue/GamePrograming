#include "Render.h"

void Render::gotoxy(SHORT x, SHORT y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Render::gotoxy(Vector2 vectorPos)
{
	COORD pos = { vectorPos.x, vectorPos.y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#pragma region Constructor, Destructor

Render::Render()
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
	hRender = CreateThread(NULL, 0, renderThread, &renderData, 0, NULL);
}

Render::~Render()
{
	if (WaitForSingleObject(hRender, INFINITE) == WAIT_OBJECT_0)
	{
		printf("성공\r\n");
	}

	CloseHandle(hRender);
}

#pragma endregion

void Render::addRenderPos(Vector2 pos)
{
	renderData.renderObjs.push_back(pos);
	++renderData.renderIndex;
}

void Render::addRenderStr(Sprite sprite)
{
	renderData.renderStr.push_back(sprite);
}

DWORD WINAPI Render::renderThread(LPVOID lpParam)
{
	RenderData* renderData = (RenderData*)lpParam;


	while (false) // TODO : 나중에 조건문 넣어야함
	{
		for (int i = 0; i < renderData->renderIndex; ++i)
		{
			renderData->renderObjs[i];	// TODO : gotoXY
			renderData->renderStr[i];	// TODO : printf
		}

	}


	return(0);
}