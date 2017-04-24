#include "Object.h"
#include "Camera.h"
#include <Windows.h>

list<Object*> Object::objects;
list<Object*> Object::objectsToCreate;

Object::Object(string name)
{
	this->name = name;

	xPosition = yPosition = 0.0;
	xSize = ySize = 0.0;
	xScale = yScale = 1.0;
	angle = 0.0;
	xOrigin = yOrigin = 0.5;

	objectsToCreate.push_back(this);

	active = true;
}

Object::~Object()
{
	DeleteFromList(this);
}

string Object::GetObjectName()
{
	return name;
}

void Object::Destroy(Object* obj)
{
	obj->active = false;
}

Object* Object::FindObject(string name)
{
	for (auto obj = objects.begin(); obj != objects.end(); obj++)
	{
		if ((*obj)->GetObjectName() == name)
			return *obj;
	}

	return NULL;
}

void Object::AddObject(Object* object)
{
	objects.push_back(object);
	object->OnCreated();
}

void Object::DeleteObject(Object* object)
{
	delete object;
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
		delete temp[i];
	}

	delete[] temp;

	objects.clear();
}

void Object::SetPosition(double x, double y)
{
	xPosition = x;
	yPosition = y;
}

void Object::SetSize(double x, double y)
{
	xSize = x;
	ySize = y;
}

void Object::SetScale(double x, double y)
{
	xScale = x;
	yScale = y;
}

void Object::SetRotation(double angle)
{
	this->angle = angle;
}

void Object::ResetScale()
{
	xScale = yScale = 1.0;
}

double Object::GetXPosition()
{
	return xPosition;
}

double Object::GetYPosition()
{
	return yPosition;
}

double Object::GetXSize()
{
	return xSize * xScale;
}

double Object::GetYSize()
{
	return ySize * yScale;
}

double Object::GetRotation()
{
	return angle;
}

void Object::Move(double deltaX, double deltaY)
{
	SetPosition(xPosition + deltaX, yPosition + deltaY);
}

void Object::Scale(double x, double y)
{
	SetScale(xScale * x, yScale * y);
}

void Object::Rotate(double delta)
{
	SetRotation(angle + delta);
}

void Object::SetOrigin(double x, double y)
{
	xOrigin = x;
	yOrigin = y;
}

double Object::GetXOrigin()
{
	return xOrigin;
}

double Object::GetYOrigin()
{
	return yOrigin;
}

FRect Object::GetLocalBoundingBox()
{
	FRect rect;

	rect.x = -GetXSize() * GetXOrigin();
	rect.y = -GetYSize() * GetYOrigin();
	rect.w = GetXSize();
	rect.h = GetYSize();

	return rect;
}

void Object::AddPreparedObjects()
{
	for (Object* obj : objectsToCreate)
	{
		AddObject(obj);
	}

	objectsToCreate.clear();
}

bool Object::IsActive()
{
	return active;
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