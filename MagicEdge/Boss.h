#pragma once

#include "OrkEnemy.h"

class Boss : public OrkEnemy
{
public:
	Boss(string name);
	void setLevel(int l) override;
	void Render() override;
	void Move(double x, double y) override;
};