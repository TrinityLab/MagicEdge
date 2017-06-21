#pragma once

#include "ObjectComponent.h"

class Mana : public Component
{
private:
	float mana = 100.0f;
	float maxMana = 100.0f;

public:
	Mana(Object* obj) : Component(obj) {};
	void SetMana(float h);
	float GetMana();
	void ManaDown(float h);
	void ManaUp(float h);
	void SetMaxMana(float h);
	float GetMaxMana();
};