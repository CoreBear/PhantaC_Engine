#ifndef _KEYBOARD_MANAGER_H
#define _KEYBOARD_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class InputHandler;
class PlayerManager;

class KeyboardManager
{
	// Variables
	bool					keyDownThisFrame[9];
	bool					keyIsDown[9];
	InputHandler*			inputHandlerPtr;
	static KeyboardManager* keyboardManagerInstance;
	PlayerManager*			playerManagerPtr;

	// Initialization
	KeyboardManager(PlayerManager* inPlayerManager);
	KeyboardManager(KeyboardManager const&) = delete;
	KeyboardManager operator=(KeyboardManager const&) = delete;

	void KeyEventHandler(bool keyDown, uchar index);

public:
	// Initialization
	static KeyboardManager* GetInstance(PlayerManager* inPlayerManager);
	
	// Update
	void Update();
};

#endif