#include "Render.h"
#include <iostream>


int main()
{
	std::string spr[3] =
	{
		"###",
		"###",
		"###"
	};


	Render render;
	Vector2 vector(10, 10);
	Sprite sprite(3, spr);

	render.addRenderPos(vector);
	render.addRenderStr(sprite); // 여기 주석처리 하면 vector subscript out of range 오류가 뜸


	printf("와센즈\r\n");
	

	printf("###\r\n");
	printf("###\r\n");
	printf("###\r\n");



	return(0);
}