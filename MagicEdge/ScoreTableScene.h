#pragma once

#include "ScoreTable.h"
#include "Scene.h"

class ScoreTableScene : public Scene
{
private:
	Object* exitButton;
public:
	ScoreTableScene();
	string GetSceneName() override;
	void OnOpened() override;
	void Update() override;
};