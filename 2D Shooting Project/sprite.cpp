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
	// TODO : 두번 삭제 함
	// == 오류

	// 메인 return(0); 할때 한번
	// Vector[i]로 접근 시 Render 소멸자 부를때 한번 더 불림
	// Vector.at(i)로 접근 시 오류는 안 나는데 화면에 출력이 되지 않음.
	delete[] sprite;
}

void Sprite::print(int index)
{
	// printf 가 안 되서
	//EnterCriticalSection(&base_spriteCrit);
	std::cout << sprite[index];
	//LeaveCriticalSection(&base_spriteCrit);
}