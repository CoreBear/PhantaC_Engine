#pragma region Dependencies
// My Headers
#include "SceneObject.h"		// Connection to declarations

#include "ObjectManager.h"
#include "ScriptManager.h"
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
	// Delete my object
	if (object) { delete object; }

	// Delete my scripts
	for (objectIterator[1] = 0; objectIterator[1] < myScripts.size(); ++objectIterator[1])
		if (myScripts.at(objectIterator[1])) { delete myScripts.at(objectIterator[1]); }
	
	// Delete my children
	for (objectIterator[1] = 0; objectIterator[1] < myChildren.size(); ++objectIterator[1])
		if (myChildren.at(objectIterator[1])) { delete myChildren.at(objectIterator[1]); }
}
#pragma endregion
