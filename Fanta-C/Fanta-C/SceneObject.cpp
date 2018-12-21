#pragma region Dependencies
// My Headers
#include "SceneObject.h"			// Connection to declarations

#include "Camera.h"
#include "ScriptManager.h"
#pragma endregion

#pragma region Forward Declarations
uint SceneObject::idCounter = 0;
#pragma endregion

#pragma region Initialization
SceneObject::SceneObject(SceneObject* camera) : active(true), collidable(false), logical(true), renderable(false), colliderManagerPtr(nullptr), meshPtr(nullptr)
{
	transformPtr = new Transform(static_cast<Camera*>(camera)->GetViewMatrix());

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
}
SceneObject::SceneObject(Mesh* inMesh, bool inActive, bool inCollidable, bool inLogical, bool inRenderable, const XMVECTOR& position) : active(inActive), collidable(inCollidable), logical(inLogical), renderable(inRenderable), meshPtr(inMesh)
{
	// Assign colliderManager
	colliderManagerPtr = (collidable) ? new ColliderManager(meshPtr->GetWidth(), meshPtr->GetHeight(), meshPtr->GetDepth(), meshPtr->GetScale()) : nullptr;

	// Assign transform
	transformPtr = new Transform(position);

	// Increment counter and store number for each object
	uniqueObjectID = idCounter++;
}
#pragma endregion

#pragma region Update
void SceneObject::Update()
{
	// Run every script for object
	for (objectIterator = 0; objectIterator < myScripts.size(); ++objectIterator)
		myScripts.at(objectIterator)->Update();
}
#pragma endregion

#pragma region Clean Up
SceneObject::~SceneObject()
{
	if (colliderManagerPtr)
	{
		delete colliderManagerPtr;
		colliderManagerPtr = nullptr;
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

	// Delete my scripts
	for (objectIterator = 0; objectIterator < myScripts.size(); ++objectIterator)
		if (myScripts.at(objectIterator)) { delete myScripts.at(objectIterator); }

	// Delete my children
	for (objectIterator = 0; objectIterator < myChildren.size(); ++objectIterator)
		if (myChildren.at(objectIterator)) { delete myChildren.at(objectIterator); }
}
#pragma endregion