#pragma region Dependencies
// My Headers
#include "BulletTrail.h"		// Connection to declarations

#include "GlobalTime.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Update
void BulletTrail::Update()
{
	// Update how much time object has been in the scene
	timeAlive += GlobalTime::deltaTime;
	
	// If the object has lived longer than its lifetime
	// add to the container that will remove it at the end of the frame
	if (timeAlive > lifeTime)
		sceneGraphPtr->AddObjectToRemove(myObject);
}
#pragma endregion
