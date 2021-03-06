#pragma once
#include <string>

class Sprite
{
private:
	// 배열 순회 용 변수
	// 인덱스 + 1 입니다.
	int				length;
	int				color;
	std::string*	sprite;
	// TODO : 색
	

public:

	/// <summary>
	/// returns array[y] Length
	/// </summary>
	/// <returns>array length (int)</returns>
	inline int getLength()
	{
		return length;
	}

	/// <summary>
	/// prints sprite
	/// </summary>
	/// <param name="index">index (just put count)</param>
	void print(int index);

	/// <summary>
	/// # 배열 사이즈 #
	/// </summary>
	/// <param name="size">: Length of sprite array. 0 ~ size</param>
	void init(int size, std::string* arr, int color);

#pragma region Constructor, Destructor

	/// <summary>
	/// # 배열 사이즈 #
	/// </summary>
	/// <param name="size">: Length of sprite array. 0 ~ size</param>
	Sprite(int size = NULL, std::string* arr = nullptr, int color = NULL);

	// 배열 삭제
	// 컴퓨터의 메모리는 소중할 겁니다. 아마도요.
	~Sprite();

#pragma endregion
};