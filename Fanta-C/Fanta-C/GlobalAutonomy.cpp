#pragma region Dependencies
// My Headers
#include "GlobalAutonomy.h"			// Connection to declarations

#include "GlobalMath.h"
#include "GlobalTransform.h"
#include "MovingObject.h"
#pragma endregion

#pragma region MyRegion
void GlobalAutonomy::LookAt(XMMATRIX* myMatrix, XMVECTOR* targetPosition)
{
	// Generate and normalize Z (forward)
	myMatrix->r[2] = XMVectorSubtract(*targetPosition, myMatrix->r[3]);
	myMatrix->r[2] = XMVector3Normalize(myMatrix->r[2]);

	// Temp up for generating X (right)
	myMatrix->r[1] = worldUp;

	// Generate and normalize X (right)
	myMatrix->r[0] = XMVector3Cross(myMatrix->r[1], myMatrix->r[2]);
	myMatrix->r[0] = XMVector3Normalize(myMatrix->r[0]);

	// Generate and normalize Y (up)
	myMatrix->r[1] = XMVector3Cross(myMatrix->r[2], myMatrix->r[0]);
	myMatrix->r[1] = XMVector3Normalize(myMatrix->r[1]);
}
void GlobalAutonomy::TurnTo(MovingObject* myMovingScript, XMVECTOR* targetPosition)
{
	myMatrix = myMovingScript->GetMyObject()->GetTransform()->GetLocalMatrix();

	// Direction to target
	targetVector = XMVectorSubtract(*targetPosition, myMatrix->r[3]);
	
	// Normilize direction
	targetVector = XMVector3Normalize(targetVector);

	// Normalize X
	myMatrix->r[0] = XMVector3Normalize(myMatrix->r[0]);
	
	// Around the Y-Axis
	GlobalTransform::RotateOnYAxis(myMovingScript->GetAngularVelocity() * -GlobalMath::Vector4DotProduct(targetVector, myMatrix->r[0]), *myMatrix);

	// Normalize Y
	myMatrix->r[1] = XMVector3Normalize(myMatrix->r[1]);

	// Around the X-Axis
	GlobalTransform::RotateOnXAxis(myMovingScript->GetAngularVelocity() * -GlobalMath::Vector4DotProduct(targetVector, myMatrix->r[1]), *myMatrix);
}
#pragma endregion
