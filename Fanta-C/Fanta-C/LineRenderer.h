#ifndef _LINE_RENDERER_H
#define _LINE_RENDERER_H

// System Headers
#include <array>

// My Headers
#include "GlobalVramStructures.h"
#include "GlobalTypedefs.h"

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
#endif