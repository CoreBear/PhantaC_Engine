#ifndef _BULLET_TRAIL_H
#define _BULLET_TRAIL_H

// My Headers
#include "NonMovingObject.h"

class BulletTrail : public NonMovingObject
{
	// Variables
	constexpr static float	lifeTime = 0.1f;
	float					timeAlive;

public:
	// Initialization
	BulletTrail(SceneObject* inObject) : timeAlive(0), NonMovingObject(inObject) { return; }

	// Update
	void Update();
};

#endif