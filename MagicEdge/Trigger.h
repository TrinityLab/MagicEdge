#pragma once

#include "Object.h"
#include "MessageManager.h"

class Trigger : public Component
{
public:
	enum TriggerType
	{
		CircleTrigger
	};

	Trigger(Object* owner);
	virtual void OnDestroyd();

	TriggerType GetType();

protected:
	TriggerType type;
};