#include "Sprite.h"
#include <iostream>

Sprite::Sprite(int size, std::string* arr)
{
	length = size + 1;

	sprite = new std::string[length];
	
	for (int i = 0; i < length; ++i)
	{
		sprite[i] = arr[i];
		std::cout << sprite[i] << std::endl;
	}
}

Sprite::~Sprite()
{
	delete[] sprite;
}

void Sprite::print(int index)
{
	// 함수 호출에서 Critical section 을 걸어둠.
	// 실행 중에 다른 쓰레드가 불릴 일 없음.
	std::cout << sprite[index];
}