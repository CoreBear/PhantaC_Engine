#pragma region Dependencies
#include "InputController.h"
#pragma endregion

#pragma region Update
void InputController::KeyPressed(ushort keyPressed, float deltaTime)
{
	// Deltatime is equal to zero for some reason...
	switch (keyPressed)
	{
	case LEFT_ARROW:
		cameraPtr->Move(0, deltaTime);
		break;
	case UP_ARROW:
		cameraPtr->Move(1, deltaTime);
		break;
	case RIGHT_ARROW:
		cameraPtr->Move(2, deltaTime);
		break;
	case DOWN_ARROW:
		cameraPtr->Move(3, deltaTime);
		break;
	}
}
void InputController::KeyReleased(ushort keyReleased, float deltaTime)
{

}
void InputController::MouseButtonPressed(ushort buttonPressed, float deltaTime)
{

}
void InputController::MouseButtonRelease(ushort buttonReleased, float deltaTime)
{

}
void InputController::MouseMovement(ushort xPosition, ushort yPosition)
{

}
#pragma endregion