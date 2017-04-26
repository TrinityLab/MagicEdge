#pragma once

#include "OrkEnemy.h"

class Boss : public OrkEnemy
{
public:
	Boss(string name);
	virtual void setLevel(int l) override;
	virtual void Render() override;
	virtual void Move(double x, double y) override;
	virtual void OnCreated() override;
};