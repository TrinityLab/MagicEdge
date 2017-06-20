#include "StandardInc.h"
#include "Trigger.h"
#include "TriggerChecker.h"

Trigger::Trigger(double *x, double *y)
{
	TriggerChecker::AddTrigger(this);

	this->x = x;
	this->y = y;
}

double Trigger::GetXPos()
{
	return *x;
}

double Trigger::GetYPos()
{
	return *y;
}

Trigger::TriggerType Trigger::GetType()
{
	return type;
}

Trigger::~Trigger()
{
	TriggerChecker::RemoveTrigger(this);
}
