#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "Typedefs.h"
#include "Camera.h"

class InputController
{
	bool		keysCurrentlyPressed[8] = { false };
	Camera*		cameraPtr;
	enum		KEYS { A = 0x41, I = 0x49, J = 0x4A, K = 0x4B, L = 0x4C, D = 0x44, S = 0x53, W = 0x57 };
public:
	// Update
	void Update();

	// Input
	void KeyPressed(ushort keyPressed);
	void KeyReleased(ushort keyReleased);
	void MouseButtonPressed(ushort buttonPressed);
	void MouseButtonRelease(ushort buttonReleased);
	void MouseMovement(ushort xPosition, ushort yPosition);

	// Mutator
	void AssignCamera(Camera* camera) { cameraPtr = camera; }
};

#endif