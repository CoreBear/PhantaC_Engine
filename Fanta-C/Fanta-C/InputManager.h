#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

// My Headers
#include "ControllerManager.h"

class InputManager
{
	ControllerManager*	controllerManagerPtr;

public:
	// Initialization
	InputManager() { controllerManagerPtr = new ControllerManager; }

	// Update
	void Update();

	// Clean Up
	~InputManager() { if (controllerManagerPtr) delete controllerManagerPtr; }

};

#endif