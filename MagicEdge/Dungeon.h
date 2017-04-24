#pragma once

#include "System.h"
#include "Overworld.h"

class Dungeon : public World
{
public:
	Dungeon(string name);
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};