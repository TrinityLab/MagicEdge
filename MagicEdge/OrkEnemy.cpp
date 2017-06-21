#include "StandardInc.h"
#include "OrkEnemy.h"
#include "DifficultyInfo.h"
#include "Object.h"
#include "ResourceManager.h"

void OrkEnemy::Move(double x, double y)
{
	Entity::Move(x, y);

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	if (x < 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("OrkEnemyLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("OrkEnemyRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		r->SetTexture(ResourceManager::GetTexture("OrkEnemyBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		r->SetTexture(ResourceManager::GetTexture("OrkEnemy"), 1, 1, 0, false);
	}
}

void OrkEnemy::SetLevel(int l)
{
	Entity::SetLevel(l);

	SetSpeed(40 * pow(1.05, l));

	damage = l * 50;

	attackRadius = l * 2;

	reloadTime = max(0.3, 5.0);
}

int OrkEnemy::GetRewardScore()
{
	return GetLevel() * 2;
}

void OrkEnemy::OnCreated()
{
	Enemy::OnCreated();

	GetOwner()->GetComponent<Renderer>()->SetTexture(
		ResourceManager::GetTexture("OrkEnemy"), 1, 1, 0, false);

	SetLevel(max(rand() % 3 - 1 + difficulty, 1));
}