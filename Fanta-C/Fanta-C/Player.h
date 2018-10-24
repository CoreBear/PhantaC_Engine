#ifndef _PLAYER_H
#define _PLAYER_H

// My Headers
#include "Agent.h"

class Player : public Agent
{
public:
	// Initialization
	Player(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed, float inRotationSpeed) : Agent(transformPtr, collidable, renderable, inMoveSpeed, inRotationSpeed) { return; }

	// Public Interface
	void ControllerInput(ushort key, float deltaTime);
};

#endif