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

public:

	CONSTRUCTOR BulletPool();
	DESTRUCTOR ~BulletPool();

	VOID addBullet();
	LPBULLET getBullet();



};