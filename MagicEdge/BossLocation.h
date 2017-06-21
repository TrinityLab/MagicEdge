#pragma once

#include "World.h"

class BossLocation : public World
{
public:
	BossLocation(Object* owner) : World(owner) {}
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};
