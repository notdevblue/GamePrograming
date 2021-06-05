#pragma once

#define _WINSOCK2API_
#include <Windows.h>

#ifndef CSESSION
#define CSESSION
#pragma region CRITICAL_SECTION RAII

class GetLock;

// 절대로 CriticalSection 을 통해서 lock, unlock 하면 안됩니다.
class CriticalSession final
{
public:
	CriticalSession()
	{
		InitializeCriticalSection(&m_cs);
	}
	~CriticalSession()
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




// RAII 패턴
// 고마워요 스택오버플로우!
class GetLock final
{
public:
	GetLock(CriticalSession& plock) : m_cs(plock)
	{
		m_cs.lock();
	}
	~GetLock()
	{
		m_cs.unlock();
	}

private:
	CriticalSession& m_cs;
};

// Critical Section Lock
// 사실 아무것도 하지 않습니다.
// 그저 명시적으로 "이거슨 RAII 패턴이다아아" 라고 하기 위한 것
#define CSLOCK


#pragma endregion
#endif

