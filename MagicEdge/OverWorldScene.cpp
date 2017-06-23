#include "StandardInc.h"
#include "OverWorldScene.h"
#include "Overworld.h"
#include "Player.h"
#include "ScoreTable.h"
#include "Button.h"
#include "Portal.h"
#include "ObjectFactory.h"
#include "SceneManager.h"

OverWorldScene::OverWorldScene() : Scene()
{

}

void OverWorldScene::OnOpened()
{
	Object* world = ObjectFactory::CreateOverworld();
	world->GetComponent<Overworld>()->Generate();

	int x, y;
	while (true)
	{
		x = World::WIDTH / 4 + rand() % World::WIDTH / 2;
		y = World::HEIGHT / 4 + rand() % World::HEIGHT / 2;

		if (!ObstacleMap::IsObstacle(x, y))
		{
			break;
		}
	}

	Object* player = ObjectFactory::SpawnPlayer(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
}

void OverWorldScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}

string OverWorldScene::GetSceneName()
{
	return "Overworld";
}

void OverWorldScene::Update()
{
	Scene::Update();

	Object* button = SceneManager::GetCurrentScene()->FindObjectWithTag("Exit2");
	if (button != nullptr)
	{
		if (button->GetComponent<Button>()->IsPressed())
		{
			SceneManager::OpenScene("MainMenu");
		}
	}

	if (Portal::NeedGo())
	{
		int chance = rand() % 75;
		if (chance< 25)
		{
			SceneManager::OpenScene("Overworld");
		}
		if(chance>=25 && chance<50)
		{
			SceneManager::OpenScene("DungeonScene");
		}
		if (chance >= 50 && chance < 75)
		{
			SceneManager::OpenScene("DesertScene");
		}
	}
}