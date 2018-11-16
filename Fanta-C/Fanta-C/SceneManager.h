#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "Renderer.h"

class SceneManager
{
	class AudioManager*			audioManagerPtr;					
	class IntelligenceManager*	intelligenceManagerPtr;	// The actual running of the scene (game update. i.e. AI)
	class PhysicsManager*		physicsManagerPtr;			
	class Renderer*				rendererPtr;
	class SceneGraph*			sceneGraphPtr;

public:
	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS);

	// Update
	void Update(float deltaTime);

	// Clean up
	~SceneManager();
};

#endif