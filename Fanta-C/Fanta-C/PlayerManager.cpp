#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "GlobalInputVariables.h"
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
	if (GlobalInputVariables::keysPressed[0])
		Move(1, 0, 0);
	if (GlobalInputVariables::keysPressed[1])
		Move(-1, 0, 0);
	if (GlobalInputVariables::keysPressed[2])
		Pitch(1);
	if (GlobalInputVariables::keysPressed[3])
		Yaw(-1);
	if (GlobalInputVariables::keysPressed[4])
		Pitch(-1);
	if (GlobalInputVariables::keysPressed[5])
		Yaw(1);
	if (GlobalInputVariables::keysPressed[6])
		Move(0, 0, 1);
	if (GlobalInputVariables::keysPressed[7])
		Move(0, 0, -1);
	if (GlobalInputVariables::keysPressed[8])
		return;
}
#pragma endregion
