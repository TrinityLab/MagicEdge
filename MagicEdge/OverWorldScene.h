#pragma once

#include "Scene.h"

class OverWorldScene : public Scene
{
private:

public:
	OverWorldScene();
protected:
	virtual void OnOpened() override;
	virtual void OnClosed() override;
	virtual void Update() override;
	string GetSceneName();
};