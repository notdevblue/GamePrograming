//#define THIS

#ifdef THIS
#include <iostream>
#include <time.h>

int main()
{
#pragma region 난수
    int randNum;
    
    time_t j = time(NULL);
    printf("time(): %lld\r\n", j);


    srand((unsigned int)time(NULL));


    for (int i = 0; i < 10; ++i)
    {
        randNum = rand();
        printf("RandomNum: %d\r\n", randNum);
    }
#pragma endregion

#pragma region 시간
    struct tm t = { 0 }; 
    localtime_s(&t, &j);
    printf("%d년 %d월 %d일", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
#pragma endregion

    return(0);
}
#endif