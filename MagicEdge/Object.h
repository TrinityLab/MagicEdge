#pragma once

#include "StandardInc.h"
#include "Utility.h"

class Object
{
protected:
	static list<Object*> objects;
	static list<Object*> objectsToCreate;
	vector<string> tags;
	bool destroy;

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
	static Object* FindObjectWithTag(string tag);
	static void AddObject(Object* object);
	static void DeleteFromList(Object* object);
	static void AddPreparedObjects();
public:
	static void ClearObjects();
	static void Destroy(Object* obj);
	Object();
	virtual ~Object();

	bool HasTag(string tag);
	void AddTag(string tag);

	virtual void SetPosition(double x, double y);
	virtual void SetSize(double x, double y);
	virtual void SetRotation(double angle);
	virtual void SetScale(double x, double y);
	virtual void SetOrigin(double x, double y);
	virtual void ResetScale();

	virtual double GetXPosition();
	virtual double GetYPosition();
	virtual double GetXSize();
	virtual double GetYSize();
	virtual double GetRotation();
	virtual double GetXOrigin();
	virtual double GetYOrigin();

	virtual void Move(double deltaX, double deltaY);
	virtual void Scale(double x, double y);
	virtual void Rotate(double delta);

	FRect GetLocalBoundingBox();

	bool useCamera = true;

	friend class Scene;
};