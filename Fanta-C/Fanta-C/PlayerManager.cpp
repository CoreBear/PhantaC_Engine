#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "GlobalInput.h"
#pragma endregion

#pragma region Update
void PlayerManager::Update()
{
	PlayerInput();
}
#pragma endregion

#pragma region Private
void PlayerManager::PlayerInput()
{
	if (GlobalInput::keysPressed[0])
		Move(1, 0, 0);
	if (GlobalInput::keysPressed[1])
		Move(-1, 0, 0);
	if (GlobalInput::keysPressed[2])
		Pitch(1);
	if (GlobalInput::keysPressed[3])
		Yaw(-1);
	if (GlobalInput::keysPressed[4])
		Pitch(-1);
	if (GlobalInput::keysPressed[5])
		Yaw(1);
	if (GlobalInput::keysPressed[6])
		Move(0, 0, 1);
	if (GlobalInput::keysPressed[7])
		Move(0, 0, -1);
	if (GlobalInput::keysPressed[8])
		return;
}
#pragma endregion
