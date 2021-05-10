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
	hRender = CreateThread(NULL, 0, renderThreadStart, &renderData, 0, NULL);
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


#pragma region Thread

DWORD Render::renderThread()
{
	while (false)
	{
		draw();
	}


	return(0);
}

void Render::draw()
{
	int y = 0;

	// renderData 안에 들어 있는 모든 것들을 돌림
	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		float	yPos	= renderData.renderObjs[i].y;
		float	xPos	= renderData.renderObjs[i].x;
				y		= renderData.renderStr[i].getYsize();

		gotoxy(yPos, xPos);

		// \r\n 쓰면 x 좌표가 0이 되기 때문
		for (int count = 0; count < y; ++y)
		{
			gotoxy(xPos, yPos + count);
			renderData.renderStr[i].print(count);
		}
	}

}

// 클래스 멤버 함수로 돌리기 위함
DWORD WINAPI Render::renderThreadStart(LPVOID lpParam)
{
	Render* This = (Render*)lpParam;
	return This->renderThread();
}

#pragma endregion