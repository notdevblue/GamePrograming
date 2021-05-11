#include "Note.h"
#include "Console.h"
#include <iostream>

#pragma region Member

void Note::downNote()
{
	++y;
}

void Note::checkEnd()
{
	if (y == 12)
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