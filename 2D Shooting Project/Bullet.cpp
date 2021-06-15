#include "Bullet.h"
#include "SoundPlayer.h"

#pragma region Constructor Destructor

// �߻� �� �� new �� ������
CONSTRUCTOR Bullet::Bullet()
{
	isEnabled = false;

	originalSprite[0] = "*"; // ���� �Ѿ��� �ʶ��ѵ�
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
		if (*this->pos.y >= 2 && *this->pos.y <= 4) // ������Ʈ�� �ִ� ��ġ
		{
			// TODO : ������Ʈ ��ġ�� �˰� �־�� ��
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
			// TODO : ���� ����
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

	// ȭ�� ������ ���� ��
	if ( *this->pos.y < 0 || *this->pos.y > 30) // TODO : Ư���� ������ �ʿ���
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