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
		printf("Mostly it is queue\r\nLine %d", __LINE__);
		abort();
	}
}

#pragma endregion

_Check_return_ LPBULLET BulletPool::getBullet()
{
	if (!bulletPool.front()->isEnabled)
	{
		bulletPool.front()->isEnabled;
		Bullet* temp =  bulletPool.front();
		bulletPool.pop();
		bulletPool.push(temp);
		return temp;
	}
	else
	{
		Bullet* temp = new Bullet();
		temp->isEnabled = true;
		bulletPool.push(temp);
		return temp;
	}
}

// queue로 하나 푸쉬해줌
VOID BulletPool::addBullet()
{
	bulletPool.push(new Bullet());
}