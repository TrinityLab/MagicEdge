#pragma once

#include "Entity.h"

class Enemy : public Entity
{
protected:
	float attackRadius;
	float reloadTime;
	float currentReloadTime;

public:
	Enemy(Object* owner) : Entity(owner) {}

	virtual void Update() override;
	virtual void OnCreated() override;
	virtual void Move(double deltaX, double deltaY) override;
	virtual void SetLevel(int L);
	virtual void OnKilled() override;

	virtual int GetRewardScore();
};