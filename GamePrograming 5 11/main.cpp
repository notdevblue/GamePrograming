#include <iostream>
#include <time.h>

#include "Note.h"
#include "Console.h"

void render();


int main()
{
	srand(unsigned(time(NULL)));

	Note* note = new Note();
	note->initNote();

	while (true)
	{
		render();
		
		gotoxy(16, 12);
		note->drawNote();

		

		gotoxy(16, 12);
		note->downNote();
		

		note->checkInput();
		note->checkEnd();
		
		

		sleep(200);
		system("cls");
	}

	delete note;
	return(0);
}



void render()
{
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "|               |" << std::endl;
	std::cout << "  1 2 3 4 5 6 7  ";

	gotoxy(1, 10);
	setTextColor(1);
	std::cout << "---------------";
	setTextColor(15);
}