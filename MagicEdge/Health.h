#pragma once

#include "ObjectComponent.h"

class Health : public Component
{
private:
	float health = 100.0f;
	float maxHealth = 100.0f;

public:
	Health(Object* obj) : Component(obj) {};
	void SetHealth(float h);
	float GetHealth();
	void HealthDown(float h);
	void HealthUp(float h);
	void SetMaxHealth(float h);
	float GetMaxHealth();

	void Update();
};