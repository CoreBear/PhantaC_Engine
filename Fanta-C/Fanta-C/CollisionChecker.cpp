#pragma region Dependencies
// My Headers
#include "CollisionChecker.h"			// Connection to declarations
#include "Agent.h"
#include "ObjectTransform.h"
#include "GlobalApplication.h"
#include "GlobalTools.h"
#pragma endregion

#pragma region Update
void CollisionChecker::Update(std::vector<Agent*>* autonomousAgents, std::vector<Agent*>* staticAgents, std::vector<Agent*>* currentlyCollidingObjects)
{
	//// Check each agent's collision (Collider)
	//for (iterators[0] = 0; iterators[0] < autonomousAgents->size(); ++iterators[0])
	//{
	//	// Setting the collider
	//	objectsBeingChecked[0] = static_cast<ObjectTransform*>(autonomousAgents->at(iterators[0])->GetTransformPtr());

	//	// Against every other agent (Collidee)
	//	for (iterators[1] = 0; iterators[1] < autonomousAgents->size(); ++iterators[1])
	//	{
	//		// If collidee not the same as collider
	//		if (iterators[1] != iterators[0])
	//		{
	//			// Setting the collidee
	//			objectsBeingChecked[1] = static_cast<ObjectTransform*>(autonomousAgents->at(iterators[1])->GetTransformPtr());

	//			// Reset for possible collision
	//			noCollision = false;

	//			// XYZ Separation
	//			for (iterators[2] = 0; iterators[2] < 3; ++iterators[2])
	//			{

	//				// Just looking for a non-collision. If this is true, no collision. Break out of loop
	//				// 1) If collider's max is less than collidee's min
	//				// 2) Or if collider's min is greater than collidee's max
	//				//if (objectsBeingChecked[0]->GetPosition().m128_f32[iterators[2]] + objectsBeingChecked[0]->GetExtents().m128_f32[iterators[2]] <
	//				//	objectsBeingChecked[1]->GetPosition().m128_f32[iterators[2]] - objectsBeingChecked[1]->GetExtents().m128_f32[iterators[2]] ||
	//				//	objectsBeingChecked[0]->GetPosition().m128_f32[iterators[2]] - objectsBeingChecked[0]->GetExtents().m128_f32[iterators[2]] >
	//				//	objectsBeingChecked[1]->GetPosition().m128_f32[iterators[2]] + objectsBeingChecked[1]->GetExtents().m128_f32[iterators[2]])
	//				//{
	//				//	noCollision = true;
	//				//	break;
	//				//}
	//			}

	//			// If collision
	//			if (!noCollision)
	//			{
	//				// If agent is not colliding
	//				//if (!autonomousAgents->at(iterators[0])->GetColliding())
	//				//{
	//				//	// Agent is now colliding
	//				//	//autonomousAgents->at(iterators[0])->ToggleColliding();

	//				//	// Add agent to container
	//				//	AddObjectToContainer<AutonomousAgent*>(currentlyCollidingObjects, autonomousAgents->at(iterators[0]));
	//				//}
	//			}

	//			// If no collision
	//			else
	//			{
	//				// If agent is colliding
	//				//if (autonomousAgents->at(iterators[0])->GetColliding())
	//				//{
	//				//	// Remove agent from container
	//				//	//RemoveObjectFromContainer<AutonomousAgent*>(currentlyCollidingObjects, autonomousAgents->at(iterators[0]));

	//				//	// Agent is now not colliding
	//				//	autonomousAgents->at(iterators[0])->ToggleColliding();
	//				//}
	//			}
	//		}			
	//	}
	//}
}
#pragma endregion