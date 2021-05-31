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

	bool bAPressed;
	bool bDPressed;

public:
	void move() override;
	char getInput();

	Vector2* getVector();
	Sprite*  getSprite();


	CONSTRUCTOR Player();
	DESTRUCTOR ~Player();

};

