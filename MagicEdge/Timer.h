#pragma once

class Timer
{
private:
	static int lastTicks;
	static int currentTicks;
	static double deltaTime;
	static double totalTime;

	static void Init();
	static void Update();
public:
	static double GetDeltaTime();
	static double GetTotalTime();

	friend class Application;
};