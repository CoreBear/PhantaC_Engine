#ifndef _COLLISION_CHECKER_H
#define _COLLISION_CHECKER_H

// System Headers
#include <vector>

class CollisionChecker
{
	bool						noCollision;
	class CollidableObject*		objectsBeingChecked[2];

public:
	// Update
	void Update(std::vector<class AutonomousAgent*>* agents, std::vector<class AutonomousAgent*>* currentlyCollidingObjects);
};

#endif