#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"
#include "Renderer.h"

// Forward Declarations
class SceneGraph;

class SceneManager
{
	class AudioManager*			audioManagerPtr;	
	class InputManager*			inputManagerPtr;
	class PhysicsManager*		physicsManagerPtr;			
	class Renderer*				rendererPtr;
	SceneGraph*					currentScenePtr;
	std::vector<SceneGraph*>	sceneGraphsPtr;

public:
	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS, class InputManager* input);

	// Update
	void Update(float delteTime);

	// Public Interface
	void ChangeScene(uchar index);

	// Clean up
	~SceneManager();
};

#endif