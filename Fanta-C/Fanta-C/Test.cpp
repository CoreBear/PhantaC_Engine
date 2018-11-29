#include "Test.h"

#include "GlobalTransform.h"
#include "ObjectManager.h"
#include "GlobalAutonomy.h"

void Test::Update()
{
	//GlobalTransform::Translate(0, 0, velocity * GlobalTime::deltaTime, *myObject->GetTransform()->GetWorldMatrix());
	if (targetPosition)
		//GlobalAutonomy::LookAt(myObject->GetTransform()->GetWorldMatrix(), targetPosition);
		GlobalAutonomy::TurnTo(this, targetPosition);
}