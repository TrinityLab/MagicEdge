#include "StandardInc.h"
#include "Trigger.h"
#include "TriggerChecker.h"

Trigger::Trigger(Object* owner) : Component(owner)
{
	TriggerChecker::AddTrigger(this);
}

void Trigger::OnDestroyd()
{
	TriggerChecker::RemoveTrigger(this);
}

Trigger::TriggerType Trigger::GetType()
{
	return type;
}
