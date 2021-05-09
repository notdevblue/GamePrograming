#pragma once

// �� �ʿ������� �𸣰����� �ϴ� ����� �ý��ϴ�.
class Sprite
{
private:
	int		xSize;
	int		ySize;
	char**	sprite;
	char aa[10];
public:
	// ���� 2���� char �迭

	/*
	�迭�� y ���� �����༭ Render ���� �� �����°͵� �����������Ű���
	*/

	void print()
	{
		for (int y = 0; y < ySize; ++y)
		{
			printf("%s", sprite[y]); // TODO : �� ������ ��. but HOW
		}
	}



#pragma region Constructor, Destructor

	/// <summary>
	/// # �迭 ������ #
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