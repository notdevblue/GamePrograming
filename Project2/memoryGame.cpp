#include <Windows.h>
#include <iostream>
#include <conio.h>

#define NUMBERS 20


void init(int*);
bool checkNumArchive(int*, int);

void showNumbers(int*);
void showHiddenNumbers();

int main()
{
	int numbers[NUMBERS] = { 0, };

	init(numbers);
	//showNumbers(numbers);
	showHiddenNumbers();

	return(0);
}


void init(int* arr)
{
	srand(unsigned(time(NULL)));

	for (int i = 0; i < NUMBERS; ++i)
	{
		arr[i] = rand() % NUMBERS + 1;
		if (i > 1)
		{
			do
			{
				arr[i] = rand() % (NUMBERS / 2) + 1;
			} while (!checkNumArchive(arr, i));
		}
	}
}

bool checkNumArchive(int* arr, int count)
{
	int sameCount = 0;

	for (int i = 0; i < count; ++i)
	{
		if (arr[count] == arr[i])
			++sameCount;
	}
	
	if (sameCount >= 2)
		return false;
	else
		return true;
}

void showNumbers(int* arr)
{
	for (int i = 0; i < NUMBERS; ++i)
	{
		std::cout << arr[i] << "\t";
		if (i % 5 == 4)
			std::cout << std::endl;
	}
}

void showHiddenNumbers()
{
	for (int i = 0; i < NUMBERS; ++i)
	{
		std::cout << "бс" << "\t";
		if (i % 5 == 4)
			std::cout << std::endl;
	}
}