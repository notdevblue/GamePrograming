#pragma once

// 페킷을 효율적인 메모리 정렬 생각하면서 보내면 낭비되는 데이터가 너무나도 많아요
// 이 20줄도 안되는 코드가 가져오는 빡침과 버그는 20배가 됩니다.
#pragma pack(push, 1)
class MoveablePacket
{
public:
	// sender id
	short id;

	// Vector2
	short x;
	short y;

	// Bullet Fired
	bool fire;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& id;
		ar& x;
		ar& y;
		ar& fire;
	}
};
#pragma pack(pop)