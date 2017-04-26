#include "OrkEnemy.h"
#include "DifficultyInfo.h"

OrkEnemy::OrkEnemy(string name) : InsectEnemy(name)
{
	
}

void OrkEnemy::Move(double x, double y)
{
	Entity::Move(x, y);

	if (x < 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("OrkEnemyLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("OrkEnemyRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		SetTexture(ResourceManager::GetTexture("OrkEnemyBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		SetTexture(ResourceManager::GetTexture("OrkEnemy"), 1, 1, 0, false);
	}
}

void OrkEnemy::setLevel(int l)
{
	InsectEnemy::setLevel(l);

	setSpeed(40 * pow(1.05, l));

	damage = l * 50;

	attackRadius = l * 2;

	attackReloadTime = max(0.3, 5.0);
}

int OrkEnemy::GetScore()
{
	return getLevel() * 2;
}

void OrkEnemy::OnCreated()
{
	InsectEnemy::OnCreated();

	SetTexture(ResourceManager::GetTexture("OrkEnemy"), 1, 1, 0, false);

	setLevel(max(rand() % 3 - 1 + difficulty, 1));
}