#include "OverWorldScene.h"
#include "Overworld.h"
#include "Viewer.h"
#include "Player.h"
#include "ScoreTable.h"
#include "Button.h"
#include "Portal.h"

OverWorldScene::OverWorldScene() : Scene()
{

}

void OverWorldScene::OnOpened()
{
	Overworld* world = new Overworld("World");
	world->Generate();

	Player* player = new Player("Player");

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

	player->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
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

	Button* button = (Button*)SceneManager::GetCurrentScene()->FindObject("Exit");
	if (button != NULL)
	{
		if (button->IsPressed())
		{
			SceneManager::OpenScene("MainMenu");
		}
	}

	button = (Button*)SceneManager::GetCurrentScene()->FindObject("Exit2");
	if (button != NULL)
	{
		if (button->IsPressed())
		{
			SceneManager::OpenScene("MainMenu");
		}
	}

	if (Portal::NeedGo())
	{
		if (rand() % 100 < 50)
		{
			SceneManager::OpenScene("Overworld");
		}
		else
		{
			SceneManager::OpenScene("DungeonScene");
		}
	}
}