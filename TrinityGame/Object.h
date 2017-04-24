#pragma once

#include "SDL.h"
#include <list>
#include <map>
#include <string>
#include "Utility.h"

using namespace std;

class Object
{
protected:
	static list<Object*> objects;
	static list<Object*> objectsToCreate;
	string name;
	bool active;

	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void OnCreated() = 0;
	virtual void OnDestroyd() = 0;

	bool ContainsObject(list<Object*>& l, Object* obj);

	double xPosition, yPosition;
	double angle;
	double xSize, ySize;
	double xScale, yScale;
	double xOrigin, yOrigin;
private:
	static Object* FindObject(string name);
	static void AddObject(Object* object);
	static void DeleteObject(Object* object);
	static void DeleteFromList(Object* object);
	static void AddPreparedObjects();
public:
	static void ClearObjects();
	static void Destroy(Object* obj);
	Object(std::string name);
	~Object();
	std::string GetObjectName();

	void SetActive(bool active);
	bool IsActive();

	virtual void SetPosition(double x, double y);
	void SetSize(double x, double y);
	void SetRotation(double angle);
	void SetScale(double x, double y);
	void SetOrigin(double x, double y);
	void ResetScale();

	double GetXPosition();
	double GetYPosition();
	double GetXSize();
	double GetYSize();
	double GetRotation();
	double GetXOrigin();
	double GetYOrigin();

	virtual void Move(double deltaX, double deltaY);
	void Scale(double x, double y);
	void Rotate(double delta);

	FRect GetLocalBoundingBox();

	friend class Scene;
};