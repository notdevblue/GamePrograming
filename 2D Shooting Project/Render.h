#pragma once
#include "Han.h"



// Render ����ϴ� Ŭ����
// �ٸ� Ŭ������ Render();�� ���⼭ ���� ������.
class Render
{	
private:
	HANDLE	hRender;
	INT		renderIndex;
	//std::deque</*���� ��� Ŭ����*/> renderObject;

protected:
	VOID gotoxy(SHORT, SHORT);


	static DWORD WINAPI renderThread(LPVOID lpParam);

	virtual VOID addRender() = 0;

public:
	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
