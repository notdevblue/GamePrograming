#pragma once
#include "Base.h"

// �� �ʿ������� �𸣰����� �ϴ� ����� �ý��ϴ�.
class Sprite
{
private:
	int		xSize;
	int		ySize;
	char**	sprite;

public:

	/// <summary>
	/// returns array[y] Length
	/// </summary>
	/// <returns>array length (int)</returns>
	inline int getYsize()
	{
		return ySize;
	}

	/// <summary>
	/// prints sprite
	/// </summary>
	/// <param name="index">index (just put count)</param>
	inline void print(int index)
	{
		printf("%s", sprite[index]);
	}



#pragma region Constructor, Destructor

	/// <summary>
	/// # �迭 ������ #
	/// </summary>
	/// <param name="x">: Length of sprite array</param>
	/// <param name="y">: Length of sprite array</param>
	Sprite(int x,int y, char** original)
	{
		xSize = x + 1;
		ySize = y + 1;

		sprite = new char* [y];
		for (int count = 0; count < y; ++count)
		{
			sprite[count] = new char[x];
		}

		for (int yCount = 0; yCount = y; ++yCount)
		{
			for (int xCount = 0; xCount = x; ++xCount)
			{
				sprite[yCount][xCount] = original[yCount][xCount];
			}
		}
	}

	// �迭 ����
	// ��ǻ���� �޸𸮴� ������ �̴ϴ�. �Ƹ�����.
	~Sprite()
	{
		for (int count = 0; count < xSize; ++count)
		{
			delete[] sprite[count];
		}

		delete[] sprite;
	}

#pragma endregion
};