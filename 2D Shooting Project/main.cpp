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
	render.addRenderStr(sprite); // ���� �ּ�ó�� �ϸ� vector subscript out of range ������ ��


	printf("�ͼ���\r\n");
	

	printf("###\r\n");
	printf("###\r\n");
	printf("###\r\n");



	return(0);
}