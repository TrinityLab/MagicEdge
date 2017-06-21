#pragma once

#include "ObjectComponent.h"

class Portal : public Component
{
protected:
	static bool go;
	static bool activity;
public:
	Portal(Object* obj) : Component(obj) {}
	void Update() override;
	void OnEnabled() override;
	static bool NeedGo();
};