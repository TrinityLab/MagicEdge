#include "StandardInc.h"
#include "Transform.h"
#include "Utility.h"

void Transform::SetPosition(float x, float y)
{
	xPosition = x;
	yPosition = y;
}

float Transform::GetXPosition()
{
	return xPosition;
}

float Transform::GetYPosition()
{
	return yPosition;
}

void Transform::Move(float dx, float dy)
{
	xPosition += dx;
	yPosition += dy;
}

void Transform::SetSize(float x, float y)
{
	xSize = x;
	ySize = y;
}

void Transform::Scale(float sx, float sy)
{
	xSize *= sx;
	ySize *= sy;
}

float Transform::GetXSize()
{
	return xSize;
}

float Transform::GetYSize()
{
	return ySize;
}

FRect Transform::GetLocalBoundingBox()
{
	FRect rect;
	rect.x = -xSize * xOrigin;
	rect.y = -ySize * yOrigin;
	rect.w = xSize;
	rect.h = ySize;

	return rect;
}

void Transform::SetOrigin(float x, float y)
{
	xOrigin = x;
	yOrigin = y;
}

float Transform::GetXOrigin()
{
	return xOrigin;
}

float Transform::GetYOrigin()
{
	return yOrigin;
}