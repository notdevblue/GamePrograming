#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#pragma region 확률 관련 구조체와 초기화 함수 + 획득한 카드 수 구조체와 초기화 함수
typedef struct pullrate
{
	float oneStar;
	float twoStar;
	float threeStar;
	float fourStar;
	float fiveStar;

	struct pullrate operator=(const struct pullrate& right)
	{
		oneStar = right.oneStar;
		twoStar = right.twoStar;
		threeStar = right.threeStar;
		fourStar = right.fourStar;
		fiveStar = right.fiveStar;

		return *this;
	}

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

void InitRate(PULLRATE* pullrate_struct, float one = 50, float two = 30, float three = 10, float four = 7, float five = 3)
{
	pullrate_struct->oneStar	= 100.0f - one;
	pullrate_struct->twoStar	= 100.0f - two;
	pullrate_struct->threeStar	= 100.0f - three;
	pullrate_struct->fourStar	= 100.0f - four;
	pullrate_struct->fiveStar	= 100.0f - five;
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
bool ShowRate(PULLRATE);
void RunGatcha();
void ResetPullrate();
void Gatcha(int count);
void Delay(int count);
#pragma endregion

bool isDelayDisabled = false;

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

	while (input != 53)
	{
		input = 0;

		std::cout << "## 카드 뽑기 프로그램 ##" << std::endl;
		std::cout << "   우엽개발" << std::endl << std::endl;

		std::cout << "(1) 확률 알아보기" << std::endl;
		std::cout << "(2) 가챠 돌리기" << std::endl;
		std::cout << "(3) 확률 재설정" << std::endl;
		if(isDelayDisabled) { std::cout << "(4) 쫄깃함 상태: 꺼짐" << std::endl; }
		else { std::cout << "(4) 쫄깃함 상태: 켜짐" << std::endl; }
		std::cout << "(5) 종료" << std::endl;

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
			ResetPullrate();
			break;

		case 52:
			isDelayDisabled = !isDelayDisabled;
			break;

		default:
			break;
		}
		system("cls");
	}
}

#pragma region ShowRate 오버로딩
void ShowRate()
{
	system("cls");

	char buffer;

	std::cout << "1성: " << 100.0f - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2성: " << 100.0f - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3성: " << 100.0f - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4성: " << 100.0f - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5성: " << 100.0f - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;

	std::cout << "돌아가려면 아무 키나 누르세요..." << std::endl;
	buffer = _getch();
}

bool ShowRate(PULLRATE pullRate)
{
	system("cls");

	std::cout << "1성: " << 100.0f - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2성: " << 100.0f - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3성: " << 100.0f - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4성: " << 100.0f - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5성: " << 100.0f - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;

	while (true)
	{
		char input;

		std::cout << "이 확률을 사용할까요? (Y/N)" << std::endl;
		std::cin >> input;

		if ((input == 'Y') || (input == 'y'))
			return true;
		else if ((input == 'N') || (input == 'n'))
			return false;
		else
			system("cls");
	}
}
#pragma endregion


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

void ResetPullrate()
{
	

	PULLRATE tempRate;
	float	 tempInput	= 0;
	float	 whole		= 100;

	while(true)
	{
		system("cls");
		whole = 100;
		for (int i = 0; i < 4; ++i)
		{
			while (true)
			{
				std::cout << "남은 %: " << whole << std::endl;
				std::cout << i + 1 << "성 확률: ";
				std::cin >> tempInput;
				if (tempInput >= whole)
				{
					std::cout << "잘못된 입력입니다.\r\n";
				}
				else
				{
					whole -= tempInput;
					switch (i)
					{
					case 0:
						tempRate.oneStar	= 100.0f - tempInput;
						break;
					case 1:
						tempRate.twoStar	= 100.0f - tempInput;
						break;
					case 2:
						tempRate.threeStar	= 100.0f - tempInput;
						break;
					case 3:
						tempRate.fourStar	= 100.0f - tempInput;
						break;
					}
					break;
				}
			}
		}
		tempRate.fiveStar = 100.0f - whole;

		if (ShowRate(tempRate))
		{
			pullRate = tempRate;
			return;
		}
	}
}

void Gatcha(int count)
{
	system("cls");

	float randNum;
	char  buffer;

	for (int i = 0; i < count; ++i)
	{
		randNum = (rand() % 10000 + 1) * 0.01f;
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

	if(!isDelayDisabled)
		Delay(count);

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

void Delay(int count)
{
	switch (count)
	{
	case 1:
		std::cout << "";
		Sleep(250);
		std::cout << ".";
		Sleep(250);
		std::cout << ".";
		Sleep(250);
		std::cout << ".";
		Sleep(250);
		system("cls");
		break;

	default:
		int repeatCount;

		if (count > 300)
		{
			repeatCount = 10;
		}
		else
		{
			repeatCount = count / 10;
		}
		for (int i = 0; i < repeatCount; ++i)
		{
			std::cout << "";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			system("cls");
		}
		break;
	}
}
#pragma endregion