#pragma once


class Vector2
{
private:
	short xPos;
	short yPos;

public:
	Vector2() : xPos(0), yPos(0) {  }

	inline void		setXPos(short value)	{ xPos = value; }
	inline void		setYPos(short value)	{ yPos = value; }
	inline short	getXPos()				{ return xPos; }
	inline short	getYPos()				{ return yPos; }

};