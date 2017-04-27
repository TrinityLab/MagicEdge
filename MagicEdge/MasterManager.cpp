#include "MasterManager.h"
#include "MainMenu.h"
#include "ScoreTableScene.h"
#include "LoginScene.h"

MasterManager::MasterManager() : SceneManager()
{
	AddScene(new MainMenu());
	AddScene(new OverWorldScene());
	AddScene(new DungeonScene());
	AddScene(new DesertScene());
	AddScene(new ScoreTableScene());
	AddScene(new LoginScene());

	OpenScene("LoginScene");
}