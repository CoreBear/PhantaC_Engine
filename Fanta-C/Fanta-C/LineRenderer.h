#ifndef _LINE_RENDERER_H
#define _LINE_RENDERER_H

#include "Typedefs.h"
#include <array>
#include "GeometryGlobals.h"
#include <DirectXMath.h>
using namespace DirectX;

class LineRenderer
{
	constexpr static ushort containerCapacity = 5000;
	ushort currentCount = 0;
	std::array<SIMPLE_VERTEX, containerCapacity> lineVertices;

public:
	void AddNewLine(XMFLOAT3 lineStart, XMFLOAT3 lineEnd, XMVECTORF32 startColor, XMVECTORF32 endColor)
	{
		if (currentCount < containerCapacity)
		{
			// Line start
			lineVertices[currentCount].color = startColor;
			lineVertices[currentCount++].localPos = lineStart;

			// Line end
			lineVertices[currentCount].color = endColor;
			lineVertices[currentCount++].localPos = lineEnd;
		}
	}
	void ClearLines()
	{
		currentCount = 0;

		/*for (iterators[0] = 0; iterators[0] < containerCapacity; ++iterators[0])
			lineVertices[iterators[0]].localPos = { 0 };*/
	}
	const SIMPLE_VERTEX* GetAllVertices()
	{
		return lineVertices.data();
	}
	unsigned short GetCurrentVertexCount()
	{
		return currentCount;
	}
	unsigned short GetContainerCapacity()
	{
		return containerCapacity;
	}
};

#endif