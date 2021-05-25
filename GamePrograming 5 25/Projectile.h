#pragma once
class Projectile
{
private:
	int x;
	int y;

	bool bMoveLeft;





public:

	Projectile();

	void setMissile(int _y);
	void moveMissile();
	void drawMissile();
	bool checkEnd();
	bool checkCollision(Projectile);



};

