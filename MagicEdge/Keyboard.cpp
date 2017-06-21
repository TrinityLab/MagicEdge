#include "StandardInc.h"
#include "Keyboard.h"

const Uint8* Keyboard::state = NULL;
Uint8 Keyboard::textInput[512] = {};
Uint8* Keyboard::prevState = NULL;
int Keyboard::keyCount = 0;

void Keyboard::Update()
{
	for (Uint8& n : textInput)
	{
		n = 0;
	}
	
	if (prevState != NULL)
		delete[] prevState;

	if (GetKeyCount() > 0)
	{
		prevState = new Uint8[GetKeyCount()];

		for (int i = 0; i < GetKeyCount(); i++)
		{
			prevState[i] = state[i];
		}
	}

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
	if (key < 0 || key >= keyCount || prevState == NULL)
		return false;

	return !prevState[key] && state[key];
}

bool Keyboard::IsTextDown(Uint8 key)
{
	if (key < 0 || key >= keyCount)
		return false;
	
	return textInput[key];
}

bool Keyboard::IsKeyUp(Uint8 key)
{
	if (key < 0 || key >= keyCount || prevState == NULL)
		return false;

	return prevState[key] && !state[key];
}

int Keyboard::GetKeyCount()
{
	return keyCount;
}