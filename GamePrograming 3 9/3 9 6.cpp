//#define THIS

#ifdef THIS
#include <iostream>
#include <time.h>

#define Randomize() srand(unsigned int(time(NULL)));
#define random(n) (rand()%(n) + 1)
int main()
{
	int randNum;
	
	Randomize();

	for (int i = 0; i < 10; ++i)
	{
		randNum = random(6);
		printf("RandNum: %d\r\n", randNum);
	}



	return(0);
}
#endif