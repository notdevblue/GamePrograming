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
	// �÷��̾� ���ּ�
	std::string originalSprite[3];

	Sprite sprite;

	// ������ ���Ǵ� ��ġ ����
	MoveablePacket pos;

	// ��ġ �Ѱ��ִ� �뵵�� ����
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

