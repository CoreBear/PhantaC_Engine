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
	BulletTrail(SceneGraph* inSceneGraph, SceneObject* inObject) : timeAlive(0), NonMovingObject(inSceneGraph, inObject) { return; }
	void ReInit() { timeAlive = 0; }

	// Update
	void Update();
};

#endif