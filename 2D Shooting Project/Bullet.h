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

	std::string originalSprite[1];

	Sprite sprite;

public:

	CONSTRUCTOR Bullet();
	DESTRUCTOR ~Bullet();

	// 총알 움직임
	void move(int x, bool isRemote);

	// Vector getter
	Vector2 getVector();

	// 비활성화
	void disable(bool collision = true);


	// 사용 체크
	bool isEnabled;


	// 적과의 충돌
	bool collisionCheck(bool isRemote);
	void onCollision();
};

