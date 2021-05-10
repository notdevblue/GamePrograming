#pragma once
#include "Han.h"



// Render ����ϴ� Ŭ����
// ��� �������� ���⼭ ���� ������.
class Render
{	
private:
	HANDLE	hRender;

	struct RenderData
	{
		std::vector<Vector2>	renderObjs; // �׸� ��ġ�� �������� ����
		std::vector<Sprite>		renderStr;	// �׸� ������Ʈ�� ����� ����

		INT	renderIndex;
	};
	RenderData renderData;


	
	static	DWORD WINAPI	renderThreadStart(LPVOID lpParam); // Vector2 �� Sprite �� ����ü�� ��Ƽ� �Ѱ������
			DWORD			renderThread();
			VOID			draw();
			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:
	// vector �� Ǫ��
	void addRenderPos(Vector2);
	void addRenderStr(Sprite);
	

	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
