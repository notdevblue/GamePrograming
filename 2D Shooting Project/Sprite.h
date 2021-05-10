#pragma once
#include "Base.h"

// 꼭 필요한지는 모르겠지만 일단 만들어 봤습니다.
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
	/// # 배열 사이즈 #
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

	// 배열 삭제
	// 컴퓨터의 메모리는 소중할 겁니다. 아마도요.
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