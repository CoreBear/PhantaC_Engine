#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

class SceneManager
{			
	class SceneGraph* scenePtr;
	static SceneManager* sceneManagerInstance;

	// Initialization
	SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS);
	SceneManager(SceneManager const&) = delete;
	SceneManager operator= (SceneManager const&) = delete;

public:
	// Update
	void Update();

	// Accessors
	SceneGraph* GetScenePtr() { return scenePtr; }
	static SceneManager* GetInstance(ushort* clientDimensions = nullptr, HWND* windowHandle = nullptr, uchar targetFPS = 0);

	// Clean up
	~SceneManager();
};

#endif