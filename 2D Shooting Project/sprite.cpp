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
	// �Լ� ȣ�⿡�� Critical section �� �ɾ��.
	// ���� �߿� �ٸ� �����尡 �Ҹ� �� ����.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << sprite[index];
}

// Ŭ���� �ɹ������� �θ� �����ڸ� �� ����
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