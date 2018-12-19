#ifndef _MOVING_OBJECT_H
#define _MOVING_OBJECT_H

// My Headers
#include "CollidingObject.h"
#include "GlobalTime.h"

class MovingObject : public CollidingObject
{
protected:
	// Variables
	float pitchVelocity;
	float rollVelocity;
	float velocity;
	float yawVelocity;

public:
	// Initialization
	MovingObject(SceneGraph* inSceneGraph, SceneObject* inObject, float inpitchVelocity, float inRollVelocity, float inVelocity, float inYawVelocity) : pitchVelocity(inpitchVelocity), rollVelocity(inRollVelocity), velocity(inVelocity), yawVelocity(inYawVelocity), CollidingObject(inSceneGraph, inObject) { return; }

	// Update
	//virtual void Update() { return; }

	// Accessors
	float GetPitchVelocity() { return pitchVelocity; }
	float GetRollVelocity() { return rollVelocity; }
	float GetVelocity() { return velocity; }
	float GetYawVelocity() { return yawVelocity; }
};

#endif