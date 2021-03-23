#include <Windows.h>
#include <iostream>

#define NUMBERS 5

void init(int*);
void showNumber(int*);
void userInput(int*);

int main()
{
	int arr[NUMBERS] = { 0, };
	
	init(arr);
	showNumber(arr);
	userInput(arr);

	return(0);
}

void init(int* arr)
{
	srand(unsigned(time(NULL)));

	for (int i = 0; i < NUMBERS; ++i)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void showNumber(int* arr)
{
	for (int i = 0; i < NUMBERS; ++i)
	{
		std::cout << arr[i] << std::endl;
		Sleep(1000);
		system("cls");
	}
}

void userInput(int* arr)
{
	int input;

	for (int i = 0; i < NUMBERS; ++i)
	{
		std::cin >> input;
		if (arr[i] != input)
		{
			std::cout << "틀렸습니다." << std::endl;
			return;
		}
	}
	std::cout << "모두 맞췄습니다." << std::endl;
}