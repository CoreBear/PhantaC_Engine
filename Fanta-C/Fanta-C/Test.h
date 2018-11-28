#pragma once
#include "MovingObject.h"

class Test : public MovingObject
{
public:
	// Initialization
	Test(ObjectManager* inObject, float inVelocity = 1, float inAngularVelocity = 1) : MovingObject(inObject, inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;
};