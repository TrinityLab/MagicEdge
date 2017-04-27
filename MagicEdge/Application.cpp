#include "Application.h"
#include "SceneManager.h"
#include "Timer.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "ResourceManager.h"
#include "MasterManager.h"

bool Application::quit;

Application::Application()
{
	window = NULL;
	renderer = NULL;
}

Application::~Application()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

int Application::Run(char* title, UINT x, UINT y, UINT width, UINT height, SDL_WindowFlags flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow(title, x, y, width, height, flags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(renderer, width, height);

	Screen::width = width;
	Screen::height = height;
	Screen::renderer = renderer;

	this->LoadResources();
	this->LoadSceneManager();

	while (!quit)
	{
		Keyboard::Update();
		Mouse::Update();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EventType::SDL_QUIT)
				return 0;
			if(event.type == SDL_EventType::SDL_KEYDOWN)
			{
				Keyboard::textInput[event.key.keysym.scancode] = 1;
			}
		}

		Update();
		Render();
	}

	ResourceManager::Clear();

	SDL_Quit();
}

void Application::Update()
{
	Timer::Update();

	SceneManager::Update();
}

void Application::Render()
{
	SceneManager::Render();
}


void Application::Quit()
{
	quit = true;
}

void Application::LoadResources()
{
	ResourceManager::LoadTexture("Grass", "Texture/Grass.png");
	ResourceManager::LoadTexture("Character", "Texture/character.png");
	ResourceManager::LoadTexture("CharacterBack", "Texture/characterback.png");
	ResourceManager::LoadTexture("CharacterLeft", "Texture/characterleft.png");
	ResourceManager::LoadTexture("CharacterRight", "Texture/characterright.png");
	ResourceManager::LoadTexture("Water", "Texture/water.png");
	ResourceManager::LoadTexture("Dirt", "Texture/earth.png");
	ResourceManager::LoadTexture("Sand", "Texture/sand.png");
	ResourceManager::LoadTexture("Stone", "Texture/stone.png");
	ResourceManager::LoadTexture("Tree", "Texture/barriertree1.png");
	ResourceManager::LoadTexture("Trees2", "Texture/barriertree2.png");
	ResourceManager::LoadTexture("InsectEnemy", "Texture/enemy.png");
	ResourceManager::LoadTexture("InsectEnemyBack", "Texture/enemyback.png");
	ResourceManager::LoadTexture("InsectEnemyLeft", "Texture/enemyleft.png");
	ResourceManager::LoadTexture("InsectEnemyRight", "Texture/enemyright.png");
	ResourceManager::LoadTexture("MagicBall", "Texture/magic.png");
	ResourceManager::LoadTexture("Shadow", "Texture/Shadow.png");
	ResourceManager::LoadTexture("Scale", "Texture/scale.png");
	ResourceManager::LoadTexture("ScaleMana", "Texture/scalemanna.png");
	ResourceManager::LoadTexture("ScaleHealth", "Texture/scalehealth.png");
	ResourceManager::LoadTexture("ScaleEXP", "Texture/scaleEXP.png");
	ResourceManager::LoadTexture("MenuBackground", "Texture/background.png");
	ResourceManager::LoadTexture("Button", "Texture/button.png");
	ResourceManager::LoadTexture("ButtonHover", "Texture/buttonhover.png");
	ResourceManager::LoadTexture("ButtonPressed", "Texture/buttonpressed.png");
	ResourceManager::LoadTexture("OrkEnemy", "Texture/enemy2.png");
	ResourceManager::LoadTexture("OrkEnemyBack", "Texture/enemy2back.png");
	ResourceManager::LoadTexture("OrkEnemyLeft", "Texture/enemy2left.png");
	ResourceManager::LoadTexture("OrkEnemyRight", "Texture/enemy2right.png");
	ResourceManager::LoadTexture("Blood", "Texture/blood.png");
	ResourceManager::LoadTexture("Rock", "Texture/barrierstone.png");
	ResourceManager::LoadTexture("Tump", "Texture/barrierstump.png");
	ResourceManager::LoadTexture("Altar", "Texture/altar.png");
	ResourceManager::LoadTexture("BlueBack", "Texture/BlueBackground.png");
	ResourceManager::LoadTexture("TableHead", "Texture/tablehead.png");
	ResourceManager::LoadTexture("TableRow", "Texture/tablerow.png");
	ResourceManager::LoadTexture("Portal", "Texture/portal.png");
	ResourceManager::LoadTexture("TextField", "Texture/TestTextField.png");
	ResourceManager::LoadMusic("Music", "Music/BackMusic.wav");
	ResourceManager::LoadFont("Visitor", "Fonts/visitor1.ttf", 24);
}

void Application::LoadSceneManager()
{
	new MasterManager();
}