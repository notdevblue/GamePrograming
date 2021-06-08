#pragma once
#include "Han.h"
#include "MoveableObjectPacket.h"

class Bullet // TODO : 총알 발사 전달을 어케 하지
{
private:
	bool isRemote;
	short x;
	// Bullets 담아두는 Vector<>
	// Bullet 은 그저 위나 아레로 잘 감
	Vector2 pos;

public:

	CONSTRUCTOR Bullet(short x, bool isRemote = false);
	DESTRUCTOR ~Bullet();

	// 총알 움직임
	void move();

	// Vector getter
	Vector2 getVector();



	// TODO : 충돌 체크

};

