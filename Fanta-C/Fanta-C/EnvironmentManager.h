#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>
#include <thread>

// My Headers
#include "GlobalTypedefs.h"

class EnvironmentManager
{	
	// Game Variables
	class AudioManager*						audioManagerPtr;
	HWND*									windowHandle;				// Will be used to manually update the window
	class InputManager*						inputManagerPtr;
	MSG*									msg;
	class PhysicsManager*					physicsManagerPtr;
	class Renderer*							rendererPtr;
	class SceneManager*						sceneManagerPtr;
	const static char						numberOfThreads = 3;
	std::thread*							threads[numberOfThreads];
	const char								targetFPS = 60;
	class UiManager*						uiManagerPtr;

public:

	// Initialization
	EnvironmentManager(HWND* inWindowHandle, ushort* clientDimensions);

	// Public Interface
	/// Summary
	/// Starts the threads that will run player input and update all
	/// components of the frame
	///
	/// Parameters
	/// msg - The container that holds events and will signal to the
	/// threads, when the quit conditions is met
	void InitializeEnvironment(MSG* msg);
	/// Summary
	/// Hacked. Delete later
	/// Updates the fps in the window's title bar
	///
	/// Parameters
	/// fps - The text that will be used for the udpate
	void UpdateFPSIndicator(const char* fps) { SetWindowText(*windowHandle, fps); }

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