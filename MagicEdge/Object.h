#pragma once

#include "StandardInc.h"
#include "Utility.h"
#include "ObjectComponent.h"
#include "Transform.h"
#include "Renderer.h"
#include "Health.h"
#include "Mana.h"
#include "AutoDestroy.h"
#include "Shell.h"
#include "Enemy.h"
#include "Portal.h"

class Object
{
private:
	static list<Object*> objects;
	static list<Object*> objectsToCreate;

	static Object* FindObjectWithTag(string tag);
	static void AddObject(Object* object);
	static void DeleteFromList(Object* object);
	static void AddPreparedObjects();
	static bool ContainsObject(list<Object*>& l, Object* obj);

	vector<string> tags;
	list<Component*> components;

	bool destroy;

	void Render();
	void Update();
	void OnCreated();
	void OnDestroyd();

public:
	static void ClearObjects();
	static void Destroy(Object* obj);
	Object();
	~Object();

	bool HasTag(string tag);
	void AddTag(string tag);

	template<typename T>
	T* GetComponent();

	template<typename T>
	T* AddComponent();

	bool useCamera = true;

	friend class Scene;
};

template<typename T>
T* Object::GetComponent()
{
	for (auto iter = components.begin(); iter != components.end(); iter++)
	{
		if (typeid(T) == typeid(**iter))
			return (T*)*iter;
	}

	return nullptr;
}

template<typename T>
T* Object::AddComponent()
{
	T* c = new T(this);

	components.push_back(c);
	((Component*)c)->SetActive(true);

	return c;
}