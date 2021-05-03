#include <Windows.h>
#include <deque>
#include "Han.h"

#ifdef DEBUG
#include <stdio.h>
#endif

// Render 담당하는 클레스
// 다른 클레스의 Render();를 여기서 전부 돌린다.
class Render
{	
private:
	HANDLE	hRender;
	INT		renderIndex;
	//std::deque</*렌더 담당 클레스*/> renderObject;

public:
	VOID gotoxy(SHORT, SHORT);

	static DWORD WINAPI renderThread(LPVOID lpParam);


	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
