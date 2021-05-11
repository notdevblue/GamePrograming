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


	
	static	DWORD WINAPI	renderThreadStart(LPVOID lpParam);	// 쓰레드 시작 함수
			DWORD			renderThread();						// 실제 쓰레드
			VOID			draw();								// Thread 에서 화면에 그리기 위해 호출하는 함수

			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:
	// vector 에 푸쉬
	void addRenderPos(const Vector2&);
	void addRenderStr(const Sprite&);
	

	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
