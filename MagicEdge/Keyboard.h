#pragma once

#include "SDL.h"

class Keyboard
{
private:
	static const Uint8* state;
	static Uint8 textInput[512];
	static Uint8* prevState;
	static int keyCount;

	static bool IsKeyDown(Uint8 key);
	static bool IsKeyUp(Uint8 key);
public:
	static void Update();
	static bool IsKey(Uint8 key);
	static bool IsTextDown(Uint8 key);
	static int GetKeyCount();

	friend class Application;
};