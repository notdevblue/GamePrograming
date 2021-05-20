#pragma once
#include "Han.h"



// Render, Update ����ϴ� Ŭ����
// ��� �������� (����)�� ���⼭ ���� ������.
class GameLogic
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

	// ���� �̰� �ʿ������� �𸣰���
	struct UpdateData
	{
		
	};
	UpdateData updataData;
	
	static	DWORD WINAPI	logicThreadLaunch(LPVOID lpParam);	// ������ ���� �Լ�
			DWORD			logicThread();						// ���� ������
			VOID			draw();								// Thread ���� ȭ�鿡 �׸��� ���� ȣ���ϴ� �Լ�

			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:
	// vector �� Ǫ��
	void addRenderPos(const Vector2&);
	void addRenderStr(const Sprite&);
	

	CONSTRUCTOR GameLogic();
	DESTRUCTOR ~GameLogic();
};
