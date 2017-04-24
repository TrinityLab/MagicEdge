#include "Screen.h"

int Screen::width;
int Screen::height;
SDL_Renderer* Screen::renderer;

int Screen::GetWidth()
{
	return width;
}

int Screen::GetHeight()
{
	return height;
}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}