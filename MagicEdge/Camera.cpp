#include "StandardInc.h"
#include "Camera.h"
#include "Screen.h"

double Camera::xOffset = 0.0;
double Camera::yOffset = 0.0;

void Camera::SetOffset(double x, double y)
{
	xOffset = x;
	yOffset = y;
}

double Camera::GetXOffset()
{
	return xOffset;
}

double Camera::GetYOffset()
{
	return yOffset;
}

void Camera::Move(double x, double y)
{
	SetOffset(xOffset + x, yOffset + y);
}