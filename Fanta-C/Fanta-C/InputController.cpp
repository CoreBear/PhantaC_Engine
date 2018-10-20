#pragma region Dependencies
// My Headers
#include "InputController.h"		// Connection to declarations
#include "Player.h"

// Defines
// Mouse position capture
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#pragma endregion

#pragma region Update
void InputController::Update()
{
	if (keysCurrentlyPressed[0])
		playerPtr->ControllerInput(A);
	if (keysCurrentlyPressed[1])
		playerPtr->ControllerInput(D);
	if (keysCurrentlyPressed[2])
		playerPtr->ControllerInput(I);
	if (keysCurrentlyPressed[3])
		playerPtr->ControllerInput(J);
	if (keysCurrentlyPressed[4])
		playerPtr->ControllerInput(K);
	if (keysCurrentlyPressed[5])
		playerPtr->ControllerInput(L);
	if (keysCurrentlyPressed[6])
		playerPtr->ControllerInput(S);
	if (keysCurrentlyPressed[7])
		playerPtr->ControllerInput(W);
	if (keysCurrentlyPressed[8])
		playerPtr->ControllerInput(SPACE);
}
#pragma endregion

#pragma region Public Interface
void InputController::KeyPressed(ushort keyPressed)
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
void InputController::KeyReleased(ushort keyReleased)
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
void InputController::MouseButtonPressed(ushort buttonPressed)
{

}
void InputController::MouseButtonRelease(ushort buttonReleased)
{

}
void InputController::MouseMovement(ushort xPosition, ushort yPosition)
{
	//GET_X_LPARAM(lParam); This came from inputController.MouseMovement(
}
#pragma endregion