#ifndef _ENVIRONMENT_MANAGER_H
#define _ENVIRONMENT_MANAGER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

class EnvironmentManager
{	
	// Game Variables
	class AudioManager*														audioManagerPtr;
	const char																targetFPS = 60;
	static EnvironmentManager*												environmentManagerInstance;
	class EventManager*														eventManagerPtr;
	class PhysicsManager*													physicsManagerPtr;
	class Renderer*															rendererPtr;
	class SceneManager*														sceneManagerPtr;

	// Initialization
	EnvironmentManager(HWND* inWindowHandle, ushort* clientDimensions);
	EnvironmentManager(EnvironmentManager const&) = delete;
	EnvironmentManager operator=(EnvironmentManager const&) = delete;

public:
	// Public Interface
	/// Summary
	/// Hacked. Delete later
	/// Updates the fps in the window's title bar
	///
	/// Parameters
	/// fps - The text that will be used for the udpate

	// Thread Functions
	void RunAudio();
	void RunEventHandler();
	void RunPhysics();
	void RunRenderer();
	void RunScene();

	// Accessors
	static EnvironmentManager* GetInstance(HWND* inWindowHandle, ushort* clientDimensions);

	// Clean Up
	~EnvironmentManager();
};

#endif