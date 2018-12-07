#ifndef _GLOBAL_WORLD_VARIABLES_H
#define _GLOBAL_WORLD_VARIABLES_H

struct GlobalWorldVariables
{
	constexpr static XMVECTOR worldForward = { 0, 0, 1, 1 };
	constexpr static XMVECTOR worldOrigin = { 0, 0, 0, 1 };
	constexpr static XMVECTOR worldRight = { 1, 0, 0, 1 };
	constexpr static XMVECTOR worldUp = { 0, 1, 0, 1 };
};

#endif