#define THIS

#ifdef THIS
#include <iostream>
#include <time.h>

int main()
{
	int randNum;
	srand(unsigned int(time(NULL)));

	for (int i = 0; i < 10; ++i)
	{
		randNum = rand() % 10;
		printf("RandNum: %d", randNum + 1);
	}



	return(0);
}
#endif