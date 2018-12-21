#pragma region Dependencies
// My Headers
#include "LineRenderer.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
LineRenderer* LineRenderer::lineRendererInstance = nullptr;
#pragma endregion

#pragma region Initialization
LineRenderer* LineRenderer::GetInstance()
{
	// If instance has been created, return it
	if (lineRendererInstance) return lineRendererInstance;

	// If instance has not been created, create it and return it
	else
	{
		lineRendererInstance = new LineRenderer;
		return lineRendererInstance;
	}
}
#pragma endregion

#pragma region Public Interface
void LineRenderer::AddNewLine(XMVECTOR lineStart, XMVECTOR lineEnd, XMVECTORF32 startColor, XMVECTORF32 endColor)
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