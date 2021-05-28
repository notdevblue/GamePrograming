#pragma once

#define _WINSOCK2API_
#include <Windows.h>
#include <vector>

#include "Vector2.h"
#include "Sprite.h"
//#include "Base.h"

#define CONSTRUCTOR
#define DESTRUCTOR

#define FONT_SIZE 11


#ifndef CSESSION
#define CSESSION
#pragma region CRITICAL_SECTION RAII


class GetLock;

// ����� CriticalSection �� ���ؼ� lock, unlock �ϸ� �ȵ˴ϴ�.
class CriticalSection final
{
public:
	CriticalSection()
	{
		InitializeCriticalSection(&m_cs);
	}
	~CriticalSection()
	{
		DeleteCriticalSection(&m_cs);
	}
private:
	friend class GetLock;

	void lock()
	{
		EnterCriticalSection(&m_cs);
	}
	void unlock()
	{
		LeaveCriticalSection(&m_cs);
	}


	explicit operator bool() { return true; }

private:
	CRITICAL_SECTION m_cs;
};




// RAII ����
class GetLock final
{
public:
	GetLock(CriticalSection& plock) : m_cs(plock)
	{
		m_cs.lock();
	}
	~GetLock()
	{
		m_cs.unlock();
	}

private:
	CriticalSection& m_cs;
};

#define CSLOCK


#pragma endregion
#endif



#define DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif