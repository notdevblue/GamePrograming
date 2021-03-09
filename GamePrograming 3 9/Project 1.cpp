#include <iostream>
#include <ctime>
#include <conio.h>

#pragma region 확률 관련 구조체와 초기화 함수 + 획득한 카드 수 구조체와 초기화 함수
typedef struct pullrate
{
	int oneStar;
	int twoStar;
	int threeStar;
	int fourStar;
	int fiveStar;
} PULLRATE;
PULLRATE pullRate;
typedef struct pulledcards
{
	int oneStar;
	int twoStar;
	int threeStar;
	int fourStar;
	int fiveStar;
} PULLEDCARDS;
PULLEDCARDS pulledCards;

void InitRate(PULLRATE* pullrate_struct, int one = 50, int two = 70, int three = 90, int four = 93, int five = 97)
{
	pullrate_struct->oneStar	= one;
	pullrate_struct->twoStar	= two;
	pullrate_struct->threeStar	= three;
	pullrate_struct->fourStar	= four;
	pullrate_struct->fiveStar	= five;
}
void InitCount(PULLEDCARDS* pulledcards_struct)
{
	pulledcards_struct->oneStar		= 0;
	pulledcards_struct->twoStar		= 0;
	pulledcards_struct->threeStar	= 0;
	pulledcards_struct->fourStar	= 0;
	pulledcards_struct->fiveStar	= 0;
}
#pragma endregion

#pragma region 함수 선언
void Mainscreen();
void ShowRate();
void RunGatcha();
void Gatcha(int count);
#pragma endregion



int main()
{
	Mainscreen();
	system("cls");
	return(0);
}

#pragma region 함수 정의
void Mainscreen()
{
	system("mode con cols=30 lines=10");

	InitRate(&pullRate);
	InitCount(&pulledCards);

	int input = 0;

	while (input != 51)
	{
		input = 0;

		std::cout << "## 카드 뽑기 프로그램 ##" << std::endl;
		std::cout << "   우엽개발" << std::endl << std::endl;

		std::cout << "(1) 확률 알아보기" << std::endl;
		std::cout << "(2) 가챠 돌리기" << std::endl;
		std::cout << "(3) 종료" << std::endl;

		input = _getch();
		

		switch (input)
		{
		case 49:
			ShowRate();
			break;

		case 50:
			RunGatcha();
			break;

		case 51:
			return;

		default:
			break;
		}
		system("cls");
	}
}

void ShowRate()
{
	system("cls");

	char buffer;

	std::cout << "1성: " << 100 - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2성: " << 100 - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3성: " << 100 - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4성: " << 100 - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5성: " << 100 - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;
	
	std::cout << "돌아가려면 아무 키나 누르세요..." << std::endl;
	buffer = _getch();
}

void RunGatcha()
{
	int input = 0;
	

	while (input != 53)
	{
		InitCount(&pulledCards);
		input = 0;

		system("cls");
		std::cout << "(1) 단차"				<< std::endl;
		std::cout << "(2) 10연속 뽑기"		<< std::endl;
		std::cout << "(3) 1000번 뽑기"		<< std::endl;
		std::cout << "(4) 자유 뽑기"			<< std::endl;
		std::cout << "(5) 돌아가기"			<< std::endl;

		input = _getch();

		switch (input)
		{
		case 49:
			Gatcha(1);
			break;

		case 50:
			Gatcha(10);
			break;

		case 51:
			Gatcha(1000);
			break;

		case 52:
			int runCount;

			system("cls");

			std::cout << "얼마나 돌려볼까요? (0을 입력할시 종료합니다.): ";
			std::cin >> runCount;
			if (!runCount)
				break;

			Gatcha(runCount);
			break;

		default:
			break;
		}
	}
}

void Gatcha(int count)
{
	system("cls");

	int  randNum;
	char buffer;

	for (int i = 0; i < count; ++i)
	{
		randNum = rand() % 100 + 1;
		if (randNum >= pullRate.fiveStar)
		{
			++pulledCards.fiveStar;
		}
		else if (randNum >= pullRate.fourStar)
		{
			++pulledCards.fourStar;
		}
		else if (randNum >= pullRate.threeStar)
		{
			++pulledCards.threeStar;
		}
		else if (randNum >= pullRate.twoStar)
		{
			++pulledCards.twoStar;
		}
		else
		{
			++pulledCards.oneStar;
		}
	}

	std::cout << "획득한 카드 수:" << std::endl;
	std::cout << "5성: " << pulledCards.fiveStar		<< std::endl;
	std::cout << "4성: " << pulledCards.fourStar		<< std::endl;
	std::cout << "3성: " << pulledCards.threeStar	<< std::endl;
	std::cout << "2성: " << pulledCards.twoStar		<< std::endl;
	std::cout << "1성: " << pulledCards.oneStar		<< std::endl;
	std::cout << std::endl;

	std::cout << "돌아가려면 아무 키나 누르세요..." << std::endl;
	buffer = _getch();
}
#pragma endregion
