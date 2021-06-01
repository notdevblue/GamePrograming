#pragma once

class Enemy
{
private:
	int x;
	int y;

public:

	void setEnemy();
	void drawEnemy();
	bool checkEnd();

	const inline int getX() { return x; }
	const inline int getY() { return y; }
};

