#include "Test.h"

#include "GlobalTransform.h"
#include "ObjectManager.h"

void Test::Update()
{
	GlobalTransform::Translate(GlobalTime::deltaTime, 0, 0, myObject->GetTransform()->GetWorldMatrix());
}