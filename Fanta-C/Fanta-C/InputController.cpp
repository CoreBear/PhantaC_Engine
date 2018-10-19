#pragma region Dependencies
#include "InputController.h"
#pragma endregion

#pragma region Update
void InputController::Update()
{
	cameraPtr->Transform(keysCurrentlyPressed);
}
#pragma endregion

#pragma region Input
void InputController::KeyPressed(ushort keyPressed)
{
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
	default:
		break;
	}
}
void InputController::KeyReleased(ushort keyReleased)
{
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

}
#pragma endregion