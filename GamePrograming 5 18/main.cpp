#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>

void	gotoxy(int x, int y)
{
	COORD pos{ x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void	setConsoleView();
void	drawReadyGame();
void	drawStartGame();
void	startGame();
bool	readyGame();
int		getKeyDown()
{
	return _kbhit() != 0 ? _getch() : 0;
}


std::vector<std::string> g_wordHistory;
std::vector<std::string> g_wordQuestion;

int main()
{
	setConsoleView();

	while (true)
	{
		if (readyGame())
		{
			startGame();
		}

	}

	return(0);
}

bool readyGame()
{
	drawReadyGame();

	while (true)
	{
		int key = getKeyDown();
		if (tolower(key) == 's')
		{
			return true;
		}
	}
}
void setWords()
{
	std::string str[4]{ "apple", "jeamun", "wasans", "wooyeop" };

	std::ifstream readFromFile("words.txt");

	if (!readFromFile.is_open())
	{
		std::ofstream writeToFile("words.txt");

		for (int i = 0; i < 4; ++i)
		{
			std::string temp = str[i];
			if (i < 3)
			{
				temp += "\n";
			}
			writeToFile.write(temp.c_str(), temp.size());
			g_wordQuestion.push_back(str[i]);
		}

		writeToFile.close();
	}
	else
	{
		while (!readFromFile.eof())
		{
			std::string temp;
			std::getline(readFromFile, temp);
			g_wordQuestion.push_back(temp);
		}

		readFromFile.close();
	}
}

void startGame()
{
	setWords();

	drawStartGame();
}

void drawStartGame()
{
	
}

void setConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title WORD GAME");
}

void drawReadyGame()
{
	system("cls");
	gotoxy(5, 2);
	std::cout << "==============================";
	gotoxy(5, 3);
	std::cout << "========= WORD  GAME =========";
	gotoxy(5, 4);
	std::cout << "==============================";
	gotoxy(6, 6);
	std::cout << "시작하려면 s를 누르세요.";
	gotoxy(20, 18);
}