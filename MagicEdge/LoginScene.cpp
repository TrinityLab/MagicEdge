#include "StandardInc.h"
#include "LoginScene.h"
#include "Button.h"
#include "ScoreTable.h"
#include "TextField.h"
#include "ObjectFactory.h"
#include "Screen.h"
#include "SceneManager.h"

LoginScene::LoginScene() : Scene()
{

}

void LoginScene::OnOpened()
{
	Object* background = ObjectFactory::UI_SpawnBackground("MenuBackground");

	okButton = ObjectFactory::UI_SpawnButton(Screen::GetWidth() / 2 - 220, Screen::GetHeight() * 0.6f - 55, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "OK");

	textField = ObjectFactory::UI_SpawnTextField(Screen::GetWidth() / 2 - 350, Screen::GetHeight() * 0.4f - 55, 700, 110,
		"TextField", "TextField", "TextField", "User name", 16);
}

void LoginScene::OnClosed()
{
	Scene::OnClosed();
}

void LoginScene::Update()
{
	Scene::Update();

	if (okButton->GetComponent<Button>()->IsPressed())
	{
		ScoreTable::userName = textField->GetComponent<TextField>()->GetText();

		SceneManager::OpenScene("MainMenu");
	}
}

string LoginScene::GetSceneName()
{
	return "LoginScene";
}