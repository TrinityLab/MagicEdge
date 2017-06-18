#pragma once

#include "Trigger.h"

class CircleTrigger : public Trigger
{
public:
	CircleTrigger(float r, double *x, double *y);
	bool IsTriggered(Trigger* obj) override;
	
	void SetRadius(float r);
	float GetRadius();
private:
	float r;
};