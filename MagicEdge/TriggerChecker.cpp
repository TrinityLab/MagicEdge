#include "StandardInc.h"
#include "TriggerChecker.h"
#include "MessageManager.h"
#include "CircleTrigger.h"
#include "Player.h"

list<Trigger*> TriggerChecker::triggers;

void TriggerChecker::AddTrigger(Trigger* trigger)
{
	triggers.push_back(trigger);
}

void TriggerChecker::RemoveTrigger(Trigger* trigger)
{
	for (auto iter = triggers.begin(); iter != triggers.end();)
	{
		if (*iter == trigger)
		{
			auto iter2 = iter;
			iter++;

			triggers.erase(iter2);
		}
		else
		{
			iter++;
		}
	}
}

void TriggerChecker::Update()
{
	if (triggers.size() == 0)
		return;

	auto lastElem = triggers.end();
	lastElem--;

	for (auto iter = triggers.begin(); iter != lastElem; iter++)
	{
		auto iter2 = iter;
		iter2++;
		for ( ; iter2 != triggers.end(); iter2++)
		{
			if (IsTriggered(*iter, *iter2))
			{
				MessageManager::SendMessage(*iter, *iter2, Message::OnCollide, *iter);
				MessageManager::SendMessage(*iter2, *iter, Message::OnCollide, *iter2);
			}
		}
	}
}

bool TriggerChecker::IsTriggered(Trigger* t1, Trigger* t2)
{
	if (t1->GetType() == Trigger::CircleTrigger && t2->GetType() == Trigger::CircleTrigger)
	{
		CircleTrigger* ct1 = (CircleTrigger*)t1;
		CircleTrigger* ct2 = (CircleTrigger*)t2;

		float d = ct1->GetRadius() + ct2->GetRadius();

		float xDist = ct1->GetXPos() - ct2->GetXPos();
		float yDist = ct1->GetYPos() - ct2->GetYPos();

		if (xDist * xDist + yDist * yDist <= d * d)
		{
			return true;
		}
	}

	return false;
}