#ifndef _GLOBAL_AUTONOMY_H
#define _GLOBAL_AUTONOMY_H

// My Headers
#include "GlobalDirectX.h"

// Variables
static XMMATRIX* myMatrix;
static XMVECTOR targetVector;
const static XMVECTOR worldOrigin = { 0, 0, 0, 1 };
const static XMVECTOR worldUp = XMVectorSet(0, 1, 0, 1);

class GlobalAutonomy
{
public:
	static void LookAt(XMMATRIX* myMatrix, XMVECTOR* targetPosition);
	static void TurnTo(class MovingObject* myMovingScript, XMVECTOR* targetPosition);
};

#endif