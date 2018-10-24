#pragma region Dependencies
// My Headers
#include "Agent.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
Agent::Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed, float inRotationSpeed) : transformPtr(transformPtr)
{
	// If agent has a collider
	if (collidable) colliderPtr = new CollidableObject(transformPtr->GetFlatness(), transformPtr->GetScale());

	// If agent has a renderer
	if (renderable) shapePtr = static_cast<Shape*>(transformPtr);

	transformPtr->SetMoveSpeed(inMoveSpeed);
	transformPtr->SetRotationSpeed(inRotationSpeed);
}
#pragma endregion