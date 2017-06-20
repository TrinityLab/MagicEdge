#pragma once

#include "Object.h"
#include "MessageManager.h"

class Trigger : public ICollideEventListener
{
public:
	enum TriggerType
	{
		CircleTrigger
	};

	Trigger(double* x, double* y);
	virtual ~Trigger();

	double GetXPos();
	double GetYPos();

	TriggerType GetType();
protected:
	TriggerType type;

	double* x;
	double* y;
};