#pragma once

#include "Block.h"

class Altar : public Block
{
public:
	Altar(int x, int y);
	string GetBlockName() override;
	void Update() override;
};

