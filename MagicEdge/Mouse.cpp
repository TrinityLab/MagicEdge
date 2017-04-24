#include "Mouse.h"
#include <Windows.h>
#include "SDL.h"

int Mouse::x = 0;
int Mouse::y = 0;
bool Mouse::state[3] = {};
bool Mouse::prevState[3] = {};

void Mouse::Update()
{
	for (int i = 0; i < _countof(state); i++)
	{
		prevState[i] = state[i];
	}

	Uint32 data = SDL_GetMouseState(&x, &y);

	state[0] = (bool)(data & SDL_BUTTON(SDL_BUTTON_LEFT));
	state[1] = (bool)(data & SDL_BUTTON(SDL_BUTTON_MIDDLE));
	state[2] = (bool)(data & SDL_BUTTON(SDL_BUTTON_RIGHT));
}

bool Mouse::IsMousePressed(int key)
{
	if (key < 1 || key > 3)
		return false;

	return state[key - 1];
}

bool Mouse::IsMouseDown(int key)
{
	if (key < 1 || key > 3)
		return false;

	return !prevState[key - 1] && state[key - 1];
}

bool Mouse::IsMouseUp(int key)
{
	if (key < 1 || key > 3)
		return false;

	return prevState[key - 1] && !state[key - 1];
}

int Mouse::GetMouseX()
{
	return x;
}

int Mouse::GetMouseY()
{
	return y;
}