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

	render.addRenderStr(sprite); // ���� �ּ�ó�� �ϸ� vector subscript out of range ������ ��
	render.addRenderPos(vector);
	


	



	return(0);
}