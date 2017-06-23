#include "StandardInc.h"
#include "Camera.h"
#include "Screen.h"
#include "Transform.h"

double Camera::xOffset = 0.0;
double Camera::yOffset = 0.0;
Transform* Camera::target = nullptr;

void Camera::SetOffset(double x, double y)
{
	xOffset = x;
	yOffset = y;
}

double Camera::GetXOffset()
{
	if (!target)
		return xOffset;
	else
		return target->GetXPosition() - Screen::GetWidth() * 0.5;
}

double Camera::GetYOffset()
{
	if (!target)
		return yOffset;
	else
		return target->GetYPosition() - Screen::GetHeight() * 0.5f;
}

void Camera::Move(double x, double y)
{
	SetOffset(xOffset + x, yOffset + y);
}

void Camera::Follow(Transform* target)
{
	Camera::target = target;
}