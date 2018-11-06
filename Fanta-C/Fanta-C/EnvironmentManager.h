#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>
#include <chrono>

// My Headers
#include "GlobalTypedefs.h"

class EnvironmentManager
{	
	// Game Variables
	float									deltaTime;
	class SceneManager*						sceneManagerPtr;
	std::chrono::duration<float>			chronoDelta;
	std::chrono::steady_clock::time_point	startTime;
	std::chrono::steady_clock::time_point	endTime;
	const uchar								targetFPS = 100;

public:
	// Initialization
	EnvironmentManager(HWND windowHandle, ushort* clientDimensions);

	// Update
	void Update();

	// Clean Up
	~EnvironmentManager();
};

#endif