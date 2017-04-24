#include "Player.h"
#include "DifficultyInfo.h"
#include "Ball.h"
#include "ScoreTable.h"
#include "Button.h"

Player::Player(string name) : Entity(name)
{
	
}

void Player::OnCreated()
{
	Entity::OnCreated();
	SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0);

	setSpeed(200);

	SetSize(Block::TILE_SIZE, Block::TILE_SIZE);
	SetPosition(World::WIDTH / 2 * Block::TILE_SIZE, World::HEIGHT / 2 * Block::TILE_SIZE);

	name = new Text("PlayerName", "Visitor");
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
	ScoreTable::SetScore(0);
}

void Player::OnDestroyd()
{
	Entity::OnDestroyd();
}

void Player::Update()
{
	Entity::Update();

	movement = false;

	if (Keyboard::IsKey(SDL_SCANCODE_A))
	{
		Move(Timer::GetDeltaTime()*(-getSpeed()), 0);
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_D))
	{
		Move(Timer::GetDeltaTime()*(getSpeed()), 0);
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_W))
	{
		Move(0, Timer::GetDeltaTime()*(-getSpeed()));
		movement = true;
	}

	if (Keyboard::IsKey(SDL_SCANCODE_S))
	{
		Move(0, Timer::GetDeltaTime()*(getSpeed()));
		movement = true;
	}

	if(Mouse::IsMouseDown(SDL_BUTTON_LEFT))
	{
		double x = Mouse::GetMouseX() + Camera::GetXOffset();
		double y = Mouse::GetMouseY() + Camera::GetYOffset();

		double dirX = x - GetXPosition();
		double dirY = y - GetYPosition();

		double dist = sqrt(dirX * dirX + dirY * dirY);

		if (getMana() > 0)
		{
			Ball* ball = new Ball("Ball", this);
			ball->SetPosition(GetXPosition() + (dirX / dist) * Block::TILE_SIZE / 2, GetYPosition() + (dirY / dist) * Block::TILE_SIZE / 2);
			ball->setV(dirX / dist * 400.0, dirY / dist * 400.0);
			ball->setDamage(getDamage());
			ball->SetColor({ 255, 255, 255, 255 });

			setMana(getMana() - 1);
		}
	}
}

void Player::SetPosition(double x, double y)
{
	Entity::SetPosition(x, y);

	Camera::SetOffset(GetXPosition() - Screen::GetWidth() / 2, GetYPosition() - Screen::GetHeight() / 2);
}

void Player::Render()
{
	FRect shadowRect = GetLocalBoundingBox();
	shadowRect.x += GetXPosition() - Camera::GetXOffset();
	shadowRect.y += GetYPosition() + Block::TILE_SIZE / 2 - Camera::GetYOffset();

	SDL_Rect rect = { (int)shadowRect.x, (int)shadowRect.y, (int)shadowRect.w, (int)shadowRect.h };

	int width, height;
	SDL_QueryTexture(ResourceManager::GetTexture("Shadow"), NULL, NULL, &width, &height);

	SDL_Rect srcRect = { 0, 0, width, height };

	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Shadow"), &srcRect, &rect);

	double offset = movement ? (5 * sin(Timer::GetTotalTime() * 10)) : 0;

	yPosition += offset;

	Entity::Render();

	SDL_Rect target1= { 20, 10, 200, 20 };
	SDL_Rect target2 = { 20, 10, 2 * 100 * getHealth() / GetMaxHealth(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleHealth"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	target1 = { 20, 50, 200, 20 };
	target2 = { 20, 50, 2*100*getMana()/GetMaxMana(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleMana"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	SDL_SetTextureColorMod(ResourceManager::GetTexture("ScaleEXP"), 128, 0, 0);
	target1 = { 20, 90, 200, 20 };
	target2 = { 20, 90, 2 *  getExp() / getLevel(), 20 };
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("ScaleEXP"), NULL, &target2);
	SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Scale"), NULL, &target1);

	yPosition -= offset;
}

void Player::Move(double x, double y)
{
	Entity::Move(x, y);

	Camera::SetOffset(GetXPosition() - Screen::GetWidth() / 2, GetYPosition() - Screen::GetHeight() / 2);

	if (x < 0)
	{
		SetTexture(ResourceManager::GetTexture("CharacterLeft"), 1, 1, 0, false);
	}
	else if (x > 0)
	{
		SetTexture(ResourceManager::GetTexture("CharacterRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		SetTexture(ResourceManager::GetTexture("CharacterBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	}
}

void Player::setLevel(int l)
{
	Entity::setLevel(l);

	difficulty = l;
	setSpeed(200);

	char lvl[100] = {};
	_itoa_s(getLevel(), lvl, 100, 10);
	string temp = "Level: ";
	level->SetFontSize(30);
	level->SetText(lvl);
}

void Player::setHealth(int health)
{
	Entity::setHealth(health);

	if (health <= 0)
	{
		TexturedObject* background = new TexturedObject("BlueBack");
		background->SetPosition(0, 0);
		Camera::SetOffset(0, 0);
		background->SetSize(Screen::GetWidth(), Screen::GetHeight());
		background->SetTexture(ResourceManager::GetTexture("BlueBack"));
		background->SetSrcRect({ 0, 0, 1280, 720 });
		background->SetOrigin(0, 0);
		
		Button* button = new Button("Exit2", "Button", "ButtonHover", "ButtonPressed");
		button->SetText("To main menu");
		button->SetPosition(Screen::GetWidth() / 2, Screen::GetHeight() / 2 - 40);
		button->SetSize(440, 110);
		button->SetSrcRect({ 0, 0, 440, 110 });
	}
}