#pragma once
#include "Han.h"
#include "Render.h"
#include "Moveable.h"

class Player : public Moveable
{
private:
	// �÷��̾� ���ּ�
	std::string originalSprite[3];

	Sprite sprite;

	// ������ ���Ǵ� ��ġ ����
	short x;
	short y;

	// ��ġ �Ѱ��ִ� �뵵�� ����
	Vector2 playerPos;

public:

	void move() override;

	char getInput();



	CONSTRUCTOR Player();
	DESTRUCTOR ~Player();

};

