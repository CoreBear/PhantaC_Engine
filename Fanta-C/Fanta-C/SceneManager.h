#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"
#include "WindowCreator.h"

// Foreward Declarations
class WindowCreator;

class SceneManager
{			
	class SceneGraph* scenePtr;
	static SceneManager* sceneManagerInstance;

	// Initialization
	SceneManager(Application_Level::WindowCreator& window);
	SceneManager(SceneManager const&) = delete;
	SceneManager operator= (SceneManager const&) = delete;

public:
	// Update
	void Update();

	// Accessors
	SceneGraph* GetScenePtr() { return scenePtr; }
	static SceneManager* GetInstance(Application_Level::WindowCreator& windowHandle);

	// Clean up
	~SceneManager();
};

#endif