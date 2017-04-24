#pragma once

#include "SDL.h"

class Screen
{
private:
	static int width;
	static int height;
	static SDL_Renderer* renderer;
public:
	static int GetWidth();
	static int GetHeight();
	static SDL_Renderer* GetRenderer();

	friend class Application;
};