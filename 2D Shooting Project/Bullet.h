#pragma once
#include "Han.h"
#include "MoveableObjectPacket.h"

#define LPBULLET Bullet*

class Bullet // TODO : �Ѿ� �߻� ������ ���� ����
{
private:
	// Bullets ��Ƶδ� Vector<>
	// Bullet �� ���� ���� �Ʒ��� �� ��
	Vector2 pos;

	std::string originalSprite[1];

	Sprite sprite;

public:

	CONSTRUCTOR Bullet();
	DESTRUCTOR ~Bullet();

	// �Ѿ� ������
	void move(int x, bool isRemote);

	// Vector getter
	Vector2 getVector();

	// ��Ȱ��ȭ
	void disable(bool collision = true);


	// ��� üũ
	bool isEnabled;


	// ������ �浹
	bool collisionCheck(bool isRemote);
	void onCollision();
};

