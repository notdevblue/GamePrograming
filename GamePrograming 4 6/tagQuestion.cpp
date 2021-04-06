#include <iostream>
#include <conio.h>
#include <string.h>

struct tag_question
{
	std::string question;
	std::string answer;
	int limitcount;
};


tag_question question[] = { "********", "alphabet", 8 };

int main()
{
	std::cout << "---------------------------" << std::endl;
	std::cout << "|  alphabet 맞추기 게임   |" << std::endl;
	std::cout << "---------------------------" << std::endl;

	char ch;

	std::string tempQuestion = question[0].question;
	std::cout << tempQuestion << std::endl;

	while(tempQuestion != question[0].answer)
	{
		ch = _getch();
		std::cout << " " << ch << std::endl;

		for (int j = 0; j < question[0].limitcount; j++)
		{
			if (ch == question[0].answer[j])
			{
				tempQuestion[j] = ch;
			}

		}

		std::cout << tempQuestion;
	}

	return(0);
}