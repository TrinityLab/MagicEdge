#pragma once

#include "OrkEnemy.h"

class BossEnemy : public Enemy
{
public:
	BossEnemy(Object* owner) : Enemy(owner) {}
	virtual void SetLevel(int l) override;
	virtual void Render() override;
	virtual void Move(double x, double y) override;
	virtual void OnCreated() override;
};