#include "Application.h"
#include "SceneManager.h"
#include "Timer.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "ResourceManager.h"
#include "MasterManager.h"
#include "ScoreTable.h"
#include <Windowsx.h>
#include "UserNameDlgRes.h"

#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

bool Application::quit;

LRESULT DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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

	ResourceManager::LoadTexture("Grass", "Texture/Grass.png");
	ResourceManager::LoadTexture("Character", "Texture/character.png");
	ResourceManager::LoadTexture("CharacterBack", "Texture/characterback.png");
	ResourceManager::LoadTexture("CharacterLeft", "Texture/characterleft.png");
	ResourceManager::LoadTexture("CharacterRight", "Texture/characterright.png");
	ResourceManager::LoadTexture("Water", "Texture/water.png");
	ResourceManager::LoadTexture("Dirt", "Texture/earth.png");
	ResourceManager::LoadTexture("Sand", "Texture/sand.png");
	ResourceManager::LoadTexture("Stone", "Texture/stone.png");
	ResourceManager::LoadTexture("Trees", "Texture/barriertree1.png");
	ResourceManager::LoadTexture("Trees2", "Texture/barriertree2.png");
	ResourceManager::LoadTexture("Enemy", "Texture/enemy.png");
	ResourceManager::LoadTexture("EnemyBack", "Texture/enemyback.png");
	ResourceManager::LoadTexture("EnemyLeft", "Texture/enemyleft.png");
	ResourceManager::LoadTexture("EnemyRight", "Texture/enemyright.png");
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
	ResourceManager::LoadTexture("Enemy2", "Texture/enemy2.png");
	ResourceManager::LoadTexture("Enemy2Back", "Texture/enemy2back.png");
	ResourceManager::LoadTexture("Enemy2Left", "Texture/enemy2left.png");
	ResourceManager::LoadTexture("Enemy2Right", "Texture/enemy2right.png");
	ResourceManager::LoadTexture("Blood", "Texture/blood.png");
	ResourceManager::LoadTexture("Rock", "Texture/barrierstone.png");
	ResourceManager::LoadTexture("Tump", "Texture/barrierstump.png");
	ResourceManager::LoadTexture("Altar", "Texture/altar.png");
	ResourceManager::LoadTexture("BlueBack", "Texture/BlueBackground.png");
	ResourceManager::LoadTexture("TableHead", "Texture/tablehead.png");
	ResourceManager::LoadTexture("TableRow", "Texture/tablerow.png");
	ResourceManager::LoadTexture("Portal", "Texture/portal.png");
	ResourceManager::LoadMusic("Music", "Music/BackMusic.wav");
	ResourceManager::LoadFont("Visitor", "Fonts/visitor1.ttf", 24);

	new MasterManager();

	DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_USERNAME), NULL, DlgProc);

	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EventType::SDL_QUIT)
				return 0;
		}

		Keyboard::Update();
		Mouse::Update();

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

LRESULT DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			if (HIWORD(wParam) == BN_CLICKED)
			{
				EndDialog(hWnd, 0);
			}
		}
		if (LOWORD(wParam) == IDC_USERNAME)
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				char name[100] = {};
				Edit_GetText((HWND)lParam, name, 100);
				ScoreTable::userName = name;
			}
		}
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}