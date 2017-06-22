#include "StandardInc.h"
#include "Trigger.h"
#include "TriggerChecker.h"

Trigger::Trigger(Object* owner) : Component(owner)
{
	TriggerChecker::AddTrigger(this);
}

Trigger::~Trigger()
{
	TriggerChecker::RemoveTrigger(this);
}

Trigger::TriggerType Trigger::GetType()
{
	return type;
}
