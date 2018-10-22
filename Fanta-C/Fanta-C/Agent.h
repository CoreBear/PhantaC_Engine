#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "ObjectTransform.h"

class Agent
{
	bool					isColliding;

protected:
	ObjectTransform*		physicalBodyPtr;

public:
	// Initialization
	Agent(ObjectTransform* physicalBodyPtr, float inMoveSpeed, float inRotationSpeed);

	// Update
	virtual void Plan() { return; }

	// Accessors
	bool GetColliding() const { return isColliding; }
	ObjectTransform* GetPhysicalBodyPtr() const { return physicalBodyPtr; }

	// Mutators
	void ToggleColliding() { isColliding = !isColliding; }
};

#endif