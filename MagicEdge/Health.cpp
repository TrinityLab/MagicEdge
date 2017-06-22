#include "StandardInc.h"
#include "Health.h"

void Health::SetHealth(float h)
{
	this->health = h;

	if (health > maxHealth)
		health = maxHealth;

	if (health < 0)
		health = 0;
}

float Health::GetHealth()
{
	return health;
}

void Health::HealthDown(float h)
{
	health -= h;
	if (health < 0)
		health = 0;
}

void Health::HealthUp(float h)
{
	health += h;
	if (health > maxHealth)
		health = maxHealth;
}

void Health::SetMaxHealth(float h)
{
	maxHealth = h;
}

float Health::GetMaxHealth()
{
	return maxHealth;
}