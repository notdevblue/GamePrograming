#pragma once
#include "Han.h"
#include "Render.h"
#include "Moveable.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "MoveableObjectPacket.h"

class Player : public Moveable
{
private:
	// 플레이어 우주선
	std::string originalSprite[3];

	Sprite sprite;

	// 실제로 사용되는 위치 변수
	MoveablePacket pos;

	// 위치 넘겨주는 용도로 사용됨
	Vector2 playerPos;
	
public:
	
	void move(bool isRemote = false) override;
	void shoot(bool isRemote = false);
	
	char getInput();

	Vector2* getVector();
	Sprite*  getSprite();
	MoveablePacket* getPacketData();

	CONSTRUCTOR Player();
	DESTRUCTOR ~Player();

	bool enabled;
};

