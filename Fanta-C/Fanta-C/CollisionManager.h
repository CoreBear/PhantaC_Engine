#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class Agent;

class CollisionManager
{
	Agent*				agentBeingChecked[2];
	uchar				checkSize;
	float				collisionValues[4];
	std::vector<bool>	isColliding;

public:
	// Update
	void Update(std::vector<Agent*>* collidableObjects);
};

#endif