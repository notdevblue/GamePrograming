#pragma once
#include "Han.h"

// Render, Update 담당하는 클레스
// 모든 렌더링과 (연산)을 여기서 전부 돌린다.
class Render
{	
private:
	// 쓰레드 헨들
	HANDLE hRender;

	// 메인 함수가 끝나서 Sprite 소멸자를 부르지 않게 하기 위한 변수
	HANDLE hThreadEndEvent;


	CriticalSection* han_crit; // TODO : 이걸 여기에 두면 다른 곳에서 접근을 못함

	// 그릴 오브젝트의 데이터를 담음
	struct RenderData
	{
		std::vector<Vector2>	renderObjs; // 그릴 위치의 포지션을 담음
		std::vector<Sprite>		renderStr;	// 그릴 오브젝트의 모습을 담음

		INT	renderIndex;
	};
	RenderData renderData;
	
	static	DWORD WINAPI	logicThreadLaunch(LPVOID lpParam);	// 쓰레드 시작 함수
			DWORD			logicThread();						// 실제 쓰레드
			VOID			draw();								// Thread 에서 화면에 그리기 위해 호출하는 함수

			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:

	// vector 에 푸쉬
	void addRenderObj(const Vector2& pos, const Sprite& sprite);

	// 쓰레드 종료 이벤트 헨들러 게터
	const HANDLE getEventHandle();
	


	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
