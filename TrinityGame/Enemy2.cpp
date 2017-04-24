#include "Enemy2.h"
#include "DifficultyInfo.h"

Enemy2::Enemy2(string name) : Enemy(name)
{
	SetTexture(ResourceManager::GetTexture("Enemy2"), 1, 1, 0, false);

	setLevel(max(rand() % 3 - 1 + difficulty, 1));
}

void Enemy2::Move(double x, double y)
{
	Entity::Move(x, y);

	if (x < 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("Enemy2Left"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("Enemy2Right"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		SetTexture(ResourceManager::GetTexture("Enemy2Back"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		SetTexture(ResourceManager::GetTexture("Enemy2"), 1, 1, 0, false);
	}
}

void Enemy2::setLevel(int l)
{
	Enemy::setLevel(l);

	setSpeed(40 * pow(1.05, l));

	damage = l * 50;

	attackRadius = l * 2;

	attackReloadTime = max(0.3, 5.0);
}

int Enemy2::GetScore()
{
	return getLevel() * 2;
}