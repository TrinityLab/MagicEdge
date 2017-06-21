#include "StandardInc.h"
#include "ScoreTableScene.h"
#include "Button.h"
#include "Screen.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "ObjectFactory.h"

ScoreTableScene::ScoreTableScene() : Scene()
{

}

string ScoreTableScene::GetSceneName()
{
	return "ScoreTable";
}

int FindMaxResult(vector<Result> results)
{
	int index = 0, max = 0;

	for (int i = 0; i < results.size(); i++)
	{
		if (max < results[i].score)
		{
			max = results[i].score;
			index = i;
		}
	}

	return index;
}

void ScoreTableScene::OnOpened()
{
	ObjectFactory::UI_SpawnBackground("MenuBackground");

	exitButton = ObjectFactory::UI_SpawnButton(
		Screen::GetWidth() / 2 - 220, 250 + 220 + 100 - 55, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "Back");

	vector<Result> results = ScoreTable::LoadScores();
	
	ObjectFactory::UI_SpawnButton(
		Screen::GetWidth() / 2 - 300, 30, 600, 60,
		"TableHead", "TableHead", "TableHead", "Name     Score");

	int count = 0;
	while (count < 5 && results.size() > 0)
	{
		int i = FindMaxResult(results);

		char name[100] = {};
		sprintf_s(name, 100, "%s%d", "Row", count);
		char res[100] = {};
		sprintf_s(res, 100, "%s     %d", results[i].name.c_str(), results[i].score);

		ObjectFactory::UI_SpawnButton(
			Screen::GetWidth() / 2 - 300, 150 + 60 * count, 600, 60,
			"TableRow", "TableRow", "TableRow", res);

		int i2 = 0;
		for (auto iter = results.begin(); iter != results.end(); iter++)
		{
			if (i2 == i)
			{
				results.erase(iter);
				break;
			}
			i2++;
		}

		count++;
	}
}

void ScoreTableScene::Update()
{
	Scene::Update();

	if (exitButton->GetComponent<Button>()->IsPressed())
	{
		SceneManager::OpenScene("MainMenu");
	}
}