#pragma once

#include "StandardInc.h"
#include "Enemy.h"

class OrkEnemy : public Enemy
{
public: 
	OrkEnemy(Object* owner) : Enemy(owner) {}
	virtual void SetLevel(int l) override;
	virtual void Move(double x, double y) override;
	virtual int GetRewardScore() override;
	virtual void OnCreated() override;
};