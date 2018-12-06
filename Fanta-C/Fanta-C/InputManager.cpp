#pragma region Dependencies
// My Headers
#include "InputManager.h"			// Connection to declarations

#include "GlobalInputVariables.h"
#include "PlayerManager.h"
#pragma endregion

#pragma region Forward Declarations
InputManager* InputManager::inputManagerInstance = nullptr;
#pragma endregion

#pragma region Update
void InputManager::Update()
{
	// If a controller is plugged in, run it
	if (controllerManagerPtr->CheckControllerStatus())
	{

	}

	// If no controller
	else
	{
		if (GlobalInputVariables::KeyIsDown[0])
			playerManagerPtr->Move(-1, 0, 0);
		if (GlobalInputVariables::KeyIsDown[1])
			playerManagerPtr->Move(1, 0, 0);
		if (GlobalInputVariables::KeyIsDown[2])
			playerManagerPtr->Pitch(-1);
		if (GlobalInputVariables::KeyIsDown[3])
			playerManagerPtr->Yaw(1);
		if (GlobalInputVariables::KeyIsDown[4])
			playerManagerPtr->Pitch(1);
		if (GlobalInputVariables::KeyIsDown[5])
			playerManagerPtr->Yaw(-1);
		if (GlobalInputVariables::KeyIsDown[6])
			playerManagerPtr->Move(0, 0, -1);
		if (GlobalInputVariables::KeyIsDown[7])
			playerManagerPtr->Move(0, 0, 1);
		if (GlobalInputVariables::KeyDownThisFrame[8])
			playerManagerPtr->Shoot();
	}
}
#pragma endregion

#pragma region Accessors
InputManager * InputManager::GetInstance(PlayerManager * inPlayerManager)
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