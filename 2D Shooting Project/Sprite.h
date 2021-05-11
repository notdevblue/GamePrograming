#pragma once
#include <string>

// 꼭 필요한지는 모르겠지만 일단 만들어 봤습니다.
class Sprite
{
private:
	int				length;
	std::string*	sprite;

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



#pragma region Constructor, Destructor

	/// <summary>
	/// # 배열 사이즈 #
	/// </summary>
	/// <param name="x">: Length of sprite array</param>
	/// <param name="y">: Length of sprite array</param>
	Sprite(int size, std::string* arr);

	// 배열 삭제
	// 컴퓨터의 메모리는 소중할 겁니다. 아마도요.
	~Sprite();

#pragma endregion
};