#pragma region Dependencies
// My Headers
#include "InputManager.h"		// Connection to declarations
#include "Player.h"

// Defines
// Mouse position capture
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#pragma endregion

#pragma region Update
void InputManager::Update(float deltaTime)
{
	if (keysCurrentlyPressed[0])
		playerPtr->ControllerInput(A, deltaTime);
	if (keysCurrentlyPressed[1])
		playerPtr->ControllerInput(D, deltaTime);
	if (keysCurrentlyPressed[2])
		playerPtr->ControllerInput(I, deltaTime);
	if (keysCurrentlyPressed[3])
		playerPtr->ControllerInput(J, deltaTime);
	if (keysCurrentlyPressed[4])
		playerPtr->ControllerInput(K, deltaTime);
	if (keysCurrentlyPressed[5])
		playerPtr->ControllerInput(L, deltaTime);
	if (keysCurrentlyPressed[6])
		playerPtr->ControllerInput(S, deltaTime);
	if (keysCurrentlyPressed[7])
		playerPtr->ControllerInput(W, deltaTime);
	if (keysCurrentlyPressed[8])
		playerPtr->ControllerInput(SPACE, deltaTime);
}
#pragma endregion

#pragma region Public Interface
void InputManager::KeyPressed(ushort keyPressed)
{
	// Add more to each switch for "Pushed this frame"
	switch (keyPressed)
	{
	case A:
		keysCurrentlyPressed[0] = true;
		break;
	case D:
		keysCurrentlyPressed[1] = true;
		break;
	case I:
		keysCurrentlyPressed[2] = true;
		break;
	case J:
		keysCurrentlyPressed[3] = true;
		break;
	case K:
		keysCurrentlyPressed[4] = true;
		break;
	case L:
		keysCurrentlyPressed[5] = true;
		break;
	case S:
		keysCurrentlyPressed[6] = true;
		break;
	case W:
		keysCurrentlyPressed[7] = true;
		break;
	case SPACE:
		keysCurrentlyPressed[8] = true;
		break;
	default:
		break;
	}
}
void InputManager::KeyReleased(ushort keyReleased)
{
	// Add more to each switch for "Released this frame"
	switch (keyReleased)
	{
	case A:
		keysCurrentlyPressed[0] = false;
		break;
	case D:
		keysCurrentlyPressed[1] = false;
		break;
	case I:
		keysCurrentlyPressed[2] = false;
		break;
	case J:
		keysCurrentlyPressed[3] = false;
		break;
	case K:
		keysCurrentlyPressed[4] = false;
		break;
	case L:
		keysCurrentlyPressed[5] = false;
		break;
	case S:
		keysCurrentlyPressed[6] = false;
		break;
	case W:
		keysCurrentlyPressed[7] = false;
		break;
	case SPACE:
		keysCurrentlyPressed[8] = false;
		break;
	default:
		break;
	}
}
void InputManager::MouseButtonPressed(ushort buttonPressed)
{

}
void InputManager::MouseButtonRelease(ushort buttonReleased)
{

}
void InputManager::MouseMovement(ushort xPosition, ushort yPosition)
{
	//GET_X_LPARAM(lParam); This came from inputManager.MouseMovement(
}
#pragma endregion