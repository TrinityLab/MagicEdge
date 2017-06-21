#pragma once

#include "Scene.h"
#include "Button.h"

class MainMenu : public Scene
{
protected:
	Button* startButton;
	Button* scoresButton;
	Button* exitButton;
	void Update() override;

public:
	MainMenu();
	void OnOpened() override;
	void OnClosed() override;
	string GetSceneName() override;
};