#include "StandardInc.h"
#include "Health.h"

void Health::SetHealth(float h)
{
	this->health = h;
}

float Health::GetHealth()
{
	return health;
}

void Health::HealthDown(float h)
{
	health -= h;
}

void Health::HealthUp(float h)
{
	health += h;
}

void Health::Update()
{
	if (health <= 0.0f)
	{
		/* --- */
	}
}

void Health::SetMaxHealth(float h)
{
	maxHealth = h;
}

float Health::GetMaxHealth()
{
	return maxHealth;
}