#include "GameLogic.h"
#include <iostream>




int main()
{
	

	std::string spr[3] =
	{
		"###",
		"###",
		"###"
	};


	GameLogic gameLogic;
	Vector2 vector(10, 10);
	Sprite sprite(3, spr);



	gameLogic.addRenderStr(sprite);
	gameLogic.addRenderPos(vector);
	


	if (WaitForSingleObject(gameLogic.getEventHandle(), INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "event handle error at " << __FUNCTION__ << ", line: " << __LINE__ << std::endl;
		return(-1);
	}



	return(0);
}