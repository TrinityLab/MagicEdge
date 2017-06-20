#include "MainMenu.h"
#include "TexturedObject.h"
#include "Button.h"
#include "ScoreTable.h"
#include <Windowsx.h>

MainMenu::MainMenu() : Scene()
{

}

void MainMenu::OnOpened()
{
	SDL_Delay(1000);

	ScoreTable::AddScore(0);

	TexturedObject* background = new TexturedObject();
	background->AddTag("Background");
	background->SetOrigin(0, 0);
	background->SetPosition(0, 0);
	background->SetSize(Screen::GetWidth(), Screen::GetHeight());
	background->SetTexture(ResourceManager::GetTexture("MenuBackground"));
	background->SetSrcRect({ 0, 0, 1280, 720 });

	Button* startButton = new Button("StartButton", "Button", "ButtonHover", "ButtonPressed");
	startButton->SetText("Start game");
	startButton->SetPosition(Screen::GetWidth() / 2, 250);
	startButton->SetSize(440, 110);
	startButton->SetSrcRect({ 0, 0, 440, 110 });

	Button* scoresButton = new Button("ScoresButton", "Button", "ButtonHover", "ButtonPressed");
	scoresButton->SetText("Scores");
	scoresButton->SetPosition(Screen::GetWidth() / 2, 250 + 110 + 50);
	scoresButton->SetSize(440, 110);
	scoresButton->SetSrcRect({ 0, 0, 440, 110 });

	Button* exitButton = new Button("ExitButton", "Button", "ButtonHover", "ButtonPressed");
	exitButton->SetText("Exit");
	exitButton->SetPosition(Screen::GetWidth() / 2, 250 + 220 + 100);
	exitButton->SetSize(440, 110);
	exitButton->SetSrcRect({ 0, 0, 440, 110 });
}

void MainMenu::Update()
{
	Scene::Update();

	Button* startButton = (Button*)SceneManager::GetCurrentScene()->FindObjectWithTag("StartButton");
	if (startButton->IsPressed())
	{
		/*if (rand() % 100 < 50)*/
			/*SceneManager::OpenScene("DesertScene");*/
		/*else*/
			SceneManager::OpenScene("Overworld");
	}

	Button* scoresButton = (Button*)SceneManager::GetCurrentScene()->FindObjectWithTag("ScoresButton");
	if (scoresButton->IsPressed())
	{
		SceneManager::OpenScene("ScoreTable");
	}

	Button* exitButton = (Button*)SceneManager::GetCurrentScene()->FindObjectWithTag("ExitButton");
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
