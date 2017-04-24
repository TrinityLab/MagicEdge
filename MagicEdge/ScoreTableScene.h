#pragma once

#include "ScoreTable.h"
#include "Scene.h"

class ScoreTableScene : public Scene
{
public:
	ScoreTableScene();
	string GetSceneName() override;
	void OnOpened() override;
	void Update() override;
};