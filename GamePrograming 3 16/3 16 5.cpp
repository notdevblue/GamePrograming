#include <iostream>
#include <ctime>

int answer[3] = { 0, };
int input[3] = { 0, };

enum STATUS
{
	GameEnd,
	Strike,
	Ball,
	Out
};

void InitAnswer();
void PlayerInput();
int StrkieCheck();
int BallCheck();
int OutCheck();

int main()
{
	srand(unsigned(time(NULL)));
	InitAnswer();
	PlayerInput();
	std::cout << "끝" << std::endl;
	return(0);
}

void InitAnswer()
{
	answer[0] = rand() % 9 + 1;

	do
	{
		answer[1] = rand() % 9 + 1;
	} while (answer[0] == answer[1]);

	do
	{
		answer[2] = rand() % 9 + 1;
	} while ((answer[0] == answer[2]) || (answer[1] == answer[2]));

	//std::cout << answer[0] << answer[1] << answer[2] << std::endl;
}

void PlayerInput()
{
	while (true)
	{
		std::cin >> input[0] >> input[1] >> input[2];
		
		int strike = StrkieCheck();
		int ball = BallCheck();
		int out = OutCheck();

		std::cout << strike << "스트라이크" << std::endl;
		std::cout << ball	<< "볼" << std::endl;
		std::cout << out	<< "아웃" << std::endl;

		if (strike == 3)
		{
			return;
		}
	}
}

int StrkieCheck()
{
	int i;
	int strikeCount = 0;

	for (i = 0; i < 3; ++i)
	{
		if (input[i] == answer[i])
		{
			++strikeCount;
		}
	}

	return strikeCount;
}

int BallCheck()
{
	int i, j;
	int ballCount = 0;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if ((input[i] == answer[j]) && (i != j))
			{
				++ballCount;
			}
		}
	}

	return ballCount;
}

int OutCheck()
{
	int i, j;
	int outCheck = 0;
	int outCount = 0;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (input[i] != answer[j])
			{
				++outCheck;
			}
		}

		if (outCheck == 3)
		{
			++outCount;
		}
		outCheck = 0;
	}

	return outCount;
}