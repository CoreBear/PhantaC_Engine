#ifndef _ENEMY_BASE_H
#define _ENEMY_BASE_H

// My Headers
#include "AutonomousAgent.h"

class EnemyBase : public AutonomousAgent
{
public:
	// Initialization
	EnemyBase(ObjectTransform* inPhysicalBodyPtr, float inMoveSpeed, float inRotationSpeed) : AutonomousAgent(inPhysicalBodyPtr, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	void Action(float deltaTime) override;
	void Plan() override;
};

#endif