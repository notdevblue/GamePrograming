#include "Bullet.h"
#include "SoundPlayer.h"

#pragma region Constructor Destructor

// 발사 할 시 new 로 생성함
CONSTRUCTOR Bullet::Bullet()
{
	isEnabled = false;

	originalSprite[0] = "*"; // 뭔가 총알이 초라한데
	sprite.init(0, originalSprite, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

DESTRUCTOR Bullet::~Bullet()
{
	
}

#pragma endregion

Vector2 Bullet::getVector()
{
	return pos;
}

bool Bullet::collisionCheck(bool isRemote)
{
	if (!isRemote)
	{
		if (*this->pos.y >= 2 && *this->pos.y <= 4) // 오브젝트가 있는 위치
		{
			// TODO : 오브젝트 위치를 알고 있어야 함
			if (true)
			{
				onCollision();
				return true;
			}
			else return false;
		}
	}
	else
	{
		if (*this->pos.y >= 20 && *this->pos.y <= 22)
		{
			// TODO : 위랑 같음
			if (true)
			{
				onCollision();
				return true;
			}
			else return false;
		}
	}
}

void Bullet::onCollision()
{
	SoundPlayer::instance().addToSoundQueue(SOUNDTYPE::HIT);
}


void Bullet::disable(bool collision)
{
	if (collision)
	{
		this->isEnabled = false;
		return;
	}

	// 화면 밖으로 나갈 때
	if ( *this->pos.y < 0 || *this->pos.y > 30) // TODO : 특정한 조건이 필요함
	{
		this->isEnabled = false;
		return;
	}
}

void Bullet::move(int x, bool isRemote)
{
	if (!isEnabled) { return; }

	*pos.x = x;

	switch(isRemote)
	{
	case true:
		++*pos.y;
		break;

	case false:
		--*pos.y;
		break;
	}
}