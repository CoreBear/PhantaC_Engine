#ifndef _LINE_RENDERER_H
#define _LINE_RENDERER_H

// System Headers
#include <array>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "Typedefs.h"

using namespace DirectX;

class LineRenderer
{
	constexpr static ushort containerCapacity = 5000;
	ushort currentCount = 0;
	std::array<SIMPLE_VERTEX, containerCapacity> lineVertices;

public:
	// Public Interface
	void AddNewLine(XMFLOAT3 lineStart, XMFLOAT3 lineEnd, XMVECTORF32 startColor, XMVECTORF32 endColor);
	void ClearLines() { currentCount = 0; }

	// Accessors
	const ushort GetContainerCapacity() const { return containerCapacity; }
	const ushort GetCurrentVertexCount() const { return currentCount; }
	const SIMPLE_VERTEX* GetAllVertices() const { return lineVertices.data(); }
};

// This maybe goes in clear lines
		/*for (iterators[0] = 0; iterators[0] < containerCapacity; ++iterators[0])
			lineVertices[iterators[0]].localPos = { 0 };*/
#endif