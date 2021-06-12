#include "MultiPlayer.h"
#include "Render.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>

// TODO : 키 매핑 기능

//// 프로젝트 스스로 평가한 주석
// 싱글톤 패턴을 남용한 프로젝트.
// 메모리 매우 비효율적
// 많은 스레드
// 많은 조건부 무한루프
// 많은 동시에 실행되는 스레드
// 비효율적인 멀티스레드 서버, 클라이언트
// 한줄로 렌더 오브젝트와 페킷 추가는 좋았음

// 결론: 만드는건 잘 했지만 코드 꼴이 매우.

// WARN , BUG , TODO : 잘못된 Singleton 사용.

int main()
{
	Render		render;	// <= 싱글톤 패턴으로 처리함
	Player		player;
	Player		enemy;
	MultiPlayer server; // <= 플레이어 위치 보내고 적 위치 받아서 페킷 클레스에 넣어줌
	


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


#pragma region 스레드 종료 대기

	if (WaitForSingleObject(render.getEventHandle(), INFINITE) != WAIT_OBJECT_0)
	{
		std::cerr << "event handle error at " << __FUNCTION__ << ", line: " << __LINE__ << std::endl;
		return(-1);
	}

#pragma endregion

	return(0);
}