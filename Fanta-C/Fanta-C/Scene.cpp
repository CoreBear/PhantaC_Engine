#pragma region Dependencies
// My Headers
#include "Scene.h"			// Connection to declarations
#include "AutonomousAgent.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void Scene::Update(std::vector<AutonomousAgent*>* agents)
{
	for (iterators[0] = 0; iterators[0] < agents->size(); ++iterators[0])
		agents->at(iterators[0])->Plan();
}
#pragma endregion