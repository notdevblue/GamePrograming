#pragma once
#include "Han.h"
#include "Render.h"
#include "Moveable.h"

class Player : public Moveable
{
private:

	// 실제로 사용되는 위치 변수
	short x;
	short y;

	// 위치 넘겨주는 용도로 사용됨
	Vector2 playerPos;

public:

	void move() override;

	char getInput();



	CONSTRUCTOR Player();
	DESTRUCTOR ~Player();

};

