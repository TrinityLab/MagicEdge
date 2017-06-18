#include "StandardInc.h"
#include "TriggerChecker.h"
#include "MessageManager.h"

list<Trigger*> TriggerChecker::triggers;

void TriggerChecker::AddTrigger(Trigger* trigger)
{
	triggers.push_back(trigger);
}

void TriggerChecker::RemoveTrigger(Trigger* trigger)
{
	for (auto iter = triggers.begin(); iter != triggers.end(); iter++)
	{
		if (*iter == trigger)
		{
			triggers.erase(iter);
			return;
		}
	}
}

void TriggerChecker::Update()
{
	auto lastIter = triggers.end();
	lastIter--;

	for (auto iter = triggers.begin(); iter != lastIter; iter++)
	{
		auto iter2 = iter;
		iter2++;

		for (; iter2 != triggers.end(); iter2++)
		{
			if ((*iter)->IsTriggered(*iter2))
			{
				MessageManager::SendMessage((IEventListener*)*iter, (IEventListener*)*iter2, Message::OnCollide, 0);
			}
		}
	}
}