#ifndef _ENEMY_BASE_H
#define _ENEMY_BASE_H

// My Headers
#include "Agent.h"

class EnemyBase : public Agent
{
public:
	// Initialization
	EnemyBase(ObjectTransform* inPhysicalBodyPtr, float inMoveSpeed, float inRotationSpeed) : Agent(inPhysicalBodyPtr, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	void Update(float deltaTime) override;
};

#endif