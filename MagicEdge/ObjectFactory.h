#pragma once

#include "Object.h"

class ObjectFactory
{
public:
	static Object* SpawnObject(float x, float y);
	static Object* SpawnObject(float x, float y, float w, float h, float ox = 0.5f, float oy = 0.5f);
	static Object* SpawnBlood(float x, float y);
	static Object* SpawnDefaultShell(Object* creator, float x, float y, float vx, float vy, float damage, SDL_Color color);
	static Object* SpawnInsectEnemy(float x, float y);
	static Object* SpawnOrkEnemy(float x, float y);
	static Object* SpawnBossEnemy(float x, float y);
	static Object* SpawnPlayer(float x, float y);
	static Object* SpawnPortal(float x, float y);

	static Object* CreateOverworld();
	static Object* CreateDungeon();
	static Object* CreateDesert();
	static Object* CreateBossLocation();

	static Object* UI_SpawnButton(
		float left, float top, float width, float height,
		string normal, string hover, string pressed, string text);

	static Object* UI_SpawnText(float x, float y, float size, string text, string fontName);

	static Object* UI_SpawnTextField(
		float left, float top, float width, float height,
		string normal, string hover, string pressed, string defaultText, int maxLen, bool isFocused = false);

	static Object* UI_SpawnPanel(float left, float top, float width, float height, string textureName);
	static Object* UI_SpawnBackground(string textureName);
};