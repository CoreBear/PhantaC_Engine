#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>
#include <chrono>
#include <thread>

// My Headers
#include "GlobalTypedefs.h"
#include "GlobalTime.h"

// Forward Declarations
class AudioManager;
class InputManager;
class PhysicsManager;
class Renderer;
class SceneManager;

class EnvironmentManager
{	
	// Game Variables
	AudioManager*							audioManagerPtr;
	bool									cycleCompleted[5];
	bool									resetTimes[5];
	float									cumulativeDeltas[5];
	InputManager*							inputManagerPtr;
	PhysicsManager*							physicsManagerPtr;
	Renderer*								rendererPtr;
	SceneManager*							sceneManagerPtr;
	std::chrono::duration<float>			chronoDelta[5];
	std::chrono::steady_clock::time_point	startTime[5];
	std::chrono::steady_clock::time_point	endTime[5];
	const static uchar						numberOfThreads = 5;
	uchar									threadIterator;
	const uchar								targetFPS = 100;
	std::thread*							threads[numberOfThreads];
	
public:
	// Initialization
	EnvironmentManager(HWND windowHandle, ushort* clientDimensions);
	void ThreadMaintenance(MSG* msg);

	// Thread Functions
	void RunAudio(MSG* msg);
	void RunInput(MSG* msg);
	void RunPhysics(MSG* msg);
	void RunRenderer(MSG* msg);
	void RunScene(MSG* msg);

	// Clean Up
	~EnvironmentManager();
};

#endif