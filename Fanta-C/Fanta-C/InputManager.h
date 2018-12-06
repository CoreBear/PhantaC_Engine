#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

// My Headers
#include "ControllerManager.h"

// Forward Declarations
class PlayerManager;

class InputManager
{
	ControllerManager*		controllerManagerPtr;
	static InputManager*	inputManagerInstance;
	PlayerManager*			playerManagerPtr;

	// Initialization
	InputManager(PlayerManager* inPlayerManager) : playerManagerPtr(inPlayerManager) { controllerManagerPtr = ControllerManager::GetInstance(); }
	InputManager(InputManager const&) = delete;
	InputManager operator=(InputManager const&) = delete;

public:
	// Update
	void Update();

	// Accessors
	static InputManager* GetInstance(PlayerManager* inPlayerManager = nullptr);

	// Clean Up
	~InputManager() { if (controllerManagerPtr) delete controllerManagerPtr; }

};

#endif