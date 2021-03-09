#include <iostream>
#include <ctime>
#include <conio.h>

#pragma region Ȯ�� ���� ����ü�� �ʱ�ȭ �Լ� + ȹ���� ī�� �� ����ü�� �ʱ�ȭ �Լ�
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

#pragma region �Լ� ����
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

#pragma region �Լ� ����
void Mainscreen()
{
	system("mode con cols=30 lines=10");

	InitRate(&pullRate);
	InitCount(&pulledCards);

	int input = 0;

	while (input != 51)
	{
		input = 0;

		std::cout << "## ī�� �̱� ���α׷� ##" << std::endl;
		std::cout << "   �쿱����" << std::endl << std::endl;

		std::cout << "(1) Ȯ�� �˾ƺ���" << std::endl;
		std::cout << "(2) ��í ������" << std::endl;
		std::cout << "(3) ����" << std::endl;

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

	std::cout << "1��: " << 100 - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2��: " << 100 - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3��: " << 100 - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4��: " << 100 - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5��: " << 100 - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;
	
	std::cout << "���ư����� �ƹ� Ű�� ��������..." << std::endl;
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
		std::cout << "(1) ����"				<< std::endl;
		std::cout << "(2) 10���� �̱�"		<< std::endl;
		std::cout << "(3) 1000�� �̱�"		<< std::endl;
		std::cout << "(4) ���� �̱�"			<< std::endl;
		std::cout << "(5) ���ư���"			<< std::endl;

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

			std::cout << "�󸶳� ���������? (0�� �Է��ҽ� �����մϴ�.): ";
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

	std::cout << "ȹ���� ī�� ��:" << std::endl;
	std::cout << "5��: " << pulledCards.fiveStar		<< std::endl;
	std::cout << "4��: " << pulledCards.fourStar		<< std::endl;
	std::cout << "3��: " << pulledCards.threeStar	<< std::endl;
	std::cout << "2��: " << pulledCards.twoStar		<< std::endl;
	std::cout << "1��: " << pulledCards.oneStar		<< std::endl;
	std::cout << std::endl;

	std::cout << "���ư����� �ƹ� Ű�� ��������..." << std::endl;
	buffer = _getch();
}
#pragma endregion
