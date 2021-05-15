#pragma once
#include <string>

// �� �ʿ������� �𸣰����� �ϴ� ����� �ý��ϴ�.

// �Ҹ��� �ι� �Ҹ��� ������ ����.
// shared_ptr �� ���� �ذ��� �ȴٰ�� ��
class Sprite
{
private:
	int				length;
	std::string*	sprite;
	//std::shared_ptr<std::string> sprite; // <= TODO : ���� ������ ���� �ϴ� ���� �ص�
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
	/// # �迭 ������ #
	/// </summary>
	/// <param name="x">: Length of sprite array</param>
	/// <param name="y">: Length of sprite array</param>
	Sprite(int size, std::string* arr);

	// �迭 ����
	// ��ǻ���� �޸𸮴� ������ �̴ϴ�. �Ƹ�����.
	~Sprite();

#pragma endregion
};