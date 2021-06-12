#include "Render.h"

#pragma region Thread

DWORD Render::renderThread()
{
	int i = 0;

	while (true) // 조건이 필요함
	{
		draw();
	}


	// GameLogic 에서 WaitForSingleObject 해서 main.cpp 용으로 이벤트 헨들을 하나 만들었어요.
	if (!SetEvent(hThreadEndEvent))
	{
		printf("SetEvent error at %s, line: %d\r\nExitting.\r\n", __FUNCTION__, __LINE__);
		system("pause");
		exit(-1);
	}

	return(0);
}


void Render::draw()
{
	if (renderData.renderIndex < 1) return;
	int length = 0;

	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		short yPos;
		short xPos;

#pragma region 변수 초기화 및 null 체크
		// 빈 박터에서 at 하면 out_of_range
		if (renderData.renderObjs.empty())
			return;
		else
		{
			yPos = *renderData.renderObjs.at(i).y;
			xPos = *renderData.renderObjs.at(i).x;
		}

		// 빈 백터에서 at 하면 out_of_range
		if (renderData.renderStr.empty())
			return;
		else
		{
			length = renderData.renderStr.at(i).getLength();
		}
#pragma endregion


		// TODO : 메크로 만들어야 함
		CSLOCK
		{
			GetLock lock(*han_crit);
			for (int count = 0; count < length; ++count)
			{
				gotoxy(xPos, yPos + count);
				renderData.renderStr.at(i).print(count);
			}
		};

	}
}

// 클래스 멤버 함수로 돌리기 위함
DWORD WINAPI Render::logicThreadLaunch(LPVOID lpParam)
{
	Render* This = (Render*)lpParam;
	return This->renderThread();
}

#pragma endregion