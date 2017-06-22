#include "StandardInc.h"
#include "Object.h"
#include "Camera.h"

list<Object*> Object::objects;
list<Object*> Object::objectsToCreate;

Object::Object()
{
	AddComponent<Transform>();

	objectsToCreate.push_back(this);

	destroy = false;
}

Object::~Object()
{
	DeleteFromList(this);
}

void Object::AddTag(string tag)
{
	tags.push_back(tag);
}

bool Object::HasTag(string tag)
{
	if (tags.size() == 0)
		return false;

	for (string& t : tags)
	{
		if (t == tag)
			return true;
	}

	return false;
}

void Object::Destroy(Object* obj)
{
	obj->destroy = true;
}

Object* Object::FindObjectWithTag(string tag)
{
	for (auto obj = objects.begin(); obj != objects.end(); obj++)
	{
		if ((*obj)->HasTag(tag))
			return *obj;
	}

	return NULL;
}

void Object::AddObject(Object* object)
{
	objects.push_back(object);
	object->OnCreated();
}

void Object::DeleteFromList(Object* object)
{
	for (auto obj = objects.begin(); obj != objects.end();)
	{
		if (*obj == object)
		{
			auto iter = obj;
			obj++;
			objects.erase(iter);
			break;
		}
		else
		{
			obj++;
		}
	}
}

void Object::ClearObjects()
{
	if (objects.size() <= 0)
		return;

	Object** temp = new Object*[objects.size()];

	int i = 0;
	for (auto iter = objects.begin(); iter != objects.end(); iter++)
	{
		temp[i] = *iter;
		i++;
	}

	for (i = 0; i < objects.size(); i++)
	{
		temp[i]->OnDestroyd();
		delete temp[i];
	}

	delete[] temp;

	objects.clear();
}

void Object::AddPreparedObjects()
{
	for (Object* obj : objectsToCreate)
	{
		AddObject(obj);
	}

	objectsToCreate.clear();
}

bool Object::ContainsObject(list<Object*>& l, Object* obj)
{
	for (auto iter = l.begin(); iter != l.end(); iter++)
	{
		if (*iter == obj)
			return true;
	}

	return false;
}

void Object::Render()
{
	for (Component* c : components)
	{
		if (c->IsActive())
			c->Render();
	}
}

void Object::Update()
{
	for (Component* c : components)
	{
		if (c->IsActive())
			c->Update();
	}
}

void Object::OnCreated()
{
	for (Component* c : components)
	{
		if (c->IsActive())
			c->OnCreated();
	}
}

void Object::OnDestroyd()
{
	for (Component* c : components)
	{
		if (c->IsActive())
			c->OnDestroyd();
	}

	for (Component* c : components)
	{
		delete c;
	}
}