#ifndef _GLOBAL_AUTONOMY_H
#define _GLOBAL_AUTONOMY_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalWorldInfo.h"

// Variables
static XMMATRIX* myMatrix;
static XMVECTOR targetVector;

class GlobalAutonomy
{
public:
	static void LookAt(XMMATRIX* myMatrix, XMVECTOR* targetPosition);
	static void TurnTo(class MovingObject* myMovingScript, XMVECTOR* targetPosition);
};

#endif