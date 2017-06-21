#pragma once

#include "World.h"

class Dungeon : public World
{
public:
	Dungeon(Object* owner) : World(owner) {}
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};