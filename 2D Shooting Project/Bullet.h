#pragma once
#include "Han.h"
#include "MoveableObjectPacket.h"

typedef Bullet* LPBULLET;

class Bullet // TODO : �Ѿ� �߻� ������ ���� ����
{
private:
	// Bullets ��Ƶδ� Vector<>
	// Bullet �� ���� ���� �Ʒ��� �� ��
	Vector2 pos;

public:

	CONSTRUCTOR Bullet();
	DESTRUCTOR ~Bullet();

	// �Ѿ� ������
	void move(int x, bool isRemote);

	// Vector getter
	Vector2 getVector();



	// TODO : �浹 üũ

};

