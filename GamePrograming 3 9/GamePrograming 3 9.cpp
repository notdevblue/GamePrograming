#include <iostream>
#include <time.h>

int main()
{
    int randNum;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        randNum = rand();
        printf("RandomNum: %d\r\n", randNum);
    }



    return(0);
}