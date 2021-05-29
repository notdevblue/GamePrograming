#pragma once
#include "Base.h"

// gotoXY가 short 를 받기 때문
class Vector2
{
public:
	short* x;
	short* y;

	Vector2(short* x, short* y) : x(x), y(y) {  }


#pragma region Operator

	// 위치 수정이 불가능해서 주소값으로 멤버변수를 바꿔서 boolean 연산 말고는 전부 터졌

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