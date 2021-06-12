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
	
	CONSTRUCTOR BulletPool();

public:

	// singleton pattern
	// 외부에서 접근해야 하기 때문에
	inline static BulletPool& instance()
	{
		static BulletPool* bulletPool = new BulletPool();
		return *bulletPool;
	}



	DESTRUCTOR ~BulletPool();

	VOID addBullet();
	bool instantiated;

	_Check_return_ LPBULLET getBullet();
};