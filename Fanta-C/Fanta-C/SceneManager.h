#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "Renderer.h"

class SceneManager
{
	class AudioManager*			audioManagerPtr;	
	class InputManager*			inputManagerPtr;
	class PhysicsManager*		physicsManagerPtr;			
	class Renderer*				rendererPtr;
	class SceneGraph*			scenePtr;

public:
	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS, class InputManager* input);

	// Update
	void Update(float delteTime);

	// Clean up
	~SceneManager();
};

#endif