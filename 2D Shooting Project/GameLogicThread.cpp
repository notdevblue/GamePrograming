#include "GameLogic.h"

#pragma region Thread

DWORD GameLogic::logicThread()
{
	int i = 0;

	while (true)
	{
		draw();
		/*break;*/
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

// TODO : 여기서 Vector 밖으로 집 나감
void GameLogic::draw()
{
	if (renderData.renderIndex < 1) return;
	int length = 0;

	// renderData 안에 들어 있는 모든 것들을 돌림
	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		short	yPos = renderData.renderObjs.at(i).y;
		short	xPos = renderData.renderObjs.at(i).x;
		length = renderData.renderStr.at(i).getLength();

		gotoxy(yPos, xPos);

		CSLOCK
		{
			GetLock lock(*han_crit);
			for (int count = 0; count < length; ++length)
			{
				gotoxy(xPos, yPos + count);
				renderData.renderStr.at(i).print(count);
			}
		}

	}
}

// 클래스 멤버 함수로 돌리기 위함
DWORD WINAPI GameLogic::logicThreadLaunch(LPVOID lpParam)
{
	GameLogic* This = (GameLogic*)lpParam;
	return This->logicThread();
}

#pragma endregion