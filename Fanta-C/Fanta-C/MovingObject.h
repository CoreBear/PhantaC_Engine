#ifndef _MOVING_OBJECT_H
#define _MOVING_OBJECT_H

// My Headers
#include "GlobalTime.h"
#include "ScriptManager.h"

class MovingObject : public ScriptManager
{
protected:
	float velocity;
	float angularVelocity;

public:
	// Initialization
	MovingObject(float inVelocity, float inAngularVelocity) : velocity(inVelocity), angularVelocity(inAngularVelocity) { return; }

	// Update
	virtual void Update() { return; }

	// Accessors
	float GetAngularVelocity() { return angularVelocity; }
};

#endif