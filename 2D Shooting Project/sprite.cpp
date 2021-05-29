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
	// TODO : �ι� ���� ��
	// == ����

	// ���� return(0); �Ҷ� �ѹ�
	// Vector[i]�� ���� �� Render �Ҹ��� �θ��� �ѹ� �� �Ҹ�
	// Vector.at(i)�� ���� �� ������ �� ���µ� ȭ�鿡 ����� ���� ����.
	delete[] sprite;
}

void Sprite::print(int index)
{
	// printf �� �� �Ǽ�
	//EnterCriticalSection(&base_spriteCrit);
	std::cout << sprite[index];
	//LeaveCriticalSection(&base_spriteCrit);
}