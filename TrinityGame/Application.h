#pragma once

#include "SDL.h"
#include <Windows.h>

class Application
{
private:
	static bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer;
	void Render();
	void Update();
public:
	Application();
	~Application();
	int Run(char* title, UINT x, UINT y, UINT width, UINT height, SDL_WindowFlags flags);
	static void Quit();
};