#ifndef _MOVING_OBJECT_H
#define _MOVING_OBJECT_H

// My Headers
#include "ScriptManager.h"

class MovingObject : public ScriptManager
{
protected:
	float velocity;
	float angularVelocity;

public:
	// Initialization
	MovingObject(ObjectManager* inObject, float inVelocity = 1, float inAngularVelocity = 1) : velocity(inVelocity), angularVelocity(inAngularVelocity), ScriptManager(inObject) { return; }
};

#endif