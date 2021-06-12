#include "Render.h"

#pragma region Thread

DWORD Render::renderThread()
{
	int i = 0;

	while (true) // ������ �ʿ���
	{
		draw();
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


void Render::draw()
{
	if (renderData.renderIndex < 1) return;
	int length = 0;

	for (int i = 0; i < renderData.renderIndex; ++i)
	{
		short yPos;
		short xPos;

#pragma region ���� �ʱ�ȭ �� null üũ
		// �� ���Ϳ��� at �ϸ� out_of_range
		if (renderData.renderObjs.empty())
			return;
		else
		{
			yPos = *renderData.renderObjs.at(i).y;
			xPos = *renderData.renderObjs.at(i).x;
		}

		// �� ���Ϳ��� at �ϸ� out_of_range
		if (renderData.renderStr.empty())
			return;
		else
		{
			length = renderData.renderStr.at(i).getLength();
		}
#pragma endregion


		// TODO : ��ũ�� ������ ��
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

// Ŭ���� ��� �Լ��� ������ ����
DWORD WINAPI Render::logicThreadLaunch(LPVOID lpParam)
{
	Render* This = (Render*)lpParam;
	return This->renderThread();
}

#pragma endregion