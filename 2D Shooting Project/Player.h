#pragma once
#include "Han.h"
#include "Render.h"
#include "Moveable.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// ��Ŷ�� ȿ������ �޸� ���� �����ϸ鼭 ������ ����Ǵ� �����Ͱ� �ʹ����� ���ƿ�
#pragma pack(push, 1)
class PlayerPacket
{
public:
	short x;
	short y;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& x;
		ar& y;
	}
};
#pragma pack(pop)

class Player : public Moveable
{
private:
	// �÷��̾� ���ּ�
	std::string originalSprite[3];

	Sprite sprite;

	// ������ ���Ǵ� ��ġ ����
	PlayerPacket pos;

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

