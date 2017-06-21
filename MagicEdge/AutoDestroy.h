#pragma once

#include "ObjectComponent.h"

class AutoDestroy : public Component
{
private:
	float time;
public:
	AutoDestroy(Object* owner) : Component(owner) {}
	void Update() override;
	void SetTime(float time);
};