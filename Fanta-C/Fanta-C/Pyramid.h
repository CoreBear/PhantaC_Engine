#ifndef _PYRAMID_H
#define _PYRAMID_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Pyramid : public ObjectTransform
{
	bool					shapeIsFlat = false;
	float					scale;
	constexpr static uchar	numberOfLineIndicesVertices[2] = { 8, 5 };
	uchar					lineIndices[numberOfLineIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLineIndicesVertices[1]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Pyramid(float inScale = 1) : scale(inScale), ObjectTransform(worldOrigin) { CreateShape(inScale); }
	Pyramid(const XMVECTOR& position, float inScale = 1) : scale(inScale), ObjectTransform(position) { CreateShape(inScale); }
	Pyramid(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : scale(inScale), ObjectTransform(false, position, forward, up) { CreateShape(inScale); }

	// Public Interface
	void DrawMe(LineRenderer& lineRenderer) override;

	// Accessors
	bool GetFlatness() const override { return shapeIsFlat; }
	float GetScale() const override { return scale; }
};

#endif