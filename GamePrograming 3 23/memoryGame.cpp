#include <Windows.h>
#include <iostream>
#include <conio.h>

#define NUMBERS 20


void init(int*);
bool checkNumArchive(int*, int);

void showNumbers(int*);
void showHiddenNumbers();
void userInput(int*);
int  userInput2ArrIndex(int*);
int  showCard(int* arr, int* select, int* inputIndex, int* inputHistory, int index, int& count);
void gotoXY(int x, int y);
bool checkGameEnd(int* inputIndex);

int main()
{
	int numbers[NUMBERS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 };

	init(numbers);

	system("mode con cols=30 lines=10");

#pragma region BEGIN
	showNumbers(numbers);
	Sleep(3000);
	system("cls");
	showHiddenNumbers();
#pragma endregion
	userInput(numbers);

	Sleep(1000);
	system("cls");
	gotoXY(0, 0);
	std::cout << "Å¬¸®¾î!" << std::endl;
	


	return(0);
}


void init(int* arr)
{
	srand(unsigned(time(NULL)));

	//for (int i = 0; i < NUMBERS; ++i)
	//{
	//	arr[i] = rand() % NUMBERS / 2;
	//	if (i > 1)
	//	{
	//		do
	//		{
	//			arr[i] = rand() % (NUMBERS / 2);
	//		} while (!checkNumArchive(arr, i));
	//	}
	//}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 2; )
		{
			int randArr = rand() % NUMBERS;
			if (arr[randArr] == -1)
			{
				arr[randArr] = i;
				++j;
			}
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
	int historyArr = 0;
	int select[2] = { -1,-1 };
	int inputIndex[2] = { -1, -1 };
	int inputHistory[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int inputArr[20] = { '1','2','3','4','5','q','w','e','r','t','a','s','d','f','g','z','x','c','v','b' };
	int selectCount = 0;

	// 12345qwertasdfgzxcvb

	while (true)
	{
		int index = userInput2ArrIndex(inputArr);
		if (index == -1)
			continue;

		if (showCard(arr, select, inputIndex, inputHistory, index, selectCount) == -1)
			continue;

		if (selectCount == 2)
		{
			Sleep(1000);
			if (select[0] != select[1])
			{
				gotoXY(inputIndex[0] % 5, inputIndex[0] / 5);
				std::cout << "*";
				gotoXY(inputIndex[1] % 5, inputIndex[1] / 5);
				std::cout << "*";
				inputIndex[0] = -1;
				inputIndex[1] = -1;

			}
			else
			{
				inputHistory[historyArr] = inputIndex[0];
				++historyArr;
				inputHistory[historyArr] = inputIndex[1];
				++historyArr;
			}
			inputIndex[0]	= -1;
			inputIndex[1]	= -1;
			selectCount		= 0;
		}
		
		if (checkGameEnd(inputHistory))
		{
			return;
		}
	}
}

int userInput2ArrIndex(int* arr)
{
	int key = _getch();
	for (int i = 0; i < NUMBERS; ++i)
	{
		if (key == arr[i])
			return i;
	}
	return -1;
}

int showCard(int* arr, int* select, int* inputIndex, int* inputHistory, int index, int& count)
{
	for (int i = 0; i < 20; ++i)
	{
		if (inputHistory[i] == index)
			return -1;
	}

	inputIndex[count] = index;
	if ((inputIndex[0] == inputIndex[1]) && inputIndex[0] != -1)
		return -1;

	gotoXY(index % 5, index / 5);
	std::cout << arr[index];
	
	select[count] = arr[index];
	++count;
	return 0;
}

bool checkGameEnd(int* inputIndex)
{
	for (int i = 0; i < 20; ++i)
	{
		if (inputIndex[i] == -1)
			return false;
	}
	return true;
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
