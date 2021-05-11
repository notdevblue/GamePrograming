#include "Sprite.h"
#include <iostream>

Sprite::Sprite(int size, std::string* arr)
{
	length = size + 1;

	sprite = new std::string[size];
	
	for (int i = 0; i < size; ++i)
	{
		sprite[i] = arr[i];
	}
}

Sprite::~Sprite()
{
	// TODO : 두번 삭제 함
	// == 오류

	// 메인 return(0); 할때 한번
	// Render 소멸자 부를때 한번 더
	delete[] sprite;
}

void Sprite::print(int index)
{
	// printf 가 안 되서
	//EnterCriticalSection(&base_spriteCrit);
	std::cout << sprite[index];
	//LeaveCriticalSection(&base_spriteCrit);
}

