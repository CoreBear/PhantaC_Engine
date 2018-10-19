#pragma region Dependencies
#include "InputController.h"
#pragma endregion

#pragma region Update
void InputController::UpdateController()
{
	// Cannot pass these functions, because they are member functions

	// A - Yaw Left
	if (keysCurrentlyPressed[0])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnYAxis(-playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// D - Yaw Right
	if (keysCurrentlyPressed[1])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnYAxis(playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// I - Nose Down
	if (keysCurrentlyPressed[2])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnXAxis(-playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// J - Roll Left
	if (keysCurrentlyPressed[3])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnZAxis(-playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// K - Nose Up
	if (keysCurrentlyPressed[4])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnXAxis(playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// L - Roll Right
	if (keysCurrentlyPressed[5])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->OnZAxis(playerPtr->GetRotationsSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// S - Move Back
	if (keysCurrentlyPressed[6])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->Translate(0, playerPtr->GetMoveSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// W - Move Forward
	if (keysCurrentlyPressed[7])
	{
		playerPtr->ResetTransformMatrix();
		playerPtr->Translate(0, -playerPtr->GetMoveSpeed());
		playerPtr->UpdateWorldMatrix();
	}

	// Space - Shoot
	if (keysCurrentlyPressed[8])
	{

	}
}
#pragma endregion

#pragma region Input
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

}
#pragma endregion