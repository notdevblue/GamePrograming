#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

bool bStart;
int currentScore;
int highScore[5];

#pragma region Base

void gotoxy(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setConsoleView()
{
	system("mode con:cols=29 lines=28");
	system("title Score Game");
}

#pragma endregion

void saveFile()
{
	std::ofstream writeToFile("score.txt");

	for (int i = 0 ; i < 5; ++i)
	{
		std::string temp = std::to_string(highScore[i]);
		
		if (i < 4) { temp += "\n"; }

		writeToFile.write(temp.c_str(), temp.size());
	}

	writeToFile.close();
}

void loadFile()
{
	std::ifstream readFromFile("score.txt");

	if (!readFromFile.is_open())
	{
		saveFile();
		readFromFile.open("score.txt");
	}

	int i = 0;
	while (!readFromFile.eof())
	{
		std::string temp;
		getline(readFromFile, temp);
		highScore[i] = std::stoi(temp);
		++i;
	}
	i = 0;

	readFromFile.close();
}

void initData()
{
	bStart = false;

	currentScore = 0;
	for (int i = 0; i < 5; ++i)
	{
		highScore[i] = 0;
	}
}


void drawHighScore()
{
	gotoxy(6, 10);
	
	std::cout << "HIGH SCORE";

	for (int i = 0; i < 5; ++i)
	{
		gotoxy(5, 12 + i * 2);
		std::cout << i + 1 << " : " << highScore[i];
	}

	gotoxy(3, 22);
	std::cout << "-----------------------";
}

void drawscore()
{
	gotoxy(5, 10);
	std::cout << "[a] ADD SCORE";

	gotoxy(3, 4);
	std::cout << "-----------------------";

	gotoxy(5, 14);
	std::cout << "SCORE : " << currentScore;

}

void saveScore(int score)
{
	for (int i = 0; i < 5; ++i)
	{
		if (score >= highScore[i])
		{
			for (int j = 3; j >= i; --j)
			{
				highScore[j + 1] = highScore[j];
			}

			highScore[i] = score;
			break;
		}
	}
}


void checkKeyDown(int key)
{
	switch (key)
	{
	case 's':
		if (bStart) return;
		bStart = true;
		currentScore = 0;
		break;
		
	case 'x':
		if (!bStart) return;
		saveScore(currentScore);
		saveFile();
		bStart = false;
		break;

	case 'a':
		if (!bStart) return;
		++currentScore;
		break;

	case 'q':
		exit(0);
		break;
	}
}

void drawMenu()
{
	gotoxy(3, 2);
	std::cout << "-----------------------";
	gotoxy(6, 3);
	std::cout << "SCORE GAME";
	gotoxy(3, 4);
	std::cout << "-----------------------";

	gotoxy(5, 6);
	std::cout << (bStart ? "[x] EXIT GAME" : "[s] START GAME");

	gotoxy(3, 8);
	std::cout << "-----------------------";


	bStart ? drawscore() : drawHighScore();
}

int main()
{

	setConsoleView();
	initData();
	loadFile();

	while (true)
	{
		

		drawMenu();
		char key = _getch_nolock();
		checkKeyDown(key);

		Sleep(100);
		system("cls");

		gotoxy(30, 30);
	}


	return(0);
}