#ifndef _AUTONOMOUS_AGENT_H
#define _AUTONOMOUS_AGENT_H

// My Headers
#include "Agent.h"

class AutonomousAgent : public Agent
{
public:
	// Initialization
	AutonomousAgent(ObjectTransform* intransformPtr, bool collider, bool renderer, float inMoveSpeed, float inRotationSpeed) : Agent(intransformPtr, collider, renderer, inMoveSpeed, inRotationSpeed) { return; }

	// Update
	virtual void Action(float deltaTime) = 0;
	virtual void Plan() { return; }
};

#endif