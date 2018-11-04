#pragma region Dependencies
// My Headers
#include "Agent.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
Agent::Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed, float inRotationSpeed) : transformPtr(transformPtr)
{
	// If agent has a collider
	colliderPtr = (collidable) ? new CollidableObject(transformPtr->GetFlatness(), transformPtr->GetScale()) : nullptr;

	// If agent has a renderer
	shapePtr = (renderable) ? static_cast<Shape*>(transformPtr) : nullptr;

	transformPtr->SetMoveSpeed(inMoveSpeed);
	transformPtr->SetRotationSpeed(inRotationSpeed);
}
#pragma endregion

#pragma region Clean Up
Agent::~Agent()
{
	if (colliderPtr)
	{
		delete colliderPtr;
		colliderPtr = nullptr;
	}
	if (shapePtr)
	{
		delete shapePtr;
		shapePtr = nullptr;
	}
}
#pragma endregion