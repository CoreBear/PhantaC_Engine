#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

// My Headers
#include "GlobalTypedefs.h"
#include "GlobalTime.h"

class EnvironmentManager
{	
	// Game Variables
	class AudioManager*						audioManagerPtr;
	class InputManager*						inputManagerPtr;
	MSG*									msg;
	class PhysicsManager*					physicsManagerPtr;
	class Renderer*							rendererPtr;
	class SceneManager*						sceneManagerPtr;
	const static uchar						numberOfThreads = 2;
	std::thread*							threads[numberOfThreads];
	const uchar								targetFPS = 60;

public:
	// Variables
	std::chrono::duration<float>			chronoDelta;
	std::chrono::steady_clock::time_point	frameEndTime;
	std::chrono::steady_clock::time_point	frameStartTime;

	// Initialization
	EnvironmentManager(HWND windowHandle, ushort* clientDimensions);

	// Public Interface
	void ThreadMaintenance(MSG* msg);

	// Thread Functions
	void RunAudio();
	void RunInput();
	void RunPhysics();
	void RunRenderer();
	void RunScene();

	// Clean Up
	~EnvironmentManager();
};

#endif