#include <Windows.h>
#include <iostream>
#include <conio.h>

const DWORD g_tone[8] = { 523,587,659,698,784,880,988,1046 };
const std::string g_name[8] = { "도","레","미","파","솔","라","시","높은 도" };

void game();
void firstShot();
_Check_return_ bool guessUser();
_Check_return_ bool giveShot(int num);
_Check_return_ int userInput();

int main()
{
	srand(unsigned(time(NULL)));

	game();

	return(0);
}

void game()
{
	while (true)
	{
		firstShot();
		Sleep(1000);
		if (guessUser())
		{
			break;
		}
		else
		{
			system("cls");
		}
	}
}

void firstShot()
{
	for (int i = 0; i < 8; ++i)
	{
		std::cout << g_name[i] << "(" << i << ")" << "\t";
		Beep(g_tone[i], 1000);
	}
	std::cout << std::endl;
}

_Check_return_ bool guessUser()
{
	int randNum = rand() % 8;

	Beep(g_tone[randNum], 500);
	Beep(g_tone[randNum], 500);

	if (giveShot(randNum))
	{
		std::cout << "정답!" << std::endl;
		Sleep(3000);
		return true;
	}
	else
	{
		std::cout << "오답" << std::endl;
		std::cout << "정답: " << g_name[randNum] << std::endl;
		Sleep(3000);
		return false;
	}
}

_Check_return_ bool giveShot(int num)
{
	if (num == userInput())
	{
		return true;
	}
	else
	{
		return false;
	}
}

_Check_return_ int userInput()
{
	return _getch() - '0';
}