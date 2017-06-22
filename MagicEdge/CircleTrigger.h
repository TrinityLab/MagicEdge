#pragma once

#include "Trigger.h"

class CircleTrigger : public Trigger
{
public:
	CircleTrigger(Object* owner);
	
	void SetRadius(float r);
	float GetRadius();
private:
	float r;
};