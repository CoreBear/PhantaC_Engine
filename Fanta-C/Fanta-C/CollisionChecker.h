#ifndef _COLLISION_CHECKER_H
#define _COLLISION_CHECKER_H

// System Headers
#include <vector>

class CollisionChecker
{
	bool						noCollision;
	class ObjectTransform*		objectsBeingChecked[2];

public:
	// Update
	void Update(std::vector<class AutonomousAgent*>* autonomousAgents, std::vector<class Agent*>* staticAgents, std::vector<class Agent*>* currentlyCollidingObjects);
};

#endif