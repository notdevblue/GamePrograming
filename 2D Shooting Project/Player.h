#pragma once
#include "Han.h"
#include "Render.h"
#include "Moveable.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// 페킷을 효율적인 메모리 정열 생각하면서 보내면 낭비되는 데이터가 너무나도 많아요
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
	// 플레이어 우주선
	std::string originalSprite[3];

	Sprite sprite;

	// 실제로 사용되는 위치 변수
	PlayerPacket pos;

	// 위치 넘겨주는 용도로 사용됨
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

