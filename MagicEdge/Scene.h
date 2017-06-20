#pragma once

#include "StandardInc.h"
#include "Object.h"

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
	Object* FindObjectWithTag(string tag);
	Object** FindObjectsWithTag(string tag, int* count);

	friend class SceneManager;
};