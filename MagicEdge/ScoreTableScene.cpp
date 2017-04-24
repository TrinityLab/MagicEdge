#include "ScoreTableScene.h"
#include "Button.h"
#include "Screen.h"
#include "ResourceManager.h"
#include "SceneManager.h"

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
	TexturedObject* background = new TexturedObject("Background");
	background->SetOrigin(0, 0);
	background->SetPosition(0, 0);
	background->SetSize(Screen::GetWidth(), Screen::GetHeight());
	background->SetTexture(ResourceManager::GetTexture("MenuBackground"));
	background->SetSrcRect({ 0, 0, 1280, 720 });

	Button* exitButton = new Button("MainMenuButton", "Button", "ButtonHover", "ButtonPressed");
	exitButton->SetText("Back");
	exitButton->SetPosition(Screen::GetWidth() / 2, 250 + 220 + 100);
	exitButton->SetSize(440, 110);
	exitButton->SetSrcRect({ 0, 0, 440, 110 });

	vector<Result> results = ScoreTable::LoadScores();
	
	Button* head = new Button("Header", "TableHead", "TableHead", "TableHead");
	head->SetText("Name     Score");
	head->SetPosition(Screen::GetWidth() / 2, 150 - 60);
	head->SetSize(600, 60);
	head->SetSrcRect({ 0, 0, 609, 63 });

	int count = 0;
	while (count < 5 && results.size() > 0)
	{
		int i = FindMaxResult(results);

		char name[100] = {};
		sprintf_s(name, 100, "%s%d", "Row", count);
		char res[100] = {};
		sprintf_s(res, 100, "%s     %d", results[i].name.c_str(), results[i].score);
		Button* row = new Button(name, "TableRow", "TableRow", "TableRow");
		row->SetText(res);
		row->SetPosition(Screen::GetWidth() / 2, 150 + 60 * count );
		row->SetSize(600, 60);
		row->SetSrcRect({ 0, 0, 609, 63 });

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

	Button* exitButton = (Button*)SceneManager::GetCurrentScene()->FindObject("MainMenuButton");
	if (exitButton->IsPressed())
	{
		SceneManager::OpenScene("MainMenu");
	}
}