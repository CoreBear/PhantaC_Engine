#ifndef _PROGRAM_GLOBALS_H
#define _PROGRAM_GLOBALS_H

#include "Typedefs.h"

enum				KEYS { A = 0x41, I = 0x49, J = 0x4A, K = 0x4B, L = 0x4C, D = 0x44, S = 0x53, W = 0x57 };
constexpr uchar		targetFPS = 100;
static ushort		clientDimensions[2] = { 720, 1280 };			// Index 0 - Height. 1 - Width
static ushort		iterators[3];

#endif