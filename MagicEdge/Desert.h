#pragma once
#include "System.h"
#include "Overworld.h"

class Desert : public Overworld
{
public:
	Desert(string name);
	void Generate() override;
	void OnCreated() override;
	void OnDestroyd() override;
};
