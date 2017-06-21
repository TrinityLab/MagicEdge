#include "StandardInc.h"
#include "SceneManager.h"

SceneManager* SceneManager::singleton = NULL;

SceneManager::SceneManager()
{
	if (singleton != NULL)
	{
		throw std::exception("Cannot create new scene manager");
	}

	singleton = this;

	currentScene = NULL;
}

SceneManager::~SceneManager()
{
	if (currentScene != NULL)
	{
		currentScene->OnClosed();
	}

	for (Scene* scene : scenes)
	{
		delete scene;
	}

	scenes.clear();

	singleton = NULL;
}

void SceneManager::OpenScene(string name)
{
	if (singleton->currentScene != NULL)
	{
		singleton->currentScene->OnClosed();
	}

	Scene* newScene = NULL;
	for (Scene* scene : singleton->scenes)
	{
		if (scene->GetSceneName() == name)
		{
			newScene = scene;
			break;
		}
	}

	if (newScene == NULL)
	{
		singleton->currentScene = NULL;

		throw std::exception(("Cannot fing scene with name " + name).c_str());
	}

	singleton->currentScene = newScene;
	singleton->currentScene->OnOpened();
}

void SceneManager::Update()
{
	if (singleton == NULL)
		return;

	if (singleton->currentScene == NULL)
		return;

	singleton->currentScene->Update();
}

void SceneManager::Render()
{
	if (singleton == NULL)
		return;

	if (singleton->currentScene == NULL)
		return;

	singleton->currentScene->Render();
}

bool SceneManager::AddScene(Scene* scene)
{
	for (Scene* s : scenes)
	{
		if (s->GetSceneName() == scene->GetSceneName())
			return false;
	}

	scenes.push_back(scene);

	return true;
}

Scene* SceneManager::GetCurrentScene()
{
	return singleton->currentScene;
}