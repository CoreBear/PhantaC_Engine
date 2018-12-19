#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PlayerManager;

class InputHandler
{
	// Variables
	static InputHandler*	inputHandlerInstance;
	PlayerManager*			playerManagerPtr;

	// Initialization
	InputHandler(PlayerManager* inPlayerManager) : playerManagerPtr(inPlayerManager) { return; }
	InputHandler(InputHandler const&) = delete;
	InputHandler operator=(InputHandler const&) = delete;

public:
	// Initilization
	static InputHandler* GetInstance(PlayerManager* inPlayerManager = nullptr);

	// Public Interface
	void HandleInput(bool downThisFrame, uchar key);
};

#endif