#ifndef _GLOBAL_TRANSFORM_H
#define _GLOBAL_TRANSFORM_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class ColliderManager;

class GlobalTransform
{
	static XMMATRIX transformMatrix;
	static XMVECTOR translationVector;

public:
	static void RotateOnWorldXAxis(float angle, XMMATRIX& inLocalMatrix);
	static void RotateOnWorldYAxis(float angle, XMMATRIX& inLocalMatrix);
	static void RotateOnWorldZAxis(float angle, XMMATRIX& inLocalMatrix);
	static void RotateOnZAxis(float angle, XMMATRIX& inLocalMatrix);
	static void RotateOnXAxis(float angle, XMMATRIX& inLocalMatrix);
	static void RotateOnYAxis(float angle, XMMATRIX& inLocalMatrix);
	static void Scale(float x, float y, float z, ColliderManager* colliderManager, XMMATRIX& inLocalMatrix);
	static void Translate(float x, float y, float z, XMMATRIX& inLocalMatrix);
	static void UniformScale(float value, ColliderManager* colliderManager, XMMATRIX& inLocalMatrix);
	//static void WorldTranslate(ushort index, float speed, XMMATRIX* inLocalMatrix);
};

#endif