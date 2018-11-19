#pragma region Dependencies
// My Headers
#include "ObjectManager.h"			// Connection to declaractions
#pragma endregion

#pragma region Initialization
ObjectManager::ObjectManager(Mesh* inMesh, bool camera, bool collidable, bool inRenderable, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : renderable(inRenderable), meshPtr(inMesh)
{
	// Assign collider
	if (collidable) colliderPtr = new Collider(meshPtr->GetFlatness(), meshPtr->GetScale());	

	// Assign transform
	transformPtr = (!camera) ? new Transform(position) : new Transform(position, forward, up);
}
#pragma endregion

#pragma region Clean Up
ObjectManager::~ObjectManager()
{
	if (colliderPtr) delete colliderPtr;
	if (meshPtr) delete meshPtr;
	if (transformPtr) delete transformPtr;
}
#pragma endregion