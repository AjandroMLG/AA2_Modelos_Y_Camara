#pragma once


class TimeManager
{
public:
	float deltaTime;
	float lastFrame;

	TimeManager()
	{
		deltaTime = 0;
		lastFrame = 0;
	}

	void Update(float currentFrame)
	{
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}
};