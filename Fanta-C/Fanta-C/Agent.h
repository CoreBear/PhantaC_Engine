#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "ObjectTransform.h"

class Agent
{
protected:
	ObjectTransform*		physicalBodyPtr;

public:
	// Initialization
	Agent(ObjectTransform* physicalBodyPtr, float inMoveSpeed, float inRotationSpeed);

	// Update
	virtual void Update(float deltaTime) { return; }

	// Accessor
	ObjectTransform* GetPhysicalBodyPtr() const { return physicalBodyPtr; }
};

#endif