#ifndef _MESH_H
#define _MESH_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Mesh : public ObjectTransform
{
protected:
	bool	meshIsFlat;
	float	scale;

public:
	// Initialization
	Mesh(const XMVECTOR& position, bool isFlat, float inScale) : meshIsFlat(isFlat), scale(inScale), ObjectTransform(position) { return; }
	Mesh(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, bool isFlat, float inScale) : meshIsFlat(isFlat), scale(inScale), ObjectTransform(false, position, forward, up) { return; }

	// Public Interface
	virtual void AddMyLinesToRenderer(LineRenderer& lineRenderer) { return; }

	// Accessors
	bool GetFlatness() const override { return meshIsFlat; }
	float GetScale() const override { return scale; }
};

#endif