#pragma region Dependencies
// My Headers
#include "GlobalMath.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
float GlobalMath::toDegreesPI = XM_PI / 180.0f;
float GlobalMath::toRadiansPI = 180.0f / XM_PI;
float GlobalMath::dotProduct = 0;
float GlobalMath::normValue = 0;
XMMATRIX* GlobalMath::tempMatrix = &XMMatrixIdentity();
XMVECTOR* GlobalMath::tempVector = &XMVectorZero();
#pragma endregion

#pragma region Public Interface
float GlobalMath::ConvertToDegrees(float degrees) { return degrees * toDegreesPI; }
float GlobalMath::ConvertToRadians(float degrees) { return degrees * toRadiansPI; }
XMVECTOR* GlobalMath::CrossProduct(XMVECTOR* firstVector, XMVECTOR* secondVector)
{
	tempVector->m128_f32[0] = (firstVector->m128_f32[1] * secondVector->m128_f32[2]) - (firstVector->m128_f32[2] * secondVector->m128_f32[1]);
	tempVector->m128_f32[1] = (firstVector->m128_f32[2] * secondVector->m128_f32[0]) - (firstVector->m128_f32[0] * secondVector->m128_f32[2]);
	tempVector->m128_f32[2] = (firstVector->m128_f32[0] * secondVector->m128_f32[1]) - (firstVector->m128_f32[1] * secondVector->m128_f32[0]);

	return tempVector;
}
XMMATRIX* GlobalMath::FastInverse(XMMATRIX* inMatrix)
{
	// Transpose the 3X3
	// X-Axis
	tempMatrix->r[0].m128_f32[0] = inMatrix->r[0].m128_f32[0];
	tempMatrix->r[0].m128_f32[1] = inMatrix->r[1].m128_f32[0];
	tempMatrix->r[0].m128_f32[2] = inMatrix->r[2].m128_f32[0];
								   
	// Y-Axis					   
	tempMatrix->r[1].m128_f32[0] = inMatrix->r[0].m128_f32[1];
	tempMatrix->r[1].m128_f32[1] = inMatrix->r[1].m128_f32[1];
	tempMatrix->r[1].m128_f32[2] = inMatrix->r[2].m128_f32[1];
								   
	// Z-Axis					   
	tempMatrix->r[2].m128_f32[0] = inMatrix->r[0].m128_f32[2];
	tempMatrix->r[2].m128_f32[1] = inMatrix->r[1].m128_f32[2];
	tempMatrix->r[2].m128_f32[2] = inMatrix->r[2].m128_f32[2];

	// Multiplying position    X															Y																Z
	tempVector->m128_f32[0] = (tempMatrix->r[0].m128_f32[0] * inMatrix->r[3].m128_f32[0]) + (tempMatrix->r[0].m128_f32[1] * inMatrix->r[3].m128_f32[0]) + (tempMatrix->r[0].m128_f32[2] * inMatrix->r[3].m128_f32[0]);
	tempVector->m128_f32[1] = (tempMatrix->r[1].m128_f32[0] * inMatrix->r[3].m128_f32[1]) + (tempMatrix->r[1].m128_f32[1] * inMatrix->r[3].m128_f32[1]) + (tempMatrix->r[1].m128_f32[2] * inMatrix->r[3].m128_f32[1]);
	tempVector->m128_f32[2] = (tempMatrix->r[2].m128_f32[0] * inMatrix->r[3].m128_f32[2]) + (tempMatrix->r[2].m128_f32[1] * inMatrix->r[3].m128_f32[2]) + (tempMatrix->r[2].m128_f32[2] * inMatrix->r[3].m128_f32[2]);

	// Negate vector
	tempVector->m128_f32[0] = -tempVector->m128_f32[0];
	tempVector->m128_f32[1] = -tempVector->m128_f32[1];
	tempVector->m128_f32[2] = -tempVector->m128_f32[2];

	// Apply position
	inMatrix->r[3].m128_f32[0] = tempVector->m128_f32[0];
	inMatrix->r[3].m128_f32[1] = tempVector->m128_f32[1];
	inMatrix->r[3].m128_f32[2] = tempVector->m128_f32[2];

	return inMatrix;
}
XMMATRIX* GlobalMath::MatrixMultiplication(XMMATRIX* movingMatrix, XMMATRIX* intoMatrix)
{
	// X-Axis
	tempMatrix->r[0].m128_f32[0] = (movingMatrix->r[0].m128_f32[0] * intoMatrix->r[0].m128_f32[0]) + (movingMatrix->r[0].m128_f32[1] * intoMatrix->r[1].m128_f32[0]) + (movingMatrix->r[0].m128_f32[2] * intoMatrix->r[2].m128_f32[0]) + (movingMatrix->r[0].m128_f32[3] * intoMatrix->r[3].m128_f32[0]);
	tempMatrix->r[0].m128_f32[1] = (movingMatrix->r[0].m128_f32[0] * intoMatrix->r[0].m128_f32[1]) + (movingMatrix->r[0].m128_f32[1] * intoMatrix->r[1].m128_f32[1]) + (movingMatrix->r[0].m128_f32[2] * intoMatrix->r[2].m128_f32[1]) + (movingMatrix->r[0].m128_f32[3] * intoMatrix->r[3].m128_f32[1]);
	tempMatrix->r[0].m128_f32[2] = (movingMatrix->r[0].m128_f32[0] * intoMatrix->r[0].m128_f32[2]) + (movingMatrix->r[0].m128_f32[1] * intoMatrix->r[1].m128_f32[2]) + (movingMatrix->r[0].m128_f32[2] * intoMatrix->r[2].m128_f32[2]) + (movingMatrix->r[0].m128_f32[3] * intoMatrix->r[3].m128_f32[2]);
	tempMatrix->r[0].m128_f32[3] = (movingMatrix->r[0].m128_f32[0] * intoMatrix->r[0].m128_f32[3]) + (movingMatrix->r[0].m128_f32[1] * intoMatrix->r[1].m128_f32[3]) + (movingMatrix->r[0].m128_f32[2] * intoMatrix->r[2].m128_f32[3]) + (movingMatrix->r[0].m128_f32[3] * intoMatrix->r[3].m128_f32[3]);
	
	// Y-Axis
	tempMatrix->r[1].m128_f32[0] = (movingMatrix->r[1].m128_f32[0] * intoMatrix->r[0].m128_f32[0]) + (movingMatrix->r[1].m128_f32[1] * intoMatrix->r[1].m128_f32[0]) + (movingMatrix->r[1].m128_f32[2] * intoMatrix->r[2].m128_f32[0]) + (movingMatrix->r[1].m128_f32[3] * intoMatrix->r[3].m128_f32[0]);
	tempMatrix->r[1].m128_f32[1] = (movingMatrix->r[1].m128_f32[0] * intoMatrix->r[0].m128_f32[1]) + (movingMatrix->r[1].m128_f32[1] * intoMatrix->r[1].m128_f32[1]) + (movingMatrix->r[1].m128_f32[2] * intoMatrix->r[2].m128_f32[1]) + (movingMatrix->r[1].m128_f32[3] * intoMatrix->r[3].m128_f32[1]);
	tempMatrix->r[1].m128_f32[2] = (movingMatrix->r[1].m128_f32[0] * intoMatrix->r[0].m128_f32[2]) + (movingMatrix->r[1].m128_f32[1] * intoMatrix->r[1].m128_f32[2]) + (movingMatrix->r[1].m128_f32[2] * intoMatrix->r[2].m128_f32[2]) + (movingMatrix->r[1].m128_f32[3] * intoMatrix->r[3].m128_f32[2]);
	tempMatrix->r[1].m128_f32[3] = (movingMatrix->r[1].m128_f32[0] * intoMatrix->r[0].m128_f32[3]) + (movingMatrix->r[1].m128_f32[1] * intoMatrix->r[1].m128_f32[3]) + (movingMatrix->r[1].m128_f32[2] * intoMatrix->r[2].m128_f32[3]) + (movingMatrix->r[1].m128_f32[3] * intoMatrix->r[3].m128_f32[3]);
	
	// Z-Axis
	tempMatrix->r[2].m128_f32[0] = (movingMatrix->r[2].m128_f32[0] * intoMatrix->r[0].m128_f32[0]) + (movingMatrix->r[2].m128_f32[1] * intoMatrix->r[1].m128_f32[0]) + (movingMatrix->r[2].m128_f32[2] * intoMatrix->r[2].m128_f32[0]) + (movingMatrix->r[2].m128_f32[3] * intoMatrix->r[3].m128_f32[0]);
	tempMatrix->r[2].m128_f32[1] = (movingMatrix->r[2].m128_f32[0] * intoMatrix->r[0].m128_f32[1]) + (movingMatrix->r[2].m128_f32[1] * intoMatrix->r[1].m128_f32[1]) + (movingMatrix->r[2].m128_f32[2] * intoMatrix->r[2].m128_f32[1]) + (movingMatrix->r[2].m128_f32[3] * intoMatrix->r[3].m128_f32[1]);
	tempMatrix->r[2].m128_f32[2] = (movingMatrix->r[2].m128_f32[0] * intoMatrix->r[0].m128_f32[2]) + (movingMatrix->r[2].m128_f32[1] * intoMatrix->r[1].m128_f32[2]) + (movingMatrix->r[2].m128_f32[2] * intoMatrix->r[2].m128_f32[2]) + (movingMatrix->r[2].m128_f32[3] * intoMatrix->r[3].m128_f32[2]);
	tempMatrix->r[2].m128_f32[3] = (movingMatrix->r[2].m128_f32[0] * intoMatrix->r[0].m128_f32[3]) + (movingMatrix->r[2].m128_f32[1] * intoMatrix->r[1].m128_f32[3]) + (movingMatrix->r[2].m128_f32[2] * intoMatrix->r[2].m128_f32[3]) + (movingMatrix->r[2].m128_f32[3] * intoMatrix->r[3].m128_f32[3]);
	
	// Translation-Axis
	tempMatrix->r[3].m128_f32[0] = (movingMatrix->r[3].m128_f32[0] * intoMatrix->r[0].m128_f32[0]) + (movingMatrix->r[3].m128_f32[1] * intoMatrix->r[1].m128_f32[0]) + (movingMatrix->r[3].m128_f32[2] * intoMatrix->r[2].m128_f32[0]) + (movingMatrix->r[3].m128_f32[3] * intoMatrix->r[3].m128_f32[0]);
	tempMatrix->r[3].m128_f32[1] = (movingMatrix->r[3].m128_f32[0] * intoMatrix->r[0].m128_f32[1]) + (movingMatrix->r[3].m128_f32[1] * intoMatrix->r[1].m128_f32[1]) + (movingMatrix->r[3].m128_f32[2] * intoMatrix->r[2].m128_f32[1]) + (movingMatrix->r[3].m128_f32[3] * intoMatrix->r[3].m128_f32[1]);
	tempMatrix->r[3].m128_f32[2] = (movingMatrix->r[3].m128_f32[0] * intoMatrix->r[0].m128_f32[2]) + (movingMatrix->r[3].m128_f32[1] * intoMatrix->r[1].m128_f32[2]) + (movingMatrix->r[3].m128_f32[2] * intoMatrix->r[2].m128_f32[2]) + (movingMatrix->r[3].m128_f32[3] * intoMatrix->r[3].m128_f32[2]);
	tempMatrix->r[3].m128_f32[3] = (movingMatrix->r[3].m128_f32[0] * intoMatrix->r[0].m128_f32[3]) + (movingMatrix->r[3].m128_f32[1] * intoMatrix->r[1].m128_f32[3]) + (movingMatrix->r[3].m128_f32[2] * intoMatrix->r[2].m128_f32[3]) + (movingMatrix->r[3].m128_f32[3] * intoMatrix->r[3].m128_f32[3]);

	return tempMatrix;
}
void GlobalMath::Normalize(XMVECTOR* inVector)
{
	normValue = 0;

	normValue += inVector->m128_f32[0] * inVector->m128_f32[0];
	normValue += inVector->m128_f32[1] * inVector->m128_f32[1];
	normValue += inVector->m128_f32[2] * inVector->m128_f32[2];
	
	normValue = sqrtf(normValue);

	inVector->m128_f32[0] /= normValue;
	inVector->m128_f32[1] /= normValue;
	inVector->m128_f32[2] /= normValue;
}
template<typename Generic> Generic GlobalMath::Square(Generic value)
{
	return value * value;
}
float GlobalMath::Vector3DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector)
{
	dotProduct = 0;

	dotProduct += firstVector->m128_f32[0] * secondVector->m128_f32[0];
	dotProduct += firstVector->m128_f32[1] * secondVector->m128_f32[1];
	dotProduct += firstVector->m128_f32[2] * secondVector->m128_f32[2];

	return dotProduct;
}
XMVECTOR* GlobalMath::VectorSubtraction(XMVECTOR* endPoint, XMVECTOR* startPoint)
{
	tempVector->m128_f32[0] = endPoint->m128_f32[0] - startPoint->m128_f32[0];
	tempVector->m128_f32[1] = endPoint->m128_f32[1] - startPoint->m128_f32[1];
	tempVector->m128_f32[2] = endPoint->m128_f32[2] - startPoint->m128_f32[2];
	tempVector->m128_f32[3] = 0;

	return tempVector;
}

#pragma endregion