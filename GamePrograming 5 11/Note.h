#pragma once

class Note
{
private:
	// 1 ~ 7
	int index;
	int x;
	int y;

public:
#pragma region Get Set

	//inline int getX()
	//{
	//	return x;
	//}
	//inline int getY()
	//{
	//	return y;
	//}

#pragma endregion

	
	void downNote();

	void checkEnd();

	void playSound();

	void initNote();
	void drawNote();
};