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
	printf("# ���� ���� �� ���� #\r\n");
	printf("#                   #\r\n");
	printf("#   ��۰���        #\r\n");
	printf("#####################\r\n\r\n");
	printf("����: 1\r\n����: 2\r\n��:   3\r\n����: 0\r\n\r\n");

	while (person)
	{
		std::cout << "����� �� ����?: ";
		std::cin >> person;

		computer = rand() % 3 + 1;
		std::cout << "��ǻ���� ����?: " << computer << std::endl << std::endl;

		std::cout << "�����   " << DisplayRSP(person) << " ��(��) �½��ϴ�." << std::endl;
		std::cout << "��ǻ�ʹ� " << DisplayRSP(computer) << " ��(��) �½��ϴ�." << std::endl;

		switch (person)
		{
#pragma region ����
		case 0:
			total = winGame + lostGame + same;
			std::cout << total << "�� " << winGame << "�� " << lostGame << "�� " << same << "��";
			exit(0);
			break;
#pragma endregion
#pragma region ����
		case 1:
			switch (computer)
			{
			case 1:
				std::cout << "�����ϴ�." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "�����ϴ�." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "�̰���ϴ�." << std::endl;
				++winGame;
				break;
			}
			break;
#pragma endregion
#pragma region ����
		case 2:
			switch (computer)
			{
			case 1:
				std::cout << "�̰���ϴ�." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "�����ϴ�." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "�����ϴ�." << std::endl;
				++winGame;
				break;
			}
			break;
#pragma endregion
#pragma region ��
		case 3:
			switch (computer)
			{
			case 1:
				std::cout << "�����ϴ�." << std::endl;
				++same;
				break;

			case 2:
				std::cout << "�̰���ϴ�." << std::endl;
				++lostGame;
				break;

			case 3:
				std::cout << "�����ϴ�." << std::endl;
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
		return "(����)";

	case 2:
		return "(����)";

	case 3:
		return "(��)  ";

	default:
		return "(����)";
	}
}

int CompareWinLose(int num)
{
	return(0);
}

#endif