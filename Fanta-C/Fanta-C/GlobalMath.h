#ifndef _GLOBAL_MATH_H
#define _GLOBAL_MATH_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"


class GlobalMath
{
	static float		dotProduct;
	static float		normValue;
	static XMMATRIX*	tempMatrix;
	static XMVECTOR*	tempVector;

public:
		// Public Interface
	static float AbsoluteValue(float value);
	static XMVECTOR* CrossProduct(XMVECTOR* firstVector, XMVECTOR* secondVector);
	static float Lerp(float min, float max, float length);
	static XMMATRIX* MatrixMultiplication(XMMATRIX* movingMatrix, XMMATRIX* intoMatrix);
	static void Normalize(XMVECTOR* inVector);
	template<typename Generic> static Generic Square(Generic value);
	static float Vector3DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector);
	static float Vector4DotProduct(XMVECTOR* firstVector, XMVECTOR* secondVector);
	static XMVECTOR* VectorSubtraction(XMVECTOR* firstVector, XMVECTOR* secondVector);
};

#endif