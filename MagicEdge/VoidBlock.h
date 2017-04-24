#pragma once

#include "Block.h"

class VoidBlock : public Block
{
public:
	VoidBlock(int x, int y);
	void Update() override;
	void Render() override;
	void OnPlayerInteract() override;
	string GetBlockName() override;
};