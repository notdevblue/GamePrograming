#pragma once
#include <string>

// 꼭 필요한지는 모르겠지만 일단 만들어 봤습니다.

// 소멸자 두번 불리는 문제가 있음.
// shared_ptr 을 쓰면 해결이 된다고는 함
class Sprite
{
private:
	int				length;
	std::string*	sprite;
	//std::shared_ptr<std::string> sprite; // <= TODO : 어케 쓰느지 몰라서 일단 선언만 해둠
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