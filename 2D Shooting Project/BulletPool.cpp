#include "BulletPool.h"


#pragma region CONSTRUCTOR DESTRUCTOR

CONSTRUCTOR BulletPool::BulletPool()
{

}

DESTRUCTOR BulletPool::~BulletPool()
{
	// 메모리 할당 해제와 큐 비우기
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

// queue로 하나 푸쉬해줌
VOID BulletPool::addBullet()
{
	bulletPool.push(new Bullet());
}