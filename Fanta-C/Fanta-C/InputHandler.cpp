#pragma region Dependencies
// My Headers
#include "InputHandler.h"			// Connection to declarations

#include "GlobalInputVariables.h"
#include "PlayerManager.h"
#pragma endregion

#pragma region Forward Declarations
InputHandler* InputHandler::inputHandlerInstance = nullptr;
#pragma endregion

#pragma region Initialization
InputHandler* InputHandler::GetInstance(PlayerManager& inPlayerManager)
{
	// If instance has already been created, return it
	if (inputHandlerInstance) return inputHandlerInstance;

	// If instance has not been created, created it and return it
	else
	{
		inputHandlerInstance = new InputHandler(inPlayerManager);
		return inputHandlerInstance;
	}
}
#pragma endregion

#pragma region Public Interface
void InputHandler::HandleInput(bool downThisFrame, uchar key)
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