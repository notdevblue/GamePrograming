#pragma once

// ��Ŷ�� ȿ������ �޸� ���� �����ϸ鼭 ������ ����Ǵ� �����Ͱ� �ʹ����� ���ƿ�
// �� 20�ٵ� �ȵǴ� �ڵ尡 �������� ��ħ�� ���״� 20�谡 �˴ϴ�.
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