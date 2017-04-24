#pragma once

#include "StandardInc.h"
#include "InsectEnemy.h"

class OrkEnemy : public InsectEnemy
{
public:
	OrkEnemy(string name);
	virtual void setLevel(int l) override;
	virtual void Move(double x, double y) override;
	virtual int GetScore() override;
};