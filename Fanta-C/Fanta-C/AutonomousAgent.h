#ifndef _AUTONOMOUS_AGENT_H
#define _AUTONOMOUS_AGENT_H

// My Headers
#include "Agent.h"

class AutonomousAgent : public Agent
{
public:
	// Initialization
	AutonomousAgent(ObjectTransform* inPhysicalBodyPtr, float inMoveSpeed, float inRotationSpeed) : Agent(inPhysicalBodyPtr, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	virtual void Action(float deltaTime) { return; }
	void Plan() override { return; }
};

#endif