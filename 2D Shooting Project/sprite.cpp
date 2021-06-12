#include "Sprite.h"
#include <iostream>

Sprite::Sprite(int size, std::string* arr)
{
	if (arr == nullptr) return;

	length = size + 1;

	sprite = new std::string[length];
}

Sprite::~Sprite()
{
	delete[] sprite;
}

void Sprite::print(int index)
{
	// �Լ� ȣ�⿡�� Critical section �� �ɾ��.
	// ���� �߿� �ٸ� �����尡 �Ҹ� �� ����.
	std::cout << sprite[index];
}

// Ŭ���� �ɹ������� �θ� �����ڸ� �� ����
void Sprite::init(int size, std::string* arr)
{
	length = size + 1;

	sprite = new std::string[length];

	for (int i = 0; i < length; ++i)
	{
		sprite[i] = arr[i];
		std::cout << sprite[i] << std::endl;
	}
}