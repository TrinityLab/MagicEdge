#pragma once

#include "System.h"

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