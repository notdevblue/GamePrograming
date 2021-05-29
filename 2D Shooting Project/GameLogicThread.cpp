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


	// GameLogic ���� WaitForSingleObject �ؼ� main.cpp ������ �̺�Ʈ ����� �ϳ� ��������.
	if (!SetEvent(hThreadEndEvent))
	{
		printf("SetEvent error at %s, line: %d\r\nExitting.\r\n", __FUNCTION__, __LINE__);
		system("pause");
		exit(-1);
	}

	return(0);
}

// TODO : ���⼭ Vector ������ �� ����
void GameLogic::draw()
{
	if (renderData.renderIndex < 1) return;
	int length = 0;

	// renderData �ȿ� ��� �ִ� ��� �͵��� ����
	// std_out_of_range ������ ���ľ� ��
	// ���� �̽�
	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		short yPos;
		short xPos;

		// �� ���Ϳ��� at �ϸ� out_of_range
		if (renderData.renderObjs.empty())
			return;
		else
		{
			yPos = renderData.renderObjs.at(i).y;
			xPos = renderData.renderObjs.at(i).x;
		}

		// �� ���Ϳ��� at �ϸ� out_of_range
		if (renderData.renderStr.empty())
			return;
		else
		{
			length = renderData.renderStr.at(i).getLength();
		}
		
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

// Ŭ���� ��� �Լ��� ������ ����
DWORD WINAPI GameLogic::logicThreadLaunch(LPVOID lpParam)
{
	GameLogic* This = (GameLogic*)lpParam;
	return This->logicThread();
}

#pragma endregion