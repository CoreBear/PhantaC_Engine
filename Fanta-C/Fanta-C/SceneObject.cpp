#pragma region Dependencies
// My Headers
#include "SceneObject.h"			// Connection to declarations

#include "ScriptManager.h"
#pragma endregion

#pragma region Forward Declarations
uint SceneObject::idCounter = 0;
#pragma endregion

#pragma region Initialization
SceneObject::SceneObject(Camera* camera) : meshPtr(camera)
{
	transformPtr = new Transform(camera->GetViewMatrix());

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
}
SceneObject::SceneObject(Mesh* inMesh, bool collidable, bool inRenderable, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : renderable(inRenderable), meshPtr(inMesh)
{
	// Assign colliderManager
	colliderManagerPtr = (collidable) ? new ColliderManager(meshPtr->GetWidth(), meshPtr->GetHeight(), meshPtr->GetDepth(), meshPtr->GetScale()) : nullptr;

	// Assign transform
	transformPtr = new Transform(position, forward, up);

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
}
#pragma endregion

#pragma region Update
void SceneObject::Update()
{
	// Run every script for object
	for (objectIterator[0] = 0; objectIterator[0] < myScripts.size(); ++objectIterator[0])
		myScripts.at(objectIterator[0])->Update();
}
#pragma endregion

#pragma region Clean Up
SceneObject::~SceneObject()
{
	if (colliderManagerPtr) delete colliderManagerPtr;
	if (meshPtr) delete meshPtr;
	if (transformPtr) delete transformPtr;

	// Delete my scripts
	for (objectIterator[1] = 0; objectIterator[1] < myScripts.size(); ++objectIterator[1])
		if (myScripts.at(objectIterator[1])) { delete myScripts.at(objectIterator[1]); }

	// Delete my children
	for (objectIterator[1] = 0; objectIterator[1] < myChildren.size(); ++objectIterator[1])
		if (myChildren.at(objectIterator[1])) { delete myChildren.at(objectIterator[1]); }
}
#pragma endregion