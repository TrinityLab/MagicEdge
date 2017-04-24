#pragma once
#include "TrinityFramework.h"

class MainMenu : public Scene
{
protected:
	void Update() override;
public:
	MainMenu();
	void OnOpened() override;
	void OnClosed() override;
	string GetSceneName() override;
};