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
	// TODO : �ι� ���� ��
	// == ����

	// ���� return(0); �Ҷ� �ѹ�
	// Render �Ҹ��� �θ��� �ѹ� ��
	delete[] sprite;
}

void Sprite::print(int index)
{
	// printf �� �� �Ǽ�
	//EnterCriticalSection(&base_spriteCrit);
	std::cout << sprite[index];
	//LeaveCriticalSection(&base_spriteCrit);
}

