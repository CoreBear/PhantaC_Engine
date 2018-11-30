#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>
//#include <chrono>
#include <thread>

// My Headers
#include "GlobalTypedefs.h"

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
	class UiManager*						uiManagerPtr;

public:

	// Initialization
	EnvironmentManager(HWND windowHandle, ushort* clientDimensions);

	// Public Interface
	/// Summary
	/// Starts the threads that will run player input and update all
	/// components of the frame
	///
	/// Parameters
	/// msg - The container that holds events and will signal to the
	/// threads, when the quit conditions is met
	void ThreadLauncher(MSG* msg);

	// Thread Functions
	void RunAudio();
	void RunInput();
	void RunPhysics();
	void RunRenderer();
	void RunScene();
	void RunUI();

	// Clean Up
	~EnvironmentManager();
};

#endif