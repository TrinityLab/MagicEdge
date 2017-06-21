#pragma once

#include "ObjectComponent.h"
#include "Utility.h"

class Transform : public Component
{
private:
	float xPosition, yPosition;
	float xSize, ySize;
	float xOrigin, yOrigin;
	
public:
	Transform(Object* obj) : Component(obj) {}

	float GetXPosition();
	float GetYPosition();
	void SetPosition(float x, float y);
	void Move(float dx, float dy);

	float GetXSize();
	float GetYSize();
	void SetSize(float x, float y);
	void Scale(float sx, float sy);

	float GetXOrigin();
	float GetYOrigin();
	void SetOrigin(float x, float y);

	FRect GetLocalBoundingBox();
};