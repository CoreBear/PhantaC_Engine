#pragma region Dependencies
// My Headers
#include "InputManager.h"			// Connection to declarations

#include "GlobalInputVariables.h"
#include "PlayerManager.h"
#pragma endregion

#pragma region Forward Declarations
InputManager* InputManager::inputManagerInstance = nullptr;
#pragma endregion

#pragma region Public Interface
void InputManager::HandleInput(bool downThisFrame, uchar key)
{
	switch (key)
	{
	case 0:
		playerManagerPtr->Yaw(1);
		break;
	case 1:
		playerManagerPtr->Yaw(-1);
		break;
	case 2:
		playerManagerPtr->Pitch(1);
		break;
	case 3:
		playerManagerPtr->Roll(1);
		break;
	case 4:
		playerManagerPtr->Pitch(-1);
		break;
	case 5:
		playerManagerPtr->Roll(-1);
		break;
	case 6:
		playerManagerPtr->Move(0, 0, -1);
		break;
	case 7:
		playerManagerPtr->Move(0, 0, 1);
		break;
	case 8:
		// Only allows shooting once per key press
		if (downThisFrame) playerManagerPtr->Shoot();
		break;
	}
}
#pragma endregion

#pragma region Accessors
InputManager* InputManager::GetInstance(PlayerManager * inPlayerManager)
{
	// If instance has already been created, return it
	if (inputManagerInstance) return inputManagerInstance;

	// If instance has not been created, created it and return it
	else
	{
		inputManagerInstance = new InputManager(inPlayerManager);
		return inputManagerInstance;
	}
}
#pragma endregion