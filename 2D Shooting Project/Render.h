#include <Windows.h>
#include <deque>
#include "Han.h"

#ifdef DEBUG
#include <stdio.h>
#endif

// Render ����ϴ� Ŭ����
// �ٸ� Ŭ������ Render();�� ���⼭ ���� ������.
class Render
{	
private:
	HANDLE	hRender;
	INT		renderIndex;
	//std::deque</*���� ��� Ŭ����*/> renderObject;

public:
	VOID gotoxy(SHORT, SHORT);

	static DWORD WINAPI renderThread(LPVOID lpParam);


	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
