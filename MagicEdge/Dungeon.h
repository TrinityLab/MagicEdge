#pragma once

#include "System.h"
#include "Overworld.h"

class Dungeon : public Overworld
{
public:
	Dungeon(string name);
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};