#include "StandardInc.h"
#include "Player.h"
#include "DifficultyInfo.h"
#include "ScoreTable.h"
#include "Button.h"
#include "Portal.h"
#include "Renderer.h"
#include "ObjectFactory.h"
#include "ResourceManager.h"
#include "Keyboard.h"
#include "Timer.h"
#include "Mouse.h"
#include "Camera.h"
#include "Screen.h"

void Player::OnCreated()
{
	GetOwner()->GetComponent<Transform>()->SetSize(Block::TILE_SIZE, Block::TILE_SIZE);

	Entity::OnCreated();

	GetOwner()->AddTag("Player");

	/*name = new Text("PlayerName", "Visitor");
	name->SetText(ScoreTable::userName.c_str());
	name->SetOrigin(0, 0);
	name->SetPosition(20, 120);
	name->SetFontSize(30);

	char lvl[100] = {};
	_itoa_s(getLevel(), lvl, 100, 10);
	string temp = "Level: ";
	temp += lvl;
	level = new Text("PlayerLevel", "Visitor", temp);
	level->SetPosition(200, 160);
	level->SetOrigin(0, 0);
	level->SetFontSize(30);

	score = new Text("PlayerScore", "Visitor", temp);
	score->SetPosition(20, 160);
	score->SetOrigin(0, 0);
	score->SetText("Score: 0");
	score->SetFontSize(30);
	ScoreTable::SetScore(0);*/

	Renderer* r;

	if ((r = GetOwner()->GetComponent<Renderer>()) == nullptr)
		r = GetOwner()->AddComponent<Renderer>();

	r->SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0);

	SetSpeed(200);
}

void Player::Update()
{
	Entity::Update();

	movement = false;

	if (Keyboard::IsKey(SDL_SCANCODE_A))
	{
		Move(Timer::GetDeltaTime()*(-GetSpeed()), 0);
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_D))
	{
		Move(Timer::GetDeltaTime()*(GetSpeed()), 0);
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_W))
	{
		Move(0, Timer::GetDeltaTime()*(-GetSpeed()));
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_S))
	{
		Move(0, Timer::GetDeltaTime()*(GetSpeed()));
		movement = true;
	}

	if (Mouse::IsMouseDown(SDL_BUTTON_LEFT))
	{
		double x = Mouse::GetMouseX() + Camera::GetXOffset();
		double y = Mouse::GetMouseY() + Camera::GetYOffset();

		Transform* t = GetOwner()->GetComponent<Transform>();

		double dirX = x - t->GetXPosition();
		double dirY = y - t->GetYPosition();

		double dist = sqrt(dirX * dirX + dirY * dirY);

		Mana* mana = GetOwner()->GetComponent<Mana>();

		if (mana->GetMana() > 0)
		{
			Transform* t = GetOwner()->GetComponent<Transform>();

			ObjectFactory::SpawnDefaultShell(GetOwner(),
				t->GetXPosition() + (dirX / dist) * Block::TILE_SIZE / 2,
				t->GetYPosition() + (dirY / dist) * Block::TILE_SIZE / 2,
				dirX / dist * 400.0, dirY / dist * 400.0,
				GetDamage(), { 255, 255, 255, 255 });

			mana->SetMana(mana->GetMana() - 1);
		}
	}
}

void Player::Render()
{
	Entity::Render();

	/*FRect shadowRect = GetLocalBoundingBox();
	shadowRect.x += GetXPosition() - Camera::GetXOffset();
	shadowRect.y += GetYPosition() + Block::TILE_SIZE / 2 - Camera::GetYOffset();

	SDL_Rect rect = { (int)shadowRect.x, (int)shadowRect.y, (int)shadowRect.w, (int)shadowRect.h };

	int width, height;
	SDL_QueryTexture(ResourceManager::GetTexture("Shadow"), NULL, NULL, &width, &height);

	SDL_Rect srcRect = { 0, 0, width, height };

	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Shadow"), &srcRect, &rect);

	double offset = movement ? (5 * sin(Timer::GetTotalTime() * 10)) : 0;

	yPosition += offset;*/

	Health* health = GetOwner()->GetComponent<Health>();
	Mana* mana = GetOwner()->GetComponent<Mana>();

	SDL_Rect target1= { 20, 10, 200, 20 };
	SDL_Rect target2 = { 20, 10, 2 * 100 * health->GetHealth() / health->GetMaxHealth(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleHealth"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	target1 = { 20, 50, 200, 20 };
	target2 = { 20, 50, (int)(2*100*mana->GetMana()/mana->GetMaxMana()), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleMana"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	SDL_SetTextureColorMod(ResourceManager::GetTexture("ScaleEXP"), 128, 0, 0);
	target1 = { 20, 90, 200, 20 };
	target2 = { 20, 90, 2 *  GetExp() / GetLevel(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleEXP"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	//yPosition -= offset;
}

void Player::Move(double x, double y)
{
	Entity::Move(x, y);

	Transform* t = GetOwner()->GetComponent<Transform>();

	Camera::SetOffset(t->GetXPosition() - Screen::GetWidth() / 2, t->GetYPosition() - Screen::GetHeight() / 2);

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	if (x < 0)
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterLeft"), 1, 1, 0, false);
	}
	else if (x > 0)
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		r->SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	}
}

void Player::SetLevel(int l)
{
	Entity::SetLevel(l);

	difficulty = l;
	SetSpeed(200);

	/*char lvl[100] = {};
	_itoa_s(GetLevel(), lvl, 100, 10);
	string temp = "Level: ";
	temp += lvl;
	level->SetText(temp);
	level->SetFontSize(30);*/

	if (l >= 1)
	{
		/*Portal* portal = (Portal*)SceneManager::GetCurrentScene()->FindObjectWithTag("Portal");
		if(portal != NULL)
			portal->SetTexture(ResourceManager::GetTexture("Portal"), 3, 1, 8, true);*/
	}
}

void Player::OnKilled()
{
	Entity::OnKilled();

	/*TexturedObject* background = new TexturedObject();
	background->AddTag("BlueBack");
	background->SetPosition(0, 0);
	Camera::SetOffset(0, 0);
	background->SetSize(Screen::GetWidth(), Screen::GetHeight());
	background->SetTexture(ResourceManager::GetTexture("BlueBack"));
	background->SetSrcRect({ 0, 0, 1280, 720 });
	background->SetOrigin(0, 0);*/

	//Button* button = new Button("Exit2", "Button", "ButtonHover", "ButtonPressed");
	//button->SetText("To main menu");
	//button->SetPosition(Screen::GetWidth() / 2, Screen::GetHeight() / 2 - 40);
	//button->SetSize(440, 110);
	//button->SetSrcRect({ 0, 0, 440, 110 });
}

void Player::OnKillEnemy(Object* enemy, int score, int exp)
{
	SetExp(GetExp() + exp);
	ScoreTable::AddScore(score);
}