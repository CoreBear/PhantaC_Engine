#pragma region Dependencies
// My Headers
#include "EventHandler.h"		// Connection to declarations

#include "GlobalEventVariables.h"
#include "ObjectManager.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Public Interface
void EventHandler::HandleEvent(uchar eventType, SceneObject* collider, SceneObject* collidee)
{
	switch (eventType)
	{
	case GlobalEventVariables::EVENT::CONTINUED_COLLISION:
		ContinuedCollision(collider, collidee);
		break;
	case GlobalEventVariables::EVENT::NEW_COLLISION:
		NewCollision(collider, collidee);
		break;
	case GlobalEventVariables::EVENT::NEW_SEPARATION:
		NewSeparation(collider, collidee);
		break;
	}
}
#pragma endregion

#pragma region Private
void EventHandler::ContinuedCollision(SceneObject* collider, SceneObject* collidee)
{

}
void EventHandler::NewCollision(SceneObject* collider, SceneObject* collidee)
{
	// Change collider's color
	collider->GetMyObject()->GetMesh()->ChangeColor(Colors::Red);
}
void EventHandler::NewSeparation(SceneObject* collider, SceneObject* collidee)
{
	// Change collider's color
	collider->GetMyObject()->GetMesh()->ChangeColor(Colors::Green);
}
#pragma endregion
