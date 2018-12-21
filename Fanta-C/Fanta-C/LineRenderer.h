#ifndef _LINE_RENDERER_H
#define _LINE_RENDERER_H

// System Headers
#include <array>

// My Headers
#include "GlobalVramStructures.h"
#include "GlobalTypedefs.h"

class LineRenderer
{
	// Variables
	static LineRenderer*							lineRendererInstance;
	constexpr static ushort							containerCapacity = 5000;
	ushort											currentCount;
	std::array<SIMPLE_VERTEX, containerCapacity>	lineVertices;

	// Initialization
	LineRenderer() : currentCount(0) { return; }
	LineRenderer(LineRenderer const&) = delete;
	LineRenderer operator=(LineRenderer const&) = delete;

public:
	// Initialization
	static LineRenderer* GetInstance();

	// Public Interface
	/// Summary
	/// Creates lines that will later be added to the renderer module to represent the simple geometry
	///
	/// Parameters
	/// lineStart - Point of start for the line
	///	lineEnd - Point of end for the line
	///	startColor - Starting color of the line
	/// endColor - Ending color of the line (Can be different from starting. Color lerp will take place.)
	void AddNewLine(XMVECTOR lineStart, XMVECTOR lineEnd, XMVECTORF32 startColor, XMVECTORF32 endColor);
	/// Summary
	/// After lines have been drawn, the counter will be reset so new lines can overwrite the old lines
	void ClearLines() { currentCount = 0; }

	// Accessors
	const ushort GetContainerCapacity() const { return containerCapacity; }
	const ushort GetCurrentVertexCount() const { return currentCount; }
	const SIMPLE_VERTEX* GetAllVertices() const { return lineVertices.data(); }
};
#endif