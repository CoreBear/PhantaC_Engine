#ifndef _PLAYER_H
#define _PLAYER_H

// My Headers
#include "Agent.h"

class Player : public Agent
{
public:
	// Initialization
	Player(ObjectTransform* physicalBodyPtr, float inMoveSpeed, float inRotationSpeed) : Agent(physicalBodyPtr, inMoveSpeed, inRotationSpeed) { return; }

	// Public Interface
	void ControllerInput(ushort key, float deltaTime);
};

#endif