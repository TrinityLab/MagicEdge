#pragma once

#include "Block.h"

class Portal : public AnimatedObject
{
protected:
	static bool go;
	static bool activity;
public:
	Portal(string name);
	void Update() override;
	static bool NeedGo();
};