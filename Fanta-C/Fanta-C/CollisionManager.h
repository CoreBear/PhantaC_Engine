#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "AutonomousAgent.h"

class CollisionManager
{
	std::vector<AutonomousAgent*> currentlyCollidingObjects;

public:
	// Accessors
	std::vector<AutonomousAgent*>* GetCurrentlyCollidingObjectContainerPtr() { return &currentlyCollidingObjects; }
};

#endif