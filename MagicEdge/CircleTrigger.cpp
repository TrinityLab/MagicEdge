#include "StandardInc.h"
#include "CircleTrigger.h"

CircleTrigger::CircleTrigger(Object* owner) : Trigger(owner)
{
	type = Trigger::CircleTrigger;
}

void CircleTrigger::SetRadius(float r)
{
	this->r = r;
}

float CircleTrigger::GetRadius()
{
	return r;
}