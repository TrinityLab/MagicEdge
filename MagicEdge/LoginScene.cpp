#include "LoginScene.h"
#include "Button.h"
#include "ScoreTable.h"

LoginScene::LoginScene() : Scene()
{

}

void LoginScene::OnOpened()
{
	TexturedObject* background = new TexturedObject("Background");
	background->SetOrigin(0, 0);
	background->SetPosition(0, 0);
	background->SetSize(Screen::GetWidth(), Screen::GetHeight());
	background->SetTexture(ResourceManager::GetTexture("Background"));

	Button* okButton = new Button("LoginOkButton", "Button", "ButtonHover", "ButtonPressed");
	okButton->SetPosition(Screen::GetWidth() / 2, Screen::GetHeight() * 0.6f);
	okButton->SetSize(440, 110);
	okButton->SetText("OK");
}

void LoginScene::OnClosed()
{

}

void LoginScene::Update()
{

}