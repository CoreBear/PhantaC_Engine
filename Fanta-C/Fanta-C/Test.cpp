#include "Test.h"

#include "GlobalAutonomy.h"
#include "GlobalTransform.h"
#include "ObjectManager.h"
#include "SceneObject.h"


void Test::Update()
{
	//GlobalTransform::Translate(-velocity * GlobalTime::deltaTime, 0, 0, *myObject->GetMyObject()->GetTransform()->GetLocalMatrix());
	//if (targetPosition)
		//GlobalAutonomy::LookAt(myObject->GetTransform()->GetLocalMatrix(), targetPosition);
		//GlobalAutonomy::TurnTo(this, targetPosition);

	// Rotate
	GlobalTransform::RotateOnXAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetMyObject()->GetTransform()->GetLocalMatrix());
	GlobalTransform::RotateOnYAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetMyObject()->GetTransform()->GetLocalMatrix());
}