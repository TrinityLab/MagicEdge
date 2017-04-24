#include "Keyboard.h"

const Uint8* Keyboard::state = NULL;
const Uint8* Keyboard::prevState = NULL;
int Keyboard::keyCount = 0;

void Keyboard::Update()
{
	prevState = state;

	state = SDL_GetKeyboardState(&keyCount);
}

bool Keyboard::IsKey(Uint8 key)
{
	if (key < 0 || key >= keyCount)
		return false;

	return (bool)state[key];
}

bool Keyboard::IsKeyDown(Uint8 key)
{
	if (key < 0 || key >= keyCount)
		return false;

	return !prevState[key] && state[key];
}

bool Keyboard::IsKeyUp(Uint8 key)
{
	if (key < 0 || key >= keyCount)
		return false;

	return prevState[key] && !state[key];
}