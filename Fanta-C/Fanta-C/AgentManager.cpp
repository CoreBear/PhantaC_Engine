#pragma region Dependencies
// My Headers
#include "AgentManager.h"			// Connection to declarations

#include "GlobalAutonomy.h"
#include "GlobalTransform.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Update
void AgentManager::Update()
{
	#pragma region DO NOT TOUCH!!!
	// Runs collision logic updates on AgentManager.h
	// When collision occurs, use AgentManager.h to script what happens
	CollidingObject::Update();
	#pragma endregion

	//GlobalTransform::Translate(-velocity * GlobalTime::deltaTime, 0, 0, *myObject->GetTransform()->GetLocalMatrix());
	if (targetPosition)
		GlobalAutonomy::LookAt(myObject->GetTransform()->GetLocalMatrix(), targetPosition);
		//GlobalAutonomy::TurnTo(this, targetPosition);

	// Rotate
	//GlobalTransform::RotateOnXAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
	//GlobalTransform::RotateOnYAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
	GlobalTransform::Translate(0, 0, velocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
}
#pragma endregion