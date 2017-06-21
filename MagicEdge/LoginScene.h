#pragma once

#include "Scene.h"

class LoginScene : public Scene
{
private:
	Object* okButton;
	Object* textField;
public:
	LoginScene();
	string GetSceneName() override;
	void OnOpened() override;
	void OnClosed() override;
	void Update() override;
};