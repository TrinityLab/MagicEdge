#include "StandardInc.h"
#include "Trigger.h"
#include "TriggerChecker.h"

Trigger::Trigger(double *x, double *y) : x(x), y(y)
{
	TriggerChecker::AddTrigger(this);
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