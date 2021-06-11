#pragma once
#include "Han.h"
#include "Bullet.h"
#include <queue>

// Bullet Pool
// Unity 에서 PoolManager 만들어서 쓰는 것과 비슷한 동작을 합니다.
// template 으로 만들게되면 안그래도 배고픈 이 학생은 매우 엄청난 에너지를 빼앗겨 하루 5끼를 먹을 수 있게 됩니다.


class BulletPool
{
private:
	std::queue<LPBULLET> bulletPool;

public:

	static BulletPool* instance;

	CONSTRUCTOR BulletPool();
	DESTRUCTOR ~BulletPool();

	VOID addBullet();
	_Check_return_ LPBULLET getBullet();
};