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
#include "SceneManager.h"

void Player::OnCreated()
{
	GetOwner()->GetComponent<Transform>()->SetSize(Block::TILE_SIZE, Block::TILE_SIZE);

	string temp = "Level: ";
	temp += std::to_string(GetLevel());
	Object* levelObj = ObjectFactory::UI_SpawnText(200, 160, 30, temp, "Visitor");
	levelText = levelObj->GetComponent<Text>();
	levelObj->GetComponent<Transform>()->SetOrigin(0.0f, 0.0f);

	Object* nameObj = ObjectFactory::UI_SpawnText(20, 120, 30, ScoreTable::userName, "Visitor");
	nameText = nameObj->GetComponent<Text>();
	nameObj->GetComponent<Transform>()->SetOrigin(0.0f, 0.0f);

	Object* scoreObj = ObjectFactory::UI_SpawnText(20, 160, 30, "Score: 0", "Visitor");
	scoreText = scoreObj->GetComponent<Text>();
	scoreObj->GetComponent<Transform>()->SetOrigin(0.0f, 0.0f);

	Entity::OnCreated();

	GetOwner()->AddTag("Player");

	Renderer* r;

	if ((r = GetOwner()->GetComponent<Renderer>()) == nullptr)
		r = GetOwner()->AddComponent<Renderer>();

	r->SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0);

	score = 0;
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

			mana->ManaDown(1);
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
	SDL_Rect target2 = { 20, 10, 200.0f * health->GetHealth() / health->GetMaxHealth(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleHealth"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	target1 = { 20, 50, 200, 20 };
	target2 = { 20, 50, (int)(200.0f*mana->GetMana()/mana->GetMaxMana()), 20 };
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

	if (levelText != nullptr)
	{
		string temp = "Level: ";
		temp += std::to_string(GetLevel());
		levelText->SetText(temp);
	}

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

	ScoreTable::SendScore(GetScore());

	ObjectFactory::UI_SpawnBackground("BlueBack");
	
	exitButton2 = ObjectFactory::UI_SpawnButton(
		Screen::GetWidth() / 2 - 220, Screen::GetHeight() / 2 - 40 - 55, 440, 110,
		"Button", "ButtonHover", "ButtonPressed", "To main menu");

	exitButton2->AddTag("Exit2");
}

void Player::OnKillEnemy(Object* enemy, int score, int exp)
{
	SetExp(GetExp() + exp);
	AddScore(score);
}

void Player::SetScore(int s)
{
	score = s;

	string temp = "Score: ";
	temp += std::to_string(score);
	scoreText->SetText(temp);
}

void Player::AddScore(int s)
{
	SetScore(score + s);
}

int Player::GetScore()
{
	return score;
}