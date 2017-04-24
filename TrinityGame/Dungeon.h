#pragma once

#include "TrinityFramework.h"
#include "Overworld.h"

class Dungeon : public Overworld
{
public:
	Dungeon(string name);
	void Generate();
};