#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "Agent.h"

class CollisionManager
{
	std::vector<Agent*> currentlyCollidingObjects;

public:
	// Accessors
	std::vector<Agent*>* GetCurrentlyCollidingObjectContainerPtr() { return &currentlyCollidingObjects; }
};

#endif