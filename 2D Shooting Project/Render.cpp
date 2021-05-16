#include "Render.h"

#pragma region gotoxy

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

	hRender = CreateThread(NULL, 0, renderThreadStart, this, 0, NULL);
}

DESTRUCTOR Render::~Render()
{
	//vector subscript out of range 1508
	if (WaitForSingleObject(hRender, INFINITE) == WAIT_OBJECT_0)
	{
		printf("����\r\n");
	}

	CloseHandle(hRender);
}

#pragma endregion

void Render::addRenderPos(const Vector2& pos)
{
	printf("%p : %d\r\n", &renderData, __LINE__);
	renderData.renderObjs.push_back(pos);
	++renderData.renderIndex;
}

void Render::addRenderStr(const Sprite& sprite)
{
	// TODO : std::out_of_range
	renderData.renderStr.push_back(sprite);
}


#pragma region Thread

DWORD Render::renderThread()
{
	int i = 0;

	while (true)
	{
		draw();
		break;
	}


	return(0);
}

// TODO : ���⼭ Vector ������ �� ����
void Render::draw()
{
	if (renderData.renderIndex < 1) return;
		int length = 0;

	// renderData �ȿ� ��� �ִ� ��� �͵��� ����
	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		printf("%d : %d\r\n", renderData.renderIndex, __LINE__);
		printf("%llu : %d\r\n", renderData.renderObjs.capacity(), __LINE__);
		printf("%llu : %d\r\n", renderData.renderStr.capacity(), __LINE__);

		//short	yPos	= renderData.renderObjs[i].y;
		//short	xPos	= renderData.renderObjs[i].x;
		//		length	= renderData.renderStr[i].getLength();
		short	yPos	= renderData.renderObjs.at(i).y;
		short	xPos	= renderData.renderObjs.at(i).x;
				length	= renderData.renderStr.at(i).getLength();

		gotoxy(yPos, xPos);

		// \r\n ���� x ��ǥ�� 0�� �Ǳ� ����
		for (int count = 0; count < length; ++length)
		{
			gotoxy(xPos, yPos + count);
			renderData.renderStr.at(i).print(count);
		}
	}
}

// Ŭ���� ��� �Լ��� ������ ����
DWORD WINAPI Render::renderThreadStart(LPVOID lpParam)
{
	Render* This = (Render*)lpParam;
	return This->renderThread();
}

#pragma endregion