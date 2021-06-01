#pragma once
class Missile
{
private:
	int x;
	int y;

	bool isEnemy;

public:

	const inline int getX() { return x; }
	const inline int getY() { return y; }

	void setMissile(int _x, int _y, bool isEnemy = false);
	void drawMissile();
	bool checkEnd();
	bool checkCollision(const int _x, const int _y);
};
