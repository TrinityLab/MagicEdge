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
		for (; iter2 != triggers.end(); iter2++)
		{
			if (IsTriggered(*iter, *iter2))
			{
				MessageManager::SendMessage((*iter)->GetOwner(), (*iter2)->GetOwner(), Message::OnCollide, (*iter)->GetOwner());
				MessageManager::SendMessage((*iter2)->GetOwner(), (*iter)->GetOwner(), Message::OnCollide, (*iter2)->GetOwner());
			}
		}
	}
}

bool TriggerChecker::IsTriggered(Trigger* t1, Trigger* t2)
{
	if (t1->GetType() == Trigger::CircleTrigger && t2->GetType() == Trigger::CircleTrigger)
	{
		CircleTrigger* ct1 = dynamic_cast<CircleTrigger*>(t1);
		CircleTrigger* ct2 = dynamic_cast<CircleTrigger*>(t2);

		Transform* t1 = ct1->GetOwner()->GetComponent<Transform>();
		Transform* t2 = ct2->GetOwner()->GetComponent<Transform>();

		float d = ct1->GetRadius() + ct2->GetRadius();

		float xDist = t1->GetXPosition() - t2->GetXPosition();
		float yDist = t1->GetYPosition() - t2->GetYPosition();

		if (xDist * xDist + yDist * yDist <= d * d)
		{
			return true;
		}
	}

	return false;
}