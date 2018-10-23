#ifndef _GLOBAL_GAME_H
#define _GLOBAL_GAME_H

#include "GlobalDirectX.h"

static bool			gameIsPaused = false;
static float		edgeOfGridDistance;																					// Will be assigned when grid is created
const XMVECTOR		worldOrigin = { 0, 0, 0, 1 };
const XMVECTOR		worldVectors[3] = { XMVectorSet(1, 0, 0, 1), XMVectorSet(0, 1, 0, 1), XMVectorSet(0, 0, 1, 1) };	// X-Axis, Y-Axis, Z-Axis

#endif