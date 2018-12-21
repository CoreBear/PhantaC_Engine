#ifndef _LINE_H
#define _LINE_H

// My Headers
#include "Mesh.h"

class Line : public Mesh
{
	SIMPLE_VERTEX vertices[2];

public:
	// Initialization
	Line() { return; }
	Line(const XMVECTORF32* inColor, XMVECTOR* startPosition, XMVECTOR* endPosition) : Mesh(*inColor)
	{
		SetLineColor(inColor);
		SetPositions(startPosition, endPosition);
	}

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer* lineRenderer) override { lineRenderer->AddNewLine(vertices[0].localPos, vertices[1].localPos, vertices[0].color, vertices[1].color); }
	void SetEndPosition(XMVECTOR* endPosition) { vertices[1].localPos = *endPosition; }
	void SetLineColor(const XMVECTORF32* inColor);
	void SetPositions(XMVECTOR* startPosition, XMVECTOR* endPosition);
	void SetStartPosition(XMVECTOR* startPosition) { vertices[0].localPos = *startPosition; }
};

#endif