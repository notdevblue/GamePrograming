#pragma once
#include "Han.h"



// Render 담당하는 클레스
// 모든 렌더링을 여기서 전부 돌린다.
class Render
{	
private:
	HANDLE	hRender;

	struct RenderData
	{
		std::vector<Vector2>	renderObjs; // 그릴 위치의 포지션을 담음
		std::vector<Sprite>		renderStr;	// 그릴 오브젝트의 모습을 담음

		INT	renderIndex;
	};
	RenderData renderData;


	
	static	DWORD WINAPI	renderThread(LPVOID lpParam); // Vector2 와 Sprite 를 구조체로 담아서 넘겨줘야함
			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:
	// vector 에 푸쉬
	void addRenderPos(Vector2);
	void addRenderStr(Sprite);


	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
