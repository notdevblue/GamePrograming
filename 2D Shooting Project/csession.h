#pragma once

#define _WINSOCK2API_
#include <Windows.h>

#ifndef CSESSION
#define CSESSION
#pragma region CRITICAL_SECTION RAII

class GetLock;

// ����� CriticalSection �� ���ؼ� lock, unlock �ϸ� �ȵ˴ϴ�.
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




// RAII ����
// ������ ���ÿ����÷ο�!
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
// ��� �ƹ��͵� ���� �ʽ��ϴ�.
// ���� ��������� "�̰Ž� RAII �����̴پƾ�" ��� �ϱ� ���� ��
#define CSLOCK


#pragma endregion
#endif

