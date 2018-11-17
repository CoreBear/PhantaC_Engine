#include "Test.h"

#include "ObjectManager.h"

void Test::Update(float deltaTime)
{
	myObject->GetTransform()->Translate(1 * deltaTime, 0, 0);
}