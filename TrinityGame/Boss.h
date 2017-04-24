#pragma once

#include "Enemy2.h"

class Boss : public Enemy2
{
public:
	Boss(string name);
	void setLevel(int l) override;
	void Render() override;
	void Move(double x, double y) override;
};