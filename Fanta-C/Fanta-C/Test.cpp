#include "Test.h"

#include "GlobalTransform.h"
#include "ObjectManager.h"
#include "GlobalAutonomy.h"

void Test::Update()
{
	//GlobalTransform::Translate(0, 0, velocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
	//if (targetPosition)
		//GlobalAutonomy::LookAt(myObject->GetTransform()->GetLocalMatrix(), targetPosition);
		//GlobalAutonomy::TurnTo(this, targetPosition);

	GlobalTransform::RotateOnYAxis(angularVelocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetLocalMatrix());
}