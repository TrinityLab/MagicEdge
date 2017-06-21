#include "StandardInc.h"
#include "Scene.h"
#include "Screen.h"
#include "TriggerChecker.h"

Scene::Scene()
{

}

void Scene::Update()
{
	Object::AddPreparedObjects();

	for (Object* obj : Object::objects)
	{
		if (!obj->destroy)
			obj->Update();
	}

	TriggerChecker::Update();
	MessageManager::Update();

	for (auto iter = Object::objects.begin(); iter != Object::objects.end();)
	{
		if ((*iter)->destroy)
		{
			auto iter2 = iter;
			iter++;
			(*iter2)->OnDestroyd();
			delete (*iter2);
		}
		else
		{
			iter++;
		}
	}
}

void Scene::Render()
{
	SDL_SetRenderDrawColor(Screen::GetRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(Screen::GetRenderer());

	for (Object* obj : Object::objects)
	{
		if(!obj->destroy)
			obj->Render();
	}

	SDL_RenderPresent(Screen::GetRenderer());
}

Object* Scene::FindObjectWithTag(string tag)
{
	return Object::FindObjectWithTag(tag);
}

void Scene::OnOpened()
{
	
}

void Scene::OnClosed()
{
	Object::ClearObjects();
}

Object** Scene::FindObjectsWithTag(string tag, int* count)
{
	*count = 0;
	for (auto iter = Object::objects.begin(); iter != Object::objects.end(); iter++)
	{
		if ((*iter)->destroy)
			continue;

		Object* obj = *iter;
		if (obj->HasTag(tag))
			(*count)++;
	}

	Object** objs = new Object*[*count];
	int index = 0;
	for (auto iter = Object::objects.begin(); iter != Object::objects.end(); iter++)
	{
		if ((*iter)->destroy)
			continue;

		Object* obj = *iter;
		if (obj->HasTag(tag))
		{
			objs[index] = obj;
			index++;
		}
	}

	return objs;
}