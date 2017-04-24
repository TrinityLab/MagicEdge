#pragma once

#include "World.h"

class Overworld : public World
{
public:
	Overworld(string name);
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};