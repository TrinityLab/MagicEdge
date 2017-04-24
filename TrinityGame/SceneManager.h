#pragma once

#include <list>
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* singleton;
	list<Scene*> scenes;
	Scene* currentScene;

	static void Update();
	static void Render();
protected:
	bool AddScene(Scene* scene);
public:
	SceneManager();
	~SceneManager();
	static void OpenScene(string sceneName);
	static Scene* GetCurrentScene();

	friend class Application;
};