#pragma once

// 꼭 필요한지는 모르겠지만 일단 만들어 봤습니다.
class Sprite
{
private:
	int		xSize;
	int		ySize;
	char**	sprite;
	char aa[10];
public:
	// 동적 2차원 char 배열

	/*
	배열과 y 수로 돌려줘서 Render 에서 줄 내리는것도 나쁘지않은거같음
	*/

	void print()
	{
		for (int y = 0; y < ySize; ++y)
		{
			printf("%s", sprite[y]); // TODO : 줄 내려야 함. but HOW
		}
	}



#pragma region Constructor, Destructor

	/// <summary>
	/// # 배열 사이즈 #
	/// </summary>
	/// <param name="x">: Length of sprite array</param>
	/// <param name="y">: Length of sprite array</param>
	Sprite(int x,int y, char** original)
	{
		xSize = x;
		ySize = y;

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