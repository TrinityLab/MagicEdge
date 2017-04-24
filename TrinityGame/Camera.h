#pragma once

class Camera
{
private:
	static double xOffset;
	static double yOffset;
public:
	static void SetOffset(double xOffset, double yOffset);
	static double GetXOffset();
	static double GetYOffset();
	static void Move(double x, double y);
};