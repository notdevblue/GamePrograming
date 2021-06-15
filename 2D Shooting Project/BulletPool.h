#pragma once
#include "Han.h"
#include "Bullet.h"
#include <queue>

// Bullet Pool
// Unity ���� PoolManager ���� ���� �Ͱ� ����� ������ �մϴ�.
// template ���� ����ԵǸ� �ȱ׷��� ����� �� �л��� �ſ� ��û�� �������� ���Ѱ� �Ϸ� 5���� ���� �� �ְ� �˴ϴ�.


/*

�ڰǽ��� �ǰ�
- �Ѿ� ��ü�� �׳� �������� �������� 



*/

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

	std::queue<LPBULLET>* getBulletPool();

	DESTRUCTOR ~BulletPool();

	VOID addBullet();

	_Check_return_ LPBULLET getBullet();
};