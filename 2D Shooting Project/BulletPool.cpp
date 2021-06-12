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

// queue�� �ϳ� Ǫ������
VOID BulletPool::addBullet()
{
	bulletPool.push(new Bullet());
}