#pragma once

class Mouse
{
private:
	static int x, y;
	static bool state[3];
	static bool prevState[3];
public:
	static void Update();
	static bool IsMousePressed(int key);
	static bool IsMouseDown(int key);
	static bool IsMouseUp(int key);
	static int GetMouseX();
	static int GetMouseY();
};