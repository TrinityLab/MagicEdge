#include "StandardInc.h"
#include "CircleTrigger.h"

CircleTrigger::CircleTrigger(float r, double *x, double *y) : Trigger(x, y)
{
	type = Trigger::CircleTrigger;

	this->r = r;
}

void CircleTrigger::SetRadius(float r)
{
	this->r = r;
}

float CircleTrigger::GetRadius()
{
	return r;
}