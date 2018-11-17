#pragma region Dependencies
// My Headers
#include "ObjectManager.h"			// Connection to declaractions
#pragma endregion

#pragma region Initialization
ObjectManager::ObjectManager(Mesh* inMesh, bool camera, bool collidable, bool inRenderable, bool transformable, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : renderable(inRenderable), meshPtr(inMesh)
{
	if (collidable) colliderPtr = new Collider(meshPtr->GetFlatness(), meshPtr->GetScale());
	if (transformable) transformPtr = (!camera) ? new Transform(position) : new Transform(true, position, forward, up);
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