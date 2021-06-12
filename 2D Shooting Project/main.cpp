#include "MultiPlayer.h"
#include "Render.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>

// TODO : Ű ���� ���

//// ������Ʈ ������ ���� �ּ�
// �̱��� ������ ������ ������Ʈ.
// �޸� �ſ� ��ȿ����
// ���� ������
// ���� ���Ǻ� ���ѷ���
// ���� ���ÿ� ����Ǵ� ������
// ��ȿ������ ��Ƽ������ ����, Ŭ���̾�Ʈ
// ���ٷ� ���� ������Ʈ�� ��Ŷ �߰��� ������

// ���: ����°� �� ������ �ڵ� ���� �ſ�.

// WARN , BUG , TODO : �߸��� Singleton ���.

int main()
{
	Render		render;	// <= �̱��� �������� ó����
	Player		player;
	Player		enemy;
	MultiPlayer server; // <= �÷��̾� ��ġ ������ �� ��ġ �޾Ƽ� ��Ŷ Ŭ������ �־���
	


#pragma region push_back to vectors

	render.addRenderObj(player.getVector(), player.getSprite(), &player.enabled);
	//render.addRenderObj(enemy.getVector(), enemy.getSprite(), &enemy.enabled); 
	server.addPacket(*player.getPacketData());
	//server.addPacket(*enemy.getPacketData());

#pragma endregion // Multiplayer, Render

#pragma region Server Connection

	//server.createTCPSocket();
	//if (server.establishConnection() == -1)
	//{
	//	return(-1);
	//}

#pragma endregion

	player.enabled = true;
	enemy.enabled  = true;

	while (true)
	{

		player.move();
		player.shoot();
		//enemy.move(true);
		//enemy.shoot();
		system("cls");
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