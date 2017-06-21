#include "StandardInc.h"
#include "ObjectFactory.h"
#include "Block.h"
#include "Entity.h"
#include "TextField.h"
#include "InsectEnemy.h"
#include "OrkEnemy.h"
#include "BossEnemy.h"
#include "Overworld.h"
#include "Desert.h"
#include "Dungeon.h"
#include "BossLocation.h"
#include "Player.h"
#include "Screen.h"
#include "ResourceManager.h"

Object* ObjectFactory::SpawnObject(float x, float y)
{
	Object* obj = new Object();
	Transform* t = obj->GetComponent<Transform>();
	t->SetPosition(x, y);
	t->SetSize(0, 0);
	t->SetOrigin(0.5f, 0.5f);

	return obj;
}

Object* ObjectFactory::SpawnObject(float x, float y, float w, float h, float ox, float oy)
{
	Object* obj = new Object();
	Transform* t = obj->GetComponent<Transform>();
	t->SetPosition(x, y);
	t->SetSize(w, h);
	t->SetOrigin(ox, oy);

	return obj;
}

Object* ObjectFactory::SpawnBlood(float x, float y)
{
	Object* obj = SpawnObject(x, y, Block::TILE_SIZE * 1.5f, Block::TILE_SIZE * 1.5f);
	Renderer* r = obj->AddComponent<Renderer>();
	r->SetTexture(ResourceManager::GetTexture("Blood"), 4, 1, 8, false);
	obj->AddTag("Blood");
	AutoDestroy* ad = obj->AddComponent<AutoDestroy>();
	ad->SetTime(0.5f);

	return obj;
}

Object* ObjectFactory::SpawnDefaultShell(Object* creator, float x, float y, float vx, float vy, float damage, SDL_Color color)
{
	Object* shell = SpawnObject(x, y);
	shell->AddComponent<Renderer>();
	Shell* s = shell->AddComponent<Shell>();

	s->SetVelocity(vx, vy);
	s->SetDamage(damage);
	s->SetCreator(creator);
	s->SetColor(color);

	return shell;
}

Object* ObjectFactory::SpawnInsectEnemy(float x, float y)
{
	Object* enemy = SpawnObject(x, y);
	enemy->AddComponent<InsectEnemy>();

	return enemy;
}

Object* ObjectFactory::SpawnOrkEnemy(float x, float y)
{
	Object* enemy = SpawnObject(x, y);
	enemy->AddComponent<OrkEnemy>();

	return enemy;
}

Object* ObjectFactory::SpawnBossEnemy(float x, float y)
{
	Object* enemy = SpawnObject(x, y);
	enemy->AddComponent<BossEnemy>();

	return enemy;
}

Object* ObjectFactory::SpawnPlayer(float x, float y)
{
	Object* player = SpawnObject(x, y);
	player->AddComponent<Player>();

	return player;
}

Object* ObjectFactory::UI_SpawnText(float x, float y, float size, string str, string fontName)
{
	Object* text = SpawnObject(x, y);
	text->AddComponent<Renderer>();
	Text* t = text->AddComponent<Text>();
	t->SetFont(fontName);
	t->SetFontSize((int)size);
	t->SetText(str);

	return text;
}

Object* ObjectFactory::UI_SpawnButton(
	float left, float top, float width, float height,
	string normal, string hover, string pressed, string text)
{
	Object* button = SpawnObject(left, top, width, height, 0.0f, 0.0f);
	Button* b = button->AddComponent<Button>();

	b->SetText(text);
	b->SetNormalTex(normal);
	b->SetHoverTex(hover);
	b->SetPressedTex(pressed);

	return button;
}

Object* ObjectFactory::UI_SpawnTextField(
	float left, float top, float width, float height,
	string normal, string hover, string pressed, string defaultText,
	int maxLen, bool isFocused /* = false */)
{
	Object* field = SpawnObject(left, top, width, height, 0.0f, 0.0f);
	field->AddComponent<Renderer>();
	TextField* t = field->AddComponent<TextField>();

	t->SetNormalTex(normal);
	t->SetHoverTex(hover);
	t->SetPressedTex(pressed);
	t->SetDefaultText(defaultText);
	t->SetMaxLen(maxLen);
	t->SetFocused(isFocused);

	return field;
}

Object* ObjectFactory::CreateOverworld()
{
	Object* world = SpawnObject(0, 0);
	world->AddComponent<Overworld>();

	return world;
}

Object* ObjectFactory::CreateDesert()
{
	Object* world = SpawnObject(0, 0);
	world->AddComponent<Desert>();

	return world;
}

Object* ObjectFactory::CreateDungeon()
{
	Object* world = SpawnObject(0, 0);
	world->AddComponent<Dungeon>();

	return world;
}

Object* ObjectFactory::CreateBossLocation()
{
	Object* world = SpawnObject(0, 0);
	world->AddComponent<BossLocation>();

	return world;
}

Object* ObjectFactory::UI_SpawnPanel(float left, float top, float width, float height, string textureName)
{
	Object* panel = SpawnObject(left, top, width, height, 0.0f, 0.0f);
	panel->AddComponent<Renderer>()->SetTexture(ResourceManager::GetTexture(textureName));
	panel->useCamera = false;

	return panel;
}

Object* ObjectFactory::UI_SpawnBackground(string textureName)
{
	return UI_SpawnPanel(0, 0, Screen::GetWidth(), Screen::GetHeight(), textureName);
}

Object* ObjectFactory::SpawnPortal(float x, float y)
{
	Object* portal = SpawnObject(x, y, Block::TILE_SIZE, Block::TILE_SIZE);
	portal->AddComponent<Portal>();
	return portal;
}