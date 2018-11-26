#pragma region Dependencies
// My Headers
#include "KeyboardManager.h"			// Connection to declarations

#include "GlobalInput.h"
#pragma endregion

#pragma region Update
void KeyboardManager::Update(std::unordered_map<char, char>* keyMap)
{
	if (GlobalInput::keysPressed[0])
		return;
	if (GlobalInput::keysPressed[1])
		return;
	if (GlobalInput::keysPressed[2])
		return;
	if (GlobalInput::keysPressed[3])
		return;
	if (GlobalInput::keysPressed[4])
		return;
	if (GlobalInput::keysPressed[5])
		return;
	if (GlobalInput::keysPressed[6])
		return;
	if (GlobalInput::keysPressed[7])
		return;
	if (GlobalInput::keysPressed[8])
		return;
}
#pragma endregion
