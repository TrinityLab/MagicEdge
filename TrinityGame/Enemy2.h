#pragma once

#include "Enemy.h"

class Enemy2 : public Enemy
{
public:
	Enemy2(string name);
	virtual void setLevel(int l) override;
	virtual void Move(double x, double y) override;
	virtual int GetScore() override;
};