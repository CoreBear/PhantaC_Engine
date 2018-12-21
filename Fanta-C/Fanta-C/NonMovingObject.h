#ifndef _NON_MOVING_OBJECT_H
#define _NON_MOVING_OBJECT_H

// My Headers
#include "CollidingObject.h"

class NonMovingObject : public CollidingObject
{
public:
	// Initialization
	NonMovingObject(SceneObject* inObject) : CollidingObject(inObject) { return; }
};

#endif