#pragma region Dependencies
// My Headers
#include "Line.h"			// Connection to declarations
#pragma endregion

#pragma region Public Interface
void Line::SetLineColor(const XMVECTORF32* inColor)
{
	vertices[0].color = *inColor;
	vertices[1].color = *inColor;
}
void Line::SetPositions(XMVECTOR* startPosition, XMVECTOR* endPosition)
{
	vertices[0].localPos = *startPosition;
	vertices[1].localPos = *endPosition;
}
#pragma endregion
