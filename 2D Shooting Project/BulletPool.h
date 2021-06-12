#pragma once
#include "Han.h"
#include "Bullet.h"
#include <queue>

// Bullet Pool
// Unity ���� PoolManager ���� ���� �Ͱ� ����� ������ �մϴ�.
// template ���� ����ԵǸ� �ȱ׷��� ����� �� �л��� �ſ� ��û�� �������� ���Ѱ� �Ϸ� 5���� ���� �� �ְ� �˴ϴ�.


class BulletPool
{
private:
	std::queue<LPBULLET> bulletPool;
	
	CONSTRUCTOR BulletPool();

public:

	// singleton pattern
	// �ܺο��� �����ؾ� �ϱ� ������
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