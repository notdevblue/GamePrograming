#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#pragma region Ȯ�� ���� ����ü�� �ʱ�ȭ �Լ� + ȹ���� ī�� �� ����ü�� �ʱ�ȭ �Լ�
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

#pragma region �Լ� ����
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

#pragma region �Լ� ����
void Mainscreen()
{
	system("mode con cols=30 lines=10");

	InitRate(&pullRate);
	InitCount(&pulledCards);

	int input = 0;

	while (input != 53)
	{
		input = 0;

		std::cout << "## ī�� �̱� ���α׷� ##" << std::endl;
		std::cout << "   �쿱����" << std::endl << std::endl;

		std::cout << "(1) Ȯ�� �˾ƺ���" << std::endl;
		std::cout << "(2) ��í ������" << std::endl;
		std::cout << "(3) Ȯ�� �缳��" << std::endl;
		if(isDelayDisabled) { std::cout << "(4) �̱��� ����: ����" << std::endl; }
		else { std::cout << "(4) �̱��� ����: ����" << std::endl; }
		std::cout << "(5) ����" << std::endl;

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

#pragma region ShowRate �����ε�
void ShowRate()
{
	system("cls");

	char buffer;

	std::cout << "1��: " << 100.0f - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2��: " << 100.0f - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3��: " << 100.0f - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4��: " << 100.0f - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5��: " << 100.0f - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;

	std::cout << "���ư����� �ƹ� Ű�� ��������..." << std::endl;
	buffer = _getch();
}

bool ShowRate(PULLRATE pullRate)
{
	system("cls");

	std::cout << "1��: " << 100.0f - pullRate.oneStar		<< "%" << std::endl;
	std::cout << "2��: " << 100.0f - pullRate.twoStar		<< "%" << std::endl;
	std::cout << "3��: " << 100.0f - pullRate.threeStar		<< "%" << std::endl;
	std::cout << "4��: " << 100.0f - pullRate.fourStar		<< "%" << std::endl;
	std::cout << "5��: " << 100.0f - pullRate.fiveStar		<< "%" << std::endl;
	std::cout << std::endl;

	while (true)
	{
		char input;

		std::cout << "�� Ȯ���� ����ұ��? (Y/N)" << std::endl;
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
				std::cout << "���� %: " << whole << std::endl;
				std::cout << i + 1 << "�� Ȯ��: ";
				std::cin >> tempInput;
				if (tempInput >= whole)
				{
					std::cout << "�߸��� �Է��Դϴ�.\r\n";
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