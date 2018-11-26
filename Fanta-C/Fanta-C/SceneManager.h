#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

class SceneManager
{			
	class SceneGraph*		scenePtr;

public:
	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS);

	// Update
	void Update();

	// Accessors
	SceneGraph* GetScenePtr() { return scenePtr; }

	// Clean up
	~SceneManager();
};

#endif