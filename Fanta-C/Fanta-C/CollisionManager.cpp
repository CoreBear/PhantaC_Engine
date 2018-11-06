#pragma region Dependencies
// My Headers
#include "CollisionManager.h"			// Connection to declarations
#include "Agent.h"
#include "GlobalIterators.h"
#include "GlobalContainers.h"
#pragma endregion

#pragma region Update
void CollisionManager::Update(std::vector<Agent*>* collidableObjects)
{
	//// Resize collision checks to accomodate the number of agents
	//if (collidableObjects->size() > isColliding.size())
	//{
	//	isColliding.resize(collidableObjects->size());
	//	checkSize = collidableObjects->size();
	//}
	//
	//// Check each agent's collision (Collider)
	//for (iterators[0] = 0; iterators[0] < checkSize; ++iterators[0])
	//{
	//	// Setting the collider
	//	agentBeingChecked[0] = collidableObjects->at(iterators[0]);
	//
	//	// Set collision to true for this agent (The goal is to disprove the collision)
	//	isColliding[iterators[0]] = true;
	//
	//	// Against every other agent (Collidee)
	//	for (iterators[1] = 0; iterators[1] < checkSize; ++iterators[1])
	//	{
	//		// If collidee not the same as collider
	//		if (iterators[1] != iterators[0])
	//		{
	//			// Setting the collidee
	//			agentBeingChecked[1] = collidableObjects->at(iterators[1]);
	//	
	//			// XYZ Separation
	//			for (iterators[2] = 0; iterators[2] < 3; ++iterators[2])
	//			{	
	//				// Just looking for a non-collision. If this is true, no collision. Break out of loop
	//				// 1) If collider's max is less than collidee's min
	//				// 2) Or if collider's min is greater than collidee's max
	//
	//				// Collider position
	//				collisionValues[0] = agentBeingChecked[0]->GetTransformPtr()->GetPosition().m128_f32[iterators[2]];
	//				
	//				// Collidee position
	//				collisionValues[1] = agentBeingChecked[1]->GetTransformPtr()->GetPosition().m128_f32[iterators[2]];
	//				
	//				// Collider extents
	//				collisionValues[2] = agentBeingChecked[0]->GetColliderPtr()->GetExtents().m128_f32[iterators[2]];
	//			
	//				// Collidee extents
	//				collisionValues[3] = agentBeingChecked[1]->GetColliderPtr()->GetExtents().m128_f32[iterators[2]];
	//				
	//				if (collisionValues[0] + collisionValues[2] < collisionValues[1] - collisionValues[3] ||
	//					collisionValues[0] - collisionValues[2] > collisionValues[1] + collisionValues[3])
	//				{
	//					// No collision
	//					isColliding[iterators[0]] = false;
	//					break;
	//				
	//			}
	//		}
	//	}
	//}
}
#pragma endregion