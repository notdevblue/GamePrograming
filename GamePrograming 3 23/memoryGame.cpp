#include <Windows.h>
#include <iostream>
#include <conio.h>

#define NUMBERS 20


void init(int*);
bool checkNumArchive(int*, int);

void showNumbers(int*);
void showHiddenNumbers();
void userInput(int*);

void gotoXY(int x, int y);

int main()
{
	int numbers[NUMBERS] = { 0, };

	init(numbers);

#pragma region BEGIN
	showNumbers(numbers);
	Sleep(3000);
	system("cls");
	showHiddenNumbers();
#pragma endregion
	userInput(numbers);


	return(0);
}


void init(int* arr)
{
	srand(unsigned(time(NULL)));

	for (int i = 0; i < NUMBERS; ++i)
	{
		arr[i] = rand() % NUMBERS / 2;
		if (i > 1)
		{
			do
			{
				arr[i] = rand() % (NUMBERS / 2);
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
		gotoXY(i % 5, i / 5);
		std::cout << arr[i];
	}
}

void showHiddenNumbers()
{
	for (int i = 0; i < NUMBERS; ++i)
	{
		gotoXY(i % 5, i / 5);
		std::cout << '*';
	}
}

void userInput(int* arr)
{
	int key;
	int select[2] = { -1,-1 };
	int keypushed[2] = { 0, };
	int selectCount = 0;

	while (true)
	{
		key = _getch();
		switch (key)
		{
		case '1': // 12345
			gotoXY(0, 0);
			std::cout << arr[0];
			select[selectCount] = arr[0];
			keypushed[selectCount] = '1';
			++selectCount;
			break;

		case '2':
			gotoXY(1, 0);
			std::cout << arr[1];
			select[selectCount] = arr[1];
			keypushed[selectCount] = '2';
			++selectCount;
			break;

		case '3':
			gotoXY(2, 0);
			arr[2];
			select[selectCount] = arr[2];
			keypushed[selectCount] = '3';
			++selectCount;
			break;

		case '4':
			break;

		case '5':
			break;

		case 'q': // QWERT
			break;
			
		case 'w':
			break;

		case 'e':
			break;

		case 'r':
			break;

		case 't':
			break;

		case 'a': // ASDFG
			break;

		case 's':
			break;

		case 'd':
			break;

		case 'f':
			break;

		case 'g':
			break;

		case 'z': // ZXCVB
			break;

		case 'x':
			break;

		case 'c':
			break;

		case 'v':
			break;

		case 'b':
			break;
		}

		Sleep(1000);

		if (selectCount == 2)
		{
			if (select[0] != select[1])
			{

			}
			selectCount = 0;
		}
	}
}


void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(hOut, cur);
}
