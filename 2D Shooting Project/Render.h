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


	
	static	DWORD WINAPI	renderThreadStart(LPVOID lpParam);	// ������ ���� �Լ�
			DWORD			renderThread();						// ���� ������
			VOID			draw();								// Thread ���� ȭ�鿡 �׸��� ���� ȣ���ϴ� �Լ�

			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:
	// vector �� Ǫ��
	void addRenderPos(const Vector2&);
	void addRenderStr(const Sprite&);
	

	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
