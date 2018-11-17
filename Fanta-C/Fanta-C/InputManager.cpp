#pragma region Dependencies
// My Headers
#include "InputManager.h"		// Connection to declarations

#include "PlayerManager.h"
#include "SceneManager.h"
#pragma endregion

#pragma region Update
void InputManager::Update(bool* keysCurrentlyPressed)
{
	if (keysCurrentlyPressed[0])	// A
		playerPtr->Yaw(-1);
	if (keysCurrentlyPressed[1])	// D
		playerPtr->Yaw(1);
	if (keysCurrentlyPressed[2])	// I
		playerPtr->Pitch(-1);
	if (keysCurrentlyPressed[3])	// J
		playerPtr->Roll(-1);
	if (keysCurrentlyPressed[4])	// K
		playerPtr->Pitch(1);
	if (keysCurrentlyPressed[5])	// L
		playerPtr->Roll(1);
	if (keysCurrentlyPressed[6])	// S
		playerPtr->Move(0, 0, 1);
	if (keysCurrentlyPressed[7])	// W
		playerPtr->Move(0, 0, -1);
	if (keysCurrentlyPressed[8])
		return;
	if (keysCurrentlyPressed[9])
		sceneManagerPtr->ChangeScene(0);
	if (keysCurrentlyPressed[10])		
		sceneManagerPtr->ChangeScene(1);
}
#pragma endregion