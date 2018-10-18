#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "Typedefs.h"
#include "Camera.h"

class InputController
{
	Camera* cameraPtr;
	enum ARROWS { LEFT_ARROW = 0x25, UP_ARROW = 0x26, RIGHT_ARROW = 0x27, DOWN_ARROW = 0x28 };
public:
	// Update
	void KeyPressed(ushort keyPressed, float deltaTime);
	void KeyReleased(ushort keyReleased, float deltaTime);
	void MouseButtonPressed(ushort buttonPressed, float deltaTime);
	void MouseButtonRelease(ushort buttonReleased, float deltaTime);
	void MouseMovement(ushort xPosition, ushort yPosition);

	// Mutator
	void AssignCamera(Camera* camera) { cameraPtr = camera; }
};

#endif