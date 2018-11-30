#pragma region Dependencies
// My Headers
#include "GlobalTransform.h"		// Connection to declarations

#include "ColliderManager.h"
#pragma endregion

#pragma region Global Variables
XMMATRIX GlobalTransform::transformMatrix;
XMVECTOR GlobalTransform::translationVector;
#pragma endregion

#pragma region Public Interface
void GlobalTransform::RotateOnWorldXAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[1] = -transformMatrix.r[1].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[1].m128_f32[1];
	inLocalMatrix = XMMatrixMultiply(inLocalMatrix, transformMatrix);
}
void GlobalTransform::RotateOnWorldYAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[0] = -transformMatrix.r[0].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[0].m128_f32[0];
	inLocalMatrix = XMMatrixMultiply(inLocalMatrix, transformMatrix);
}
void GlobalTransform::RotateOnWorldZAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[0] = -transformMatrix.r[0].m128_f32[1];
	transformMatrix.r[1].m128_f32[1] = transformMatrix.r[0].m128_f32[0];
	inLocalMatrix = XMMatrixMultiply(inLocalMatrix, transformMatrix);
}
void GlobalTransform::RotateOnXAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[1] = -transformMatrix.r[1].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[1].m128_f32[1];
	inLocalMatrix = XMMatrixMultiply(transformMatrix, inLocalMatrix);
}
void GlobalTransform::RotateOnYAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[0] = -transformMatrix.r[0].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[0].m128_f32[0];
	inLocalMatrix = XMMatrixMultiply(transformMatrix, inLocalMatrix);
}
void GlobalTransform::RotateOnZAxis(float angle, XMMATRIX& inLocalMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[0] = -transformMatrix.r[0].m128_f32[1];
	transformMatrix.r[1].m128_f32[1] = transformMatrix.r[0].m128_f32[0];
	inLocalMatrix = XMMatrixMultiply(transformMatrix, inLocalMatrix);
}
void GlobalTransform::Scale(float x, float y, float z, ColliderManager* colliderManager, XMMATRIX& inLocalMatrix)
{
	// Update colliderManager extents
	colliderManager->GetBoundingBox()->SetExtents(x, y, z);

	// Update mesh vertices
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0] *= x;
	transformMatrix.r[1] *= y;
	transformMatrix.r[2] *= z;
	inLocalMatrix = XMMatrixMultiply(transformMatrix, inLocalMatrix);
}
void GlobalTransform::Translate(float x, float y, float z, XMMATRIX& inLocalMatrix)
{
	inLocalMatrix.r[3].m128_f32[0] += x;
	inLocalMatrix.r[3].m128_f32[1] += y;
	inLocalMatrix.r[3].m128_f32[2] += z;
}
void GlobalTransform::UniformScale(float value, ColliderManager* colliderManager, XMMATRIX& inLocalMatrix)
{
	// Update colliderManager extents
	colliderManager->GetBoundingBox()->SetExtents(value, value, value);

	// Update mesh vertices
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0] *= value;
	transformMatrix.r[1] *= value;
	transformMatrix.r[2] *= value;
	inLocalMatrix = XMMatrixMultiply(transformMatrix, inLocalMatrix);
}
#pragma endregion