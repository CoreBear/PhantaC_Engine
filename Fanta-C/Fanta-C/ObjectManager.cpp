#pragma region Dependencies
// My Headers
#include "ObjectManager.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
uint ObjectManager::idCounter = 0;
#pragma endregion

#pragma region Initialization
ObjectManager::ObjectManager(Camera* camera) : meshPtr(camera)
{
	transformPtr = new Transform(camera->GetViewMatrix());

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
}
ObjectManager::ObjectManager(Mesh* inMesh, bool collidable, bool inRenderable, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : renderable(inRenderable), meshPtr(inMesh)
{
	// Assign colliderManager
	if (collidable) colliderManagerPtr = new ColliderManager(meshPtr->GetWidth(), meshPtr->GetHeight(), meshPtr->GetDepth(), meshPtr->GetScale());

	// Assign transform
	transformPtr = new Transform(position, forward, up);

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
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