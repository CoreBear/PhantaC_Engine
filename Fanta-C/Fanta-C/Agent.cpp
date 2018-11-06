#pragma region Dependencies
// My Headers
#include "Agent.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
Agent::Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed, float inRotationSpeed) : transformPtr(transformPtr)
{
	// If agent has a collider
	colliderPtr = (collidable) ? new Collider(transformPtr->GetFlatness(), transformPtr->GetScale()) : nullptr;

	// If agent has a rendererPtr
	meshPtr = (renderable) ? static_cast<Mesh*>(transformPtr) : nullptr;

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
	if (meshPtr)
	{
		delete meshPtr;
		meshPtr = nullptr;
	}
	if (transformPtr)
	{
		delete transformPtr;
		transformPtr = nullptr;
	}
}
#pragma endregion