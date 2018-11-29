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
	bool		meshIsFlat;
	float		depth;
	float		height;
	float		scale;
	float		width;
	XMVECTORF32	color;

public:
	// Initialization (Camera uses the first constructor and shapes use the second)
	Mesh(bool isFlat, XMVECTORF32 inColor = Colors::White) : depth(0), height(0), scale(1), width(0), color(inColor) { return; }
	Mesh(float inWidth, float inHeight, float inDepth, float inScale, XMVECTORF32 inColor) : depth(inDepth), height(inHeight), scale(inScale), width(inWidth), color(inColor) { meshIsFlat = (inWidth == 0 || inHeight == 0 || inDepth == 0) ? true : false; }

	// Public Interface
	virtual void AddMyLinesToRenderer(LineRenderer& lineRenderer) { return; }
	void ChangeColor(XMVECTORF32 inColor) { color = inColor; }

	// Accessors
	bool GetFlatness() const { return meshIsFlat; }
	float GetDepth() const { return depth; }
	float GetHeight() const { return height; }
	float GetScale() const { return scale; }
	float GetWidth() const { return width; }
};

#endif