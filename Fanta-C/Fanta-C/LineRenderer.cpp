#pragma region Dependencies
// My Headers
#include "LineRenderer.h"			// Connection to declarations
#pragma endregion

#pragma region Public Interface
void LineRenderer::AddNewLine(XMFLOAT3 lineStart, XMFLOAT3 lineEnd, XMVECTORF32 startColor, XMVECTORF32 endColor)
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
#pragma endregion