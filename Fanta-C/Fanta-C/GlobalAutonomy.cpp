#pragma region Dependencies
// My Headers
#include "GlobalAutonomy.h"			// Connection to declarations

#include "AgentManager.h"
#include "GlobalMath.h"
#include "GlobalTransform.h"
#include "GlobalWorldVariables.h"
#pragma endregion

#pragma region MyRegion
void GlobalAutonomy::LookAt(XMMATRIX* myMatrix, XMVECTOR* targetPosition)
{
	// Generate and normalize Z (forward)
	myMatrix->r[2] = *GlobalMath::VectorSubtraction(targetPosition, &myMatrix->r[3]);
	GlobalMath::Normalize(&myMatrix->r[2]);

	// Temp up for generating X (right)
	myMatrix->r[1] = GlobalWorldVariables::worldUp;

	// Generate and normalize X (right)
	myMatrix->r[0] = *GlobalMath::CrossProduct(&myMatrix->r[1], &myMatrix->r[2]);
	GlobalMath::Normalize(&myMatrix->r[0]);

	// Generate and normalize Y (up)
	myMatrix->r[1] = *GlobalMath::CrossProduct(&myMatrix->r[2], &myMatrix->r[0]);
	GlobalMath::Normalize(&myMatrix->r[1]);
}
void GlobalAutonomy::TurnTo(AgentManager* myMovingScript, XMVECTOR* targetPosition)
{
	myMatrix = myMovingScript->GetMyObject()->GetTransform()->GetLocalMatrix();

	// Direction to target
	targetVector = GlobalMath::VectorSubtraction(targetPosition, &myMatrix->r[3]);
	
	// Normilize direction
	GlobalMath::Normalize(targetVector);

	// Normalize X
	GlobalMath::Normalize(&myMatrix->r[0]);
	
	// Around the Y-Axis
	GlobalTransform::RotateOnWorldYAxis(myMovingScript->GetAngularVelocity() * -GlobalMath::Vector3DotProduct(targetVector, &myMatrix->r[0]), *myMatrix);

	// Normalize Y
	GlobalMath::Normalize(&myMatrix->r[1]);

	// Around the X-Axis
	GlobalTransform::RotateOnXAxis(myMovingScript->GetAngularVelocity() * -GlobalMath::Vector3DotProduct(targetVector, &myMatrix->r[1]), *myMatrix);
}
#pragma endregion
