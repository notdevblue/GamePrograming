#pragma once
#include "Base.h"

// gotoXY가 short 를 받기 때문
class Vector2
{
public:
	short* x;
	short* y;

	Vector2(short* x = nullptr, short* y = nullptr) : x(x), y(y) {  }

	void init(short* x, short* y) { this->x = x; this->y = y; }

	inline Vector2 get()
	{
		Vector2 temp(this->x, this->y);
		return temp;
	}

#pragma region Operator

	// Vector2 + Vector2
	Vector2 operator+(const Vector2& left)
	{
		*this->x += *left.x;
		*this->y += *left.y;
	}
	// Vector2 - Vector2
	Vector2 operator-(const Vector2& left)
	{
		*this->x += *left.x;
		*this->y += *left.y;
	}

	// ++Vector2
	Vector2 operator++()
	{
		++*this->x;
		++*this->y;
	}

	// Vector2 * short
	Vector2 operator*(const short left)
	{
		*this->x *= left;
		*this->y *= left;
	}
	// Vector2 * Vector2
	Vector2 operator*(const Vector2 left)
	{
		*this->x *= *left.x;
		*this->y *= *left.y;
	}

	// Vector2 / short
	Vector2 operator/(const short left)
	{
		*this->x /= left;
		*this->y /= left;
	}
	// Vector2 / Vector2
	Vector2 operator/(const Vector2 left)
	{
		*this->x /= *left.x;
		*this->y /= *left.y;
	}

	// Vector2 = short
	Vector2 operator=(const short left)
	{
		*this->x = left;
		*this->y = left;
	}

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