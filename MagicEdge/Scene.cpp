#include "Scene.h"
#include "Screen.h"

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

Object* Scene::FindObject(string name)
{
	return Object::FindObject(name);
}

void Scene::OnOpened()
{
	
}

void Scene::OnClosed()
{
	Object::ClearObjects();
}

Object** Scene::GetObjectsOfName(string name, int* count)
{
	*count = 0;
	for (auto iter = Object::objects.begin(); iter != Object::objects.end(); iter++)
	{
		if ((*iter)->destroy)
			continue;

		Object* obj = *iter;
		if (obj->GetObjectName() == name)
			(*count)++;
	}

	Object** objs = new Object*[*count];
	int index = 0;
	for (auto iter = Object::objects.begin(); iter != Object::objects.end(); iter++)
	{
		if ((*iter)->destroy)
			continue;

		Object* obj = *iter;
		if (obj->GetObjectName() == name)
		{
			objs[index] = obj;
			index++;
		}
	}

	return objs;
}