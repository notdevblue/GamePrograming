#pragma once
#include "Han.h"

// Render, Update ����ϴ� Ŭ����
// ��� �������� (����)�� ���⼭ ���� ������.
class Render
{	
private:
	// ������ ���
	HANDLE hRender;

	// ���� �Լ��� ������ Sprite �Ҹ��ڸ� �θ��� �ʰ� �ϱ� ���� ����
	HANDLE hThreadEndEvent;


	CriticalSection* han_crit; // TODO : �̰� ���⿡ �θ� �ٸ� ������ ������ ����

	// �׸� ������Ʈ�� �����͸� ����
	struct RenderData
	{
		std::vector<Vector2>	renderObjs; // �׸� ��ġ�� �������� ����
		std::vector<Sprite>		renderStr;	// �׸� ������Ʈ�� ����� ����

		INT	renderIndex;
	};
	RenderData renderData;
	
	static	DWORD WINAPI	logicThreadLaunch(LPVOID lpParam);	// ������ ���� �Լ�
			DWORD			logicThread();						// ���� ������
			VOID			draw();								// Thread ���� ȭ�鿡 �׸��� ���� ȣ���ϴ� �Լ�

			VOID			gotoxy(SHORT, SHORT);
			VOID			gotoxy(Vector2);


public:

	// vector �� Ǫ��
	void addRenderObj(const Vector2& pos, const Sprite& sprite);

	// ������ ���� �̺�Ʈ ��鷯 ����
	const HANDLE getEventHandle();
	


	CONSTRUCTOR Render();
	DESTRUCTOR ~Render();
};
