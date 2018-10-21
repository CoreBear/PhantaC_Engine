#pragma region Dependencies
// My Headers
#include "Scene.h"			// Connection to declarations
#include "Agent.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void Scene::Update(float deltaTime, std::vector<Agent*>* autonomousAgents)
{
	// Skip zero, becuase it is reserved for the camera
	for (iterators[0] = 1; iterators[0] < autonomousAgents->size(); ++iterators[0])
		autonomousAgents->at(iterators[0])->Update(deltaTime);
}
#pragma endregion