#pragma region Dependencies
// My Headers
#include "ObjectManager.h"			// Connection to declaractions
#pragma endregion

#pragma region Initialization
ObjectManager::ObjectManager(Mesh* inMesh, bool collidable, bool inRenderable, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : renderable(inRenderable), meshPtr(inMesh)
{
	// Assign colliderManager
	//if (collidable) colliderManagerPtr = new ColliderManager(meshPtr->GetFlatness(), meshPtr->GetScale());
	if (collidable) colliderManagerPtr = new ColliderManager(meshPtr->GetWidth(), meshPtr->GetHeight(), meshPtr->GetDepth(), meshPtr->GetScale());

	// Assign transform
	transformPtr = new Transform(position, forward, up);
}
#pragma endregion

#pragma region Clean Up
ObjectManager::~ObjectManager()
{
	if (colliderManagerPtr) delete colliderManagerPtr;
	if (meshPtr) delete meshPtr;
	if (transformPtr) delete transformPtr;
}
#pragma endregion