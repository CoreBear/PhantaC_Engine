#include "Test.h"

#include "GlobalTransform.h"
#include "ObjectManager.h"
#include "GlobalAutonomy.h"

void Test::Update()
{
	GlobalTransform::Translate(-velocity * GlobalTime::deltaTime, 0, 0, *myObject->GetTransform()->GetLocalMatrix());
	//if (targetPosition)
		//GlobalAutonomy::LookAt(myObject->GetTransform()->GetLocalMatrix(), targetPosition);
		//GlobalAutonomy::TurnTo(this, targetPosition);

	//GlobalTransform::RotateOnYAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
}