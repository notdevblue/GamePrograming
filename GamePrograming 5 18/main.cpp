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
	srand(unsigned(time(NULL)));

	setWords();

	while (true)
	{
		int num = rand() % (int)g_wordQuestion.size();
		//std::string originalQuestion = g_wordQuestion[num];
		std::string originalQuestion = g_wordQuestion.at(num);

		int questionLength = (int)originalQuestion.length();
		std::string question;
		for (int i = 0; i < questionLength; ++i)
		{
			question += "_";
		}

		while (true)
		{
			drawStartGame();

			gotoxy(5, 5);
			//for (int i = 0; i < questionLength; ++i)
			//{
			//	std::cout << question[i];
			//}
			for (auto item : question)
			{
				std::cout << item << " ";
			}
			std::cout << std::endl;

			gotoxy(9, 12);
			bool inputOK = true;
			std::string input;
			std::cin >> input;
			for (auto item : g_wordHistory)
			{
				if (item == input)
				{
					inputOK = false;
				}
			}
			if (!inputOK)
			{
				continue;
			}

			g_wordHistory.push_back(input);

			if (input.length() == 1)
			{
				for (int i = 0; i < questionLength; ++i)
				{
					if (originalQuestion[i] == input[0])
					{
						question[i] = input[0];
					}
				}
			}
			else if (input.length() > 1)
			{
				if (originalQuestion == input)
				{
					g_wordHistory.clear();
					break;
				}
			}
			else {}
		}
	}
}

void drawStartGame()
{
	system("cls");
	gotoxy(5, 8);
	std::cout << "past = ";
	for (auto item : g_wordHistory)
	{
		std::cout << item << " ";
	}
	//for (int i = 0; i < (int)g_wordHistory.size(); ++i)
	//{
	//	std::cout << g_wordHistory[i] << " ";
	//}

	gotoxy(5, 12);
	std::cout << "input = ";
	
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