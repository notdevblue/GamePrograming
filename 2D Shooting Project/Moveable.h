#pragma once

// 움직이는 모든건 이걸 상속받음.
// 의미가 있는지는 모르겠지만
class Moveable abstract
{
private:


public:

	virtual void move(bool isRemote = false) abstract = 0;
};

