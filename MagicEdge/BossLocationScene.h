#pragma once

#include "OverWorldScene.h"

class BossLocationScene : public OverWorldScene
{
public:
	string GetSceneName() override;
	void OnOpened() override;
	void OnClosed() override;
};