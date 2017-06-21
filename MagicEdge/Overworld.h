#pragma once

#include "World.h"

class Overworld : public World
{
public:
	Overworld(Object* owner) : World(owner) {}
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};