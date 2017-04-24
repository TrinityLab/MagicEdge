#pragma once

#include "Block.h"

class Stone : public Block
{
public:
	Stone(int x, int y);
	string GetBlockName() override;
};