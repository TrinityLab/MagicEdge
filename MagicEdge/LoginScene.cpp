#include "LoginScene.h"
#include "Button.h"
#include "ScoreTable.h"
#include "TextField.h"

LoginScene::LoginScene() : Scene()
{

}

void LoginScene::OnOpened()
{
	TexturedObject* background = new TexturedObject();
	background->AddTag("Background");
	background->SetOrigin(0, 0);
	background->SetPosition(0, 0);
	background->SetSize(Screen::GetWidth(), Screen::GetHeight());
	background->SetTexture(ResourceManager::GetTexture("MenuBackground"));

	Button* okButton = new Button("LoginOkButton", "Button", "ButtonHover", "ButtonPressed");
	okButton->SetPosition(Screen::GetWidth() / 2, Screen::GetHeight() * 0.6f);
	okButton->SetSize(440, 110);
	okButton->SetText("OK");

	TextField* field = new TextField("UsernameField", "TextField", "TextField", "TextField");
	field->SetPosition(Screen::GetWidth() / 2, Screen::GetHeight() * 0.4f);
	field->SetSize(700, 110);
	field->SetMaxLen(16);
	field->SetDefaultText("User name");
}

void LoginScene::OnClosed()
{
	Scene::OnClosed();
}

void LoginScene::Update()
{
	Scene::Update();

	Button* loginOkButton = (Button*)SceneManager::GetCurrentScene()->FindObjectWithTag("LoginOkButton");
	if (loginOkButton->IsPressed())
	{
		TextField* field = (TextField*)SceneManager::GetCurrentScene()->FindObjectWithTag("UsernameField");
		ScoreTable::userName = field->GetText();

		SceneManager::OpenScene("MainMenu");
	}
}

string LoginScene::GetSceneName()
{
	return "LoginScene";
}