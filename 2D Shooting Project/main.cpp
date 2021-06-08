#include "MultiPlayer.h"
#include "Render.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>

// TODO : Ű ���� ���

int main()
{
	Render		render;	
	Player		player;
	Player		enemy;
	MultiPlayer server; // <= �÷��̾� ��ġ ������ �� ��ġ �޾Ƽ� ��Ŷ Ŭ������ �־���


#pragma region push_back to vectors

	render.addRenderObj(player.getVector(), player.getSprite());
	//render.addRenderObj(enemy.getVector(), enemy.getSprite());
	server.addPacket(*player.getPacketData());
	//server.addPacket(*enemy.getPacketData());

#pragma endregion // Multiplayer, Render

	//server.createTCPSocket();
	//if (server.establishConnection() == -1)
	//{
	//	return(-1);
	//}

	while (true)
	{
		system("cls");
		player.move();
		enemy.move(true);
		
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