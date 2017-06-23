#include "StandardInc.h"
#include "MainMenu.h"
#include "Button.h"
#include "ScoreTable.h"
#include "ObjectFactory.h"
#include "Screen.h"
#include "SceneManager.h"
#include "Application.h"

MainMenu::MainMenu() : Scene()
{

}

void MainMenu::OnOpened()
{
	SDL_Delay(1000);

	Object* background = ObjectFactory::UI_SpawnBackground("MenuBackground");

	Object* startButton = ObjectFactory::UI_SpawnButton(
		Screen::GetWidth() / 2 - 220, 250 - 110 * 0.5f, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "Start game");

	Object* scoresButton = ObjectFactory::UI_SpawnButton(Screen::GetWidth() / 2 - 220, 250 + 110 + 50 - 55, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "Scores");

	Object* exitButton = ObjectFactory::UI_SpawnButton(Screen::GetWidth() / 2 - 220, 250 + 220 + 100 - 55, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "Exit");

	this->startButton = startButton->GetComponent<Button>();
	this->scoresButton = scoresButton->GetComponent<Button>();
	this->exitButton = exitButton->GetComponent<Button>();
}

void MainMenu::Update()
{
	Scene::Update();

	if (startButton->IsPressed())
	{
		/*if (rand() % 100 < 50)*/
			/*SceneManager::OpenScene("DesertScene");*/
		/*else*/
			SceneManager::OpenScene("Overworld");
	}

	if (scoresButton->IsPressed())
	{
		SceneManager::OpenScene("ScoreTable");
	}

	if (exitButton->IsPressed())
	{
		Application::Quit();
	}
}

void MainMenu::OnClosed()
{

}

string MainMenu::GetSceneName()
{
	return "MainMenu";
}
