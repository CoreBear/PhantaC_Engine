#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <chrono>
#include <Windows.h>

// My Headers
#include "GlobalConsoleWrite.h"
#include "GlobalTypedefs.h"

// Foreward Declarations
class WindowCreator;

class EnvironmentManager
{	
	// Variables
	class AudioManager*						audioManagerPtr;
	static EnvironmentManager*				environmentManagerInstance;
	class InputManager*						inputManagerPtr;
	float									fpsTimeElapsed;
	class PhysicsManager*					physicsManagerPtr;
	class Renderer*							rendererPtr;
	class SceneManager*						sceneManagerPtr;
	std::chrono::duration<float>			chronoDelta;
	std::chrono::steady_clock::time_point	frameEndTime;
	std::chrono::steady_clock::time_point	frameStartTime;
	std::string								fpsString;
	const uchar								targetFPS;
	class UiManager*						uiManagerPtr;
	ushort									actualFpsCount;
	ushort									frameCounter;
	const ushort							thousandMilliseconds; 

	// Initialization
	EnvironmentManager(WindowCreator* window);
	EnvironmentManager(EnvironmentManager const&) = delete;
	EnvironmentManager operator=(EnvironmentManager const&) = delete;

	// Private Functionality
	void FPSEnd();
	void FPSStart();

public:
	// Initialization
	static EnvironmentManager* GetInstance(WindowCreator* window);

	// Update
	void Update();

	// Clean Up
	~EnvironmentManager();
};

#endif