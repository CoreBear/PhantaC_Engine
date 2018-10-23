#pragma region Dependencies
// My Headers
#include "Scene.h"			// Connection to declarations
#include "Agent.h"
#include "AutonomousAgent.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void Scene::Update(std::vector<Agent*>* agents)
{
	// Skip 1 for the camera right now
	/*for (iterators[0] = 1; iterators[0] < agents->size(); ++iterators[0])
		static_cast<AutonomousAgent*>(agents->at(iterators[0]))->Plan();*/
}
#pragma endregion