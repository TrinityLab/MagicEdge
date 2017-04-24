#pragma once

#include "SDL.h"

class Keyboard
{
private:
	static const Uint8* state;
	static const Uint8* prevState;
	static int keyCount;
public:
	static void Update();
	static bool IsKey(Uint8 key);
	static bool IsKeyDown(Uint8 key);
	static bool IsKeyUp(Uint8 key);
};