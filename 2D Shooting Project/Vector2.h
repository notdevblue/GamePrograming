#pragma once
#include "Base.h"

// gotoXY�� short �� �ޱ� ����
class Vector2
{
public:
	short* x;
	short* y;

	Vector2(short* x = nullptr, short* y = nullptr) : x(x), y(y) {  }

	void init(short* x, short* y) { this->x = x; this->y = y; }


#pragma region Operator

	// ��ġ ������ �Ұ����ؼ� �ּҰ����� ��������� �ٲ㼭 boolean ���� ����� ���� ����

	//// Vector2 + Vector2
	//Vector2 operator+(const Vector2& left)
	//{
	//	return Vector2(x += left.x, y += left.y);
	//}
	//// Vector2 - Vector2
	//Vector2 operator-(const Vector2& left)
	//{
	//	return Vector2(x -= left.x, y -= left.y);
	//}

	//// ++Vector2
	//Vector2 operator++()
	//{
	//	return Vector2(++x, ++y);
	//}

	//// Vector2 * short
	//Vector2 operator*(const short left)
	//{
	//	return Vector2(x *= left, y *= left);
	//}
	//// Vector2 * Vector2
	//Vector2 operator*(const Vector2 left)
	//{
	//	return Vector2(x *= left.x, y *= left.y);
	//}

	//// Vector2 / short
	//Vector2 operator/(const short left)
	//{
	//	return Vector2(x /= left, y /= left);
	//}
	//// Vector2 / Vector2
	//Vector2 operator/(const Vector2 left)
	//{
	//	return Vector2(x /= left.x, y /= left.y);
	//}

	//// Vector2 = short
	//Vector2 operator=(const short left)
	//{
	//	return Vector2(x = left, y = left);
	//}

#pragma region Boolean

	// Vector2 == Vector2
	bool operator==(const Vector2& left) const
	{
		return *this->x == *left.x && *this->y == *left.y;
	}
	// Vector2 > Vector2
	bool operator>(const Vector2& left) const
	{
		return *this->x > *left.x && *this->y > *left.y;
	}
	// Vector2 < Vector2
	bool operator<(const Vector2& left) const
	{
		return *this->x < *left.x && *this->y < *left.y;
	}
	// Vector2 >= Vector2
	bool operator>=(const Vector2& left) const
	{
		return *this->x >= *left.x && *this->y >= *left.y;
	}
	// Vector2 <= Vector2
	bool operator<=(const Vector2& left) const
	{
		return *this->x <= *left.x&& *this->y <= *left.y;
	}

#pragma endregion



#pragma endregion
};