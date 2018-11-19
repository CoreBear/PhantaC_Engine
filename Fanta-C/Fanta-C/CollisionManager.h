#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

// System Headers
#include <vector>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

class CollisionManager
{
	bool					isColliding;
	class ObjectManager*	objectsBeingChecked[2];
	ushort					collisionIterators[4];
	XMVECTOR				min[2];						
	XMVECTOR				max[2];

public:
	// Update
	void Update(std::vector<class ObjectManager*>* collidableObjects);
};

#endif