#ifndef _MESH_H
#define _MESH_H

// My Headers
#include "GlobalGame.h"
#include "GlobalGeometry.h"
#include "ObjectTransform.h"

class Mesh : public ObjectTransform
{
protected:
	bool	shapeIsFlat;
	float	scale;

public:
	// Initialization
	Mesh(const XMVECTOR& position, bool isFlat, float inScale) : shapeIsFlat(isFlat), scale(inScale), ObjectTransform(position) { return; }
	Mesh(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, bool isFlat, float inScale) : shapeIsFlat(isFlat), scale(inScale), ObjectTransform(false, position, forward, up) { return; }
	
	// Accessors
	bool GetFlatness() const override { return shapeIsFlat; }
	float GetScale() const override { return scale; }
};

#endif