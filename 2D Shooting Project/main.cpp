#include "Render.h"
#include "Player.h"
#include <iostream>




int main()
{
	Render render;	
	Player player;
	
#pragma region push_back to render vector

	render.addRenderObj(player.getVector(), player.getSprite());


#pragma endregion


	while (true)
	{
		system("cls");
		player.move();


		
		Sleep(1000 / 60); // 60fps
	}


#pragma region ������ ���� ���

	if (WaitForSingleObject(render.getEventHandle(), INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "event handle error at " << __FUNCTION__ << ", line: " << __LINE__ << std::endl;
		return(-1);
	}

#pragma endregion

	return(0);
}