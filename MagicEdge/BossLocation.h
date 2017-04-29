#pragma once

#include "System.h"
#include "Overworld.h"

class BossLocation : public Overworld
{
public:
	BossLocation(string name);
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};
