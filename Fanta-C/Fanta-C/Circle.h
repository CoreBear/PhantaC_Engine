#ifndef _CIRCLE_H
#define _CIRCLE_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Circle : public ObjectTransform
{
	bool						shapeIsFlat = true;
	float						scale;
	constexpr static ushort		numberOfVertices = 360;
	SIMPLE_VERTEX				vertices[numberOfVertices];

	void CreateShape(float scale);

public:
	// Initialization
	Circle(float inScale = 1) : scale(inScale), ObjectTransform(worldOrigin) { CreateShape(inScale); }
	Circle(const XMVECTOR& position, float inScale = 1) : scale(inScale), ObjectTransform(position) { CreateShape(inScale); }
	Circle(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : scale(inScale), ObjectTransform(false, position, forward, up) { CreateShape(inScale); }

	// Public Interface
	void DrawMe(LineRenderer& lineRenderer) override;

	// Accessors
	bool GetFlatness() const override { return shapeIsFlat; }
	float GetScale() const override { return scale; }
};

#endif