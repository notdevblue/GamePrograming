#include "Note.h"
#include "Console.h"
#include <iostream>
#include <conio.h>

#pragma region Member

void Note::downNote()
{
	++y;
}

void Note::InputNote(char num)
{/*
	if (_kbhit())
	{*/
		if(num == _getch())
		{
			checkEnd(true);
		}
	//}
}

void Note::checkInput()
{
	bTiming = false;
	if (y == 11)
	{
		bTiming = true;
		switch (x)
		{
		case 1:
			InputNote('1');
			break;

		case 4:
			InputNote('2');
			break;

		case 6:
			InputNote('3');
			break;

		case 8:
			InputNote('4');
			break;

		case 10:
			InputNote('5');
			break;

		case 12:
			InputNote('6');
			break;

		case 14:
			InputNote('7');
			break;
		}
	}
	bTiming = false;
}

void Note::checkEnd(bool input)
{
	if (y == 13 || input)
	{
		playSound();
		initNote();
	}
}

void Note::playSound()
{
	int tone[7] = { 523, 587, 659, 698, 784, 880, 988 };
	beep(tone[index - 1], 500);
}

void Note::initNote()
{

	index = rand() % 7 + 1;
	x = index * 2;
	y = 0;
}

void Note::drawNote()
{
	gotoxy(x, y);
	setTextColor(14);
	std::cout << "Q";
	setTextColor(15);
}

#pragma endregion