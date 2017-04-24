#pragma once

#include "AnimatedObject.h"

class Blood : public AnimatedObject
{
protected:
	double time;
public:
	Blood(string name);
	void Update();
};