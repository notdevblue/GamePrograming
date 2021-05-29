#include "GameLogic.h"
#include <iostream>




int main()
{
	

	std::string spr[3] =
	{
		"111",
		"222",
		"333"
	};


	GameLogic gameLogic;
	
	short tempX = 10;
	short tempY = 10;
	


	Vector2 vector(&tempX, &tempY);
	Sprite sprite(2, spr);



	gameLogic.addRenderStr(sprite);
	gameLogic.addRenderPos(vector);
	

	short moveY = 1;
	while (true)
	{
		if (tempY > 20)
		{
			moveY = -1;
		}
		if (tempY < 1)
		{
			moveY = 1;
		}
		tempY += moveY;
		system("cls");
		Sleep(250);
	}


	if (WaitForSingleObject(gameLogic.getEventHandle(), INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "event handle error at " << __FUNCTION__ << ", line: " << __LINE__ << std::endl;
		return(-1);
	}



	return(0);
}