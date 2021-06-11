#pragma once
#include "Han.h"
#include "MoveableObjectPacket.h"

#define LPBULLET Bullet*

class Bullet // TODO : 총알 발사 전달을 어케 하지
{
private:
	// Bullets 담아두는 Vector<>
	// Bullet 은 그저 위나 아레로 잘 감
	Vector2 pos;


public:

	CONSTRUCTOR Bullet();
	DESTRUCTOR ~Bullet();

	// 총알 움직임
	void move(int x, bool isRemote);

	// Vector getter
	Vector2 getVector();

	void disable();


	// 사용 체크
	bool isEnabled;


	// TODO : 충돌 체크

};

