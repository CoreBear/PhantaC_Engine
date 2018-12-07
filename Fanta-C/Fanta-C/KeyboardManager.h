#ifndef _KEYBOARD_MANAGER_H
#define _KEYBOARD_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class InputManager;
class PlayerManager;

class KeyboardManager
{
	bool					keyDownThisFrame[9];
	bool					keyIsDown[9];
	InputManager*			inputManagerPtr;
	static KeyboardManager* keyboardManagerInstance;
	PlayerManager*			playerManagerPtr;

	// Initialization
	KeyboardManager(PlayerManager* inPlayerManager);
	KeyboardManager(KeyboardManager const&) = delete;
	KeyboardManager operator=(KeyboardManager const&) = delete;

	void KeyEventHandler(bool keyDown, uchar index);

public:
	// Update
	void Update();

	// Accessors
	static KeyboardManager* GetInstance(PlayerManager* inPlayerManager);
};

#endif