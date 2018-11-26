#ifndef _KEYBOARD_MANAGER_H
#define _KEYBOARD_MANAGER_H

// System Headers
#include <unordered_map>

class KeyboardManager
{
	bool keysPressed[11];

public:
	// Update
	void Update(std::unordered_map<char, char>* keyMap);

	// Accessors
	bool* GetKeysPressed() { return keysPressed; }
};

#endif