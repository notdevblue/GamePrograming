//#define THIS

#ifdef THIS

#include <iostream>

const char* DisplayRSP(int);
int CompareWinLose(int);

int main()
{
	int computer	= 0;
	int person		= 100;
	int winGame		= 0;
	int lostGame	= 0;
	int same		= 0;
	int total		= 0;

	printf("#####################\r\n");
	printf("#                   #\r\n");
	printf("# 가위 바위 보 게임 #\r\n");
	printf("#                   #\r\n");
	printf("#   우앱개발        #\r\n");
	printf("#####################\r\n\r\n");
	printf("가위: 1\r\n바위: 2\r\n보:   3\r\n종료: 0\r\n\r\n");

	while (person)
	{
		std::cout << "당신의 낼 수는?: ";
		std::cin >> person;

		computer = rand() % 3 + 1;
		std::cout << "컴퓨터의 수는?: " << computer << std::endl << std::endl;

		std::cout << "당신은   " << DisplayRSP(person) << " 을(를) 냈습니다." << std::endl;
		std::cout << "컴퓨터는 " << DisplayRSP(computer) << " 을(를) 냈습니다." << std::endl;

		switch (person)
		{
#pragma region 종료
		case 0:
			total = winGame + lostGame + same;
			std::cout << total << "전 " << winGame << "승 " << lostGame << "패 " << same << "무";
			exit(0);
			break;
#pragma endregion
#pragma region 가위
		case 1:
			switch (computer)
			{
			case 1:
				std::cout << "비겼습니다." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "졌습니다." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "이겼습니다." << std::endl;
				++winGame;
				break;
			}
			break;
#pragma endregion
#pragma region 바위
		case 2:
			switch (computer)
			{
			case 1:
				std::cout << "이겼습니다." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "비겼습니다." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "졌습니다." << std::endl;
				++winGame;
				break;
			}
			break;
#pragma endregion
#pragma region 보
		case 3:
			switch (computer)
			{
			case 1:
				std::cout << "졌습니다." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "이겼습니다." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "비겼습니다." << std::endl;
				++winGame;
				break;
			}
			break;
#pragma endregion
		}


		std::cout << std::endl;
	}

}

const char* DisplayRSP(int num)
{
	switch (num)
	{
	case 1:
		return "(가위)";

	case 2:
		return "(바위)";

	case 3:
		return "(보)  ";

	default:
		return "(종료)";
	}
}

int CompareWinLose(int num)
{
	return(0);
}

#endif