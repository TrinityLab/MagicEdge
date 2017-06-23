#pragma once

class Transform;

class Camera
{
private:
	static double xOffset;
	static double yOffset;

	static Transform* target;

public:
	static void SetOffset(double xOffset, double yOffset);
	static double GetXOffset();
	static double GetYOffset();
	static void Move(double x, double y);

	static void Follow(Transform* target);
};