#ifndef _TRIANGLE_H
#define _TRIANGLE_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Triangle : public ObjectTransform
{
	bool					shapeIsFlat = false;
	float					scale;
	constexpr static uchar	numberOfVertices = 3;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	// Private
	void CreateShape(float scale);

public:
	// Initialization
	Triangle(float inScale = 1) : scale(inScale), ObjectTransform(worldOrigin) { CreateShape(inScale); }
	Triangle(const XMVECTOR& position, float inScale = 1) : scale(inScale), ObjectTransform(position) { CreateShape(inScale); }
	Triangle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : scale(inScale), ObjectTransform(false, position, forward, up) { CreateShape(inScale); }

	// Public Interface
	void DrawMe(LineRenderer& lineRenderer) override;

	// Accessors
	bool GetFlatness() const override { return shapeIsFlat; }
	float GetScale() const override { return scale; }
};

#endif