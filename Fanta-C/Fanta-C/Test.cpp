#include "Test.h"

#include "GlobalTransform.h"
#include "ObjectManager.h"

void Test::Update()
{
	GlobalTransform::Translate(velocity * GlobalTime::deltaTime, 0, 0, myObject->GetTransform()->GetWorldMatrix());
}