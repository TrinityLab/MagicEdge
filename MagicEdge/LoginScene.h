#pragma once

#include "System.h"

class LoginScene : public Scene
{
public:
	LoginScene();
	string GetSceneName() override;
	void OnOpened() override;
	void OnClosed() override;
	void Update() override;
};