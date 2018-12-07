#ifndef _BULLET_TRAIL_H
#define _BULLET_TRAIL_H

// My Headers
#include "Line.h"

class BulletTrail : public Line
{
	const static float lifeTime;

public:
	// Update
	void Update() override { return; }
};

#endif