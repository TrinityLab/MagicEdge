#pragma once

#include "Trigger.h"

class TriggerChecker
{
private:
	static list<Trigger*> triggers;
public:
	static void AddTrigger(Trigger* trigger);
	static void RemoveTrigger(Trigger* trigger);
	static void Update();
	static bool IsTriggered(Trigger* t1, Trigger* t2);
};