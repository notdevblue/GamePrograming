#pragma once
#include "Han.h"
#include "MoveableObjectPacket.h"

class Bullet // TODO : �Ѿ� �߻� ������ ���� ����
{
private:
	bool isRemote;
	short x;
	// Bullets ��Ƶδ� Vector<>
	// Bullet �� ���� ���� �Ʒ��� �� ��
	Vector2 pos;

public:

	CONSTRUCTOR Bullet(short x, bool isRemote = false);
	DESTRUCTOR ~Bullet();

	// �Ѿ� ������
	void move();

	// Vector getter
	Vector2 getVector();



	// TODO : �浹 üũ

};

