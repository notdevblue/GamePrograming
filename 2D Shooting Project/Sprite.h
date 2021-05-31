#pragma once
#include <string>

// �Ҹ��� �ι� �Ҹ��� ������ ����.
// shared_ptr �� ���� �ذ��� �ȴٰ�� ��
class Sprite
{
private:
	// �迭 ��ȸ �� ����
	// �ε��� + 1 �Դϴ�.
	int				length;

	std::string*	sprite;
	// TODO : ��
	

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
	/// # �迭 ������ #
	/// </summary>
	/// <param name="size">: Length of sprite array. 0 ~ size</param>
	void init(int size, std::string* arr);

#pragma region Constructor, Destructor

	/// <summary>
	/// # �迭 ������ #
	/// </summary>
	/// <param name="size">: Length of sprite array. 0 ~ size</param>
	Sprite(int size = NULL, std::string* arr = nullptr);

	// �迭 ����
	// ��ǻ���� �޸𸮴� ������ �̴ϴ�. �Ƹ�����.
	~Sprite();

#pragma endregion
};