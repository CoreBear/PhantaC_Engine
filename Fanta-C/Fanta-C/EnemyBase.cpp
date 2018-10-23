#pragma region Dependencies
// My Headers
#include "EnemyBase.h"			// Connection to declarations
#pragma endregion

#pragma region Planning
void EnemyBase::Plan()
{

}
#pragma endregion

#pragma region Actions
void EnemyBase::Action(float deltaTime)
{
	transformPtr->Translate(transformPtr->GetMoveSpeed() * deltaTime, 0, 0);
}
#pragma endregion
