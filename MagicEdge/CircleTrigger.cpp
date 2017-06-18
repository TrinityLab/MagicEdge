#include "StandardInc.h"
#include "CircleTrigger.h"

CircleTrigger::CircleTrigger(float r, double *x, double *y) : Trigger(x, y), r(r)
{
	type = Trigger::CircleTrigger;
}

bool CircleTrigger::IsTriggered(Trigger* obj)
{
	switch (obj->GetType())
	{
	case Trigger::CircleTrigger:
		CircleTrigger* other = (CircleTrigger*)obj;
		if ((GetXPos() - other->GetXPos()) * (GetXPos() - other->GetXPos()) +
			(GetYPos() - other->GetYPos()) * (GetYPos() - other->GetYPos()) <= (r + other->r) * (r + other->r))
		{
			return true;
		}
		break;
	}

	return false;
}

void CircleTrigger::SetRadius(float r)
{
	this->r = r;
}

float CircleTrigger::GetRadius()
{
	return r;
}