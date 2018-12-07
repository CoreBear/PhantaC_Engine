#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PlayerManager;

class InputManager
{
	static InputManager*	inputManagerInstance;
	PlayerManager*			playerManagerPtr;

	// Initialization
	InputManager(PlayerManager* inPlayerManager) : playerManagerPtr(inPlayerManager) { return; }
	InputManager(InputManager const&) = delete;
	InputManager operator=(InputManager const&) = delete;

public:
	// Public Interface
	void HandleInput(bool downThisFrame, uchar key);

	// Accessors
	static InputManager* GetInstance(PlayerManager* inPlayerManager = nullptr);
};

#endif