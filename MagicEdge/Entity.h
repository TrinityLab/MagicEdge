#pragma once

#include "Block.h"
#include "ObstacleMap.h"

class Entity : public Component
{
protected:
	double speed;
	int level;
	int exp;
	int damage;

public:
	Entity(Object* owner) : Component(owner) {}

	virtual void OnEnabled() override;
	virtual void OnKilled();

	virtual void SetLevel(int L);
	virtual void SetExp(int E);
	virtual void Move(double deltaX, double deltaY);
	int GetLevel();
	int GetExp();
	void SetSpeed(double speed);
	double GetSpeed();
	int GetDamage();
};

