#include "BulletPool.h"


#pragma region CONSTRUCTOR DESTRUCTOR

CONSTRUCTOR BulletPool::BulletPool()
{

}

DESTRUCTOR BulletPool::~BulletPool()
{
	// �޸� �Ҵ� ������ ť ����
	try
	{
		while (!bulletPool.empty())
		{
			delete bulletPool.front();
			bulletPool.pop();
		}
	}
	catch (int e)
	{
		printf("Error at BulletPool destructor.\r\n");
		abort();
	}
	
}

#pragma endregion

LPBULLET BulletPool::getBullet()
{


	return;
}

// queue�� �ϳ� Ǫ������
VOID BulletPool::addBullet()
{
	bulletPool.push(new Bullet());
}