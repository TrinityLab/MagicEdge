#pragma once

#include <string.h>
#include "SDL.h"
#include "Scene.h"
#include "Object.h"

using namespace std;

class Scene
{
protected:
	virtual void OnOpened();
	virtual void OnClosed();

	virtual void Render();
	virtual void Update();
public:
	Scene();
	virtual string GetSceneName() = 0;
	Object* FindObject(string name);
	Object** GetObjectsOfName(string name, int* count);

	friend class SceneManager;
};