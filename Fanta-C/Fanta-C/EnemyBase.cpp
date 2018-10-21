#pragma region Dependencies
// My Headers
#include "EnemyBase.h"			// Connection to declarations
#pragma endregion

#pragma region Update
void EnemyBase::Update(float deltaTime)
{
	physicalBodyPtr->Translate(0, physicalBodyPtr->GetMoveSpeed() * deltaTime, 0);
}
#pragma endregion