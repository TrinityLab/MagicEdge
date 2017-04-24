#include "MasterManager.h"
#include "MainMenu.h"
#include "ScoreTableScene.h"

MasterManager::MasterManager() : SceneManager()
{
	AddScene(new MainMenu());
	AddScene(new OverWorldScene());
	AddScene(new DungeonScene());
	AddScene(new ScoreTableScene());

	OpenScene("MainMenu");
}