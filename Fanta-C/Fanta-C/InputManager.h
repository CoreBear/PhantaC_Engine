#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PlayerManager;
class SceneObject;
class SceneGraph;

class InputManager
{
	// Variables
	class ControllerManager*												controllerManagerPtr;
	static InputManager*													inputManagerInstance;
	class KeyboardManager*													keyboardManagerPtr;
	SceneGraph*																sceneGraphPtr;

	// Initialization
	InputManager(PlayerManager* inPlayerManager, SceneGraph* inSceneGraph);
	InputManager(InputManager const&) = delete;
	InputManager operator=(InputManager const&) = delete;

public:
	// Initialization
	static InputManager* GetInstance(PlayerManager* inPlayerManager = nullptr, SceneGraph* inSceneGraph = nullptr);
	
	// Update
	void Update();

	// Clean Up
	~InputManager();
};

#endif
