#ifndef _ENEMY_BASE_H
#define _ENEMY_BASE_H

// My Headers
#include "AutonomousAgent.h"

class EnemyBase : public AutonomousAgent
{
public:
	// Initialization
	EnemyBase(ObjectTransform* intransformPtr, bool collidable, bool renderable, float inMoveSpeed, float inRotationSpeed) : AutonomousAgent(intransformPtr, collidable, renderable, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	void Action() override { return; }
};

#endif