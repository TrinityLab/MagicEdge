#pragma once

#include "Block.h"
#include "ObstacleMap.h"
#include "MessageManager.h"

class Entity : public Component, public ICollideEventListener
{
protected:
	double speed;
	int level;
	int exp;
	int damage;

public:
	Entity(Object* owner) : Component(owner) {}

	virtual void OnCreated() override;
	virtual void OnKilled();

	virtual void SetLevel(int L);
	virtual void SetExp(int E);
	virtual void Move(double deltaX, double deltaY);
	virtual void TakeDamage(float damage);

	virtual void OnCollide(Object* obj) override;

	int GetLevel();
	int GetExp();
	void SetSpeed(double speed);
	double GetSpeed();
	int GetDamage();
};

