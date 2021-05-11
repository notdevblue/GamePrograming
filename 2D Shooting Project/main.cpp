#include "Render.h"
#include <iostream>
// ≈¨∑°Ω∫ º≥∞Ë«œ∞Ì ¬•æﬂ«“µÌ »Ï»Ï»Ï»Ï»Ï»Ï»Ï»Ï

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
	render.addRenderStr(sprite);


	printf("øÕºæ¡Ó\r\n");
	

	//printf("###\r\n");
	//printf("###\r\n");
	//printf("###\r\n");



	return(0);
}