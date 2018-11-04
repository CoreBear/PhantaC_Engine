#pragma region Dependencies
// My Headers
#include "PhysicsMain.h"			// Connection to declarations
#include "AutonomousAgent.h"
#include "ObjectTransform.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void PhysicsMain::Update(float deltaTime, std::vector<AutonomousAgent*>* autonomousAgents, std::vector<Agent*>* staticAgents)
{
	for (iterators[0] = 0; iterators[0] < autonomousAgents->size(); ++iterators[0])
		autonomousAgents->at(iterators[0])->Action(deltaTime);

	// Check for collisions
	collisionChecker.Update(autonomousAgents, staticAgents, collisionManager.GetCurrentlyCollidingObjectContainerPtr());
}
#pragma endregion