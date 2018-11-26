#pragma region Dependencies
// My Headers
#include "InputManager.h"			// Connection to declarations

#pragma endregion

#pragma region Update
void InputManager::Update()
{
	// If a controller is plugged in, run it
	if (controllerManagerPtr->CheckControllerStatus())
	{

	}
}
#pragma endregion