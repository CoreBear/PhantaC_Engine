#ifndef _PHYSICS_MAIN_H
#define _PHYSICS_MAIN_H

// System Headers
#include <vector>

// My Headers
#include "CollisionChecker.h"
#include "CollisionManager.h"

class PhysicsMain
{
	CollisionChecker collisionChecker;
	CollisionManager collisionManager;

public:
	// Update
	void Update(float deltaTime, std::vector<class AutonomousAgent*>* autonomousAgents, std::vector<class Agent*>* staticAgents);
};

#endif