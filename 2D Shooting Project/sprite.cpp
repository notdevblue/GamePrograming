#include "Sprite.h"
#include <iostream>
#include <Windows.h>

Sprite::Sprite(int size, std::string* arr, int color)
{
	if (arr == nullptr) return;

	length = size + 1;

	sprite = new std::string[length];

	this->color = color;
}

Sprite::~Sprite()
{
	delete[] sprite;
}

void Sprite::print(int index)
{
	// 함수 호출에서 Critical section 을 걸어둠.
	// 실행 중에 다른 쓰레드가 불릴 일 없음.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << sprite[index];
}

// 클래스 맴버변수로 두면 생성자를 못 돌림
void Sprite::init(int size, std::string* arr, int color)
{
	length = size + 1;

	sprite = new std::string[length];

	for (int i = 0; i < length; ++i)
	{
		sprite[i] = arr[i];
	}

	this->color = color;
}