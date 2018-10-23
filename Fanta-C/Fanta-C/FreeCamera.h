#ifndef _FREE_CAMERA_H
#define _FREE_CAMERA_H

// My Headers
#include "AutonomousAgent.h"

class FreeCamera : public AutonomousAgent
{
public:
	// Initialization
	FreeCamera(ObjectTransform* intransformPtr, bool collider, bool renderer, float inMoveSpeed = 0, float inRotationSpeed = 0) : AutonomousAgent(intransformPtr, collider, renderer, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	void Action(float deltaTime) override;
};

#endif