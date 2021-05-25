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


	GameLogic render;
	Vector2 vector(10, 10);
	Sprite sprite(3, spr);

	render.addRenderStr(sprite); // 여기 주석처리 하면 vector subscript out of range 오류가 뜸
	render.addRenderPos(vector);
	


	



	return(0);
}