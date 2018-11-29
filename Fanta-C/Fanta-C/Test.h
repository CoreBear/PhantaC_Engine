#pragma once
#include "MovingObject.h"

class Test : public MovingObject
{
	XMVECTOR* targetPosition;

public:
	// Initialization
	Test(ObjectManager* inObject, float inVelocity = 1, float inAngularVelocity = 1) : MovingObject(inObject, inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;

	void AssignTarget(XMVECTOR* inTargetPosition) override { targetPosition = inTargetPosition; }
};