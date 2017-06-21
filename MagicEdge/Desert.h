#pragma once

#include "World.h"

class Desert : public World
{
public:
	Desert(Object* owner) : World(owner) {}
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};
