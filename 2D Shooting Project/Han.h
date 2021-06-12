#pragma once

#define _WINSOCK2API_
#include <Windows.h>
#include <vector>

// std::cout << msg << std::endl 은 원자성이 보장되지 않음.
// 컨테스트 스위칭이 일어나게 되면 매우 큰 일이 일어남
#include <stdio.h>

#include "Vector2.h"
#include "Sprite.h"
//#include "Base.h"

#define CONSTRUCTOR
#define DESTRUCTOR

#define FONT_SIZE 11

// 주석 메세지 설명
/*
TODO : 할 일
WARN : 주의
BUG  : BUG

앞 메세지가 없는 주석은 무언가를 설명하거나 생각을 적어 둔 주석이에요.
*/


// 소리 종류
// WARN : END_OF_ENUM 뒤에는 절때로 더 추가하면 안됩니다.
enum class SOUNDTYPE
{
	FIRE = 0,
	HIT,
	END_OF_ENUM // WARN : no more enums please.
};