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


public:

	CONSTRUCTOR Bullet();
	DESTRUCTOR ~Bullet();

	// �Ѿ� ������
	void move(int x, bool isRemote);

	// Vector getter
	Vector2 getVector();

	void disable();


	// ��� üũ
	bool isEnabled;


	// TODO : �浹 üũ

};

