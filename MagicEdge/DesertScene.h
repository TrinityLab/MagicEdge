#pragma once

#include "System.h"
#include "OverWorldScene.h"

class DesertScene: public OverWorldScene
{
public:
	string GetSceneName() override;
	void OnOpened() override;
	void OnClosed() override;
};