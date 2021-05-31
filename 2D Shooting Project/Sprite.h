#pragma once
#include <string>

// 소멸자 두번 불리는 문제가 있음.
// shared_ptr 을 쓰면 해결이 된다고는 함
class Sprite
{
private:
	// 배열 순회 용 변수
	// 인덱스 + 1 입니다.
	int				length;

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
	void init(int size, std::string* arr);

#pragma region Constructor, Destructor

	/// <summary>
	/// # 배열 사이즈 #
	/// </summary>
	/// <param name="size">: Length of sprite array. 0 ~ size</param>
	Sprite(int size = NULL, std::string* arr = nullptr);

	// 배열 삭제
	// 컴퓨터의 메모리는 소중할 겁니다. 아마도요.
	~Sprite();

#pragma endregion
};