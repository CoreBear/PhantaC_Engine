#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

// Foreward Declarations
class WindowCreator;

class SceneManager
{			
	class SceneGraph* scenePtr;
	static SceneManager* sceneManagerInstance;

	// Initialization
	SceneManager(WindowCreator* window, uchar targetFPS);
	SceneManager(SceneManager const&) = delete;
	SceneManager operator= (SceneManager const&) = delete;

public:
	// Update
	void Update();

	// Accessors
	SceneGraph* GetScenePtr() { return scenePtr; }
	static SceneManager* GetInstance(WindowCreator* windowHandle, uchar targetFPS);

	// Clean up
	~SceneManager();
};

#endif