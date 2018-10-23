#ifndef _CUBE_H
#define _CUBE_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Cube : public ObjectTransform
{
	bool					shapeIsFlat = false;
	float					scale;
	constexpr static uchar	numberOfLinesTriIndicesVertices[3] = { 3, 4, 8 };
	uchar					triIndices[numberOfLinesTriIndicesVertices[1]][numberOfLinesTriIndicesVertices[0]][2];
	SIMPLE_VERTEX			vertices[numberOfLinesTriIndicesVertices[2]];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Cube(float inScale = 1) : scale(inScale), ObjectTransform(worldOrigin) { CreateShape(inScale); }
	Cube(const XMVECTOR& position, float inScale = 1) : scale(inScale), ObjectTransform(position) { CreateShape(inScale); }
	Cube(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : scale(inScale), ObjectTransform(false, position, forward, up) { CreateShape(inScale); }

	// Public Interface
	void DrawMe(LineRenderer& lineRenderer) override;

	// Accessors
	bool GetFlatness() const override { return shapeIsFlat; }
	float GetScale() const override { return scale; }
};

#endif