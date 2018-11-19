#ifndef _MESH_H
#define _MESH_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalIterators.h"
#include "GlobalWorldInfo.h"
#include "GlobalVramStructures.h"
#include "GlobalTypedefs.h"
#include "LineRenderer.h"

class Mesh
{
protected:
	bool			meshIsFlat;
	float			scale;
	XMVECTORF32		color;

public:
	// Initialization
	Mesh(bool isFlat, float inScale, XMVECTORF32 inColor = Colors::White) : meshIsFlat(isFlat), scale(inScale), color(inColor) { return; }

	// Public Interface
	virtual void AddMyLinesToRenderer(LineRenderer& lineRenderer) { return; }
	void ChangeColor(XMVECTORF32 inColor) { color = inColor; }

	// Accessors
	bool GetFlatness() const { return meshIsFlat; }
	float GetScale() const { return scale; }
};

#endif