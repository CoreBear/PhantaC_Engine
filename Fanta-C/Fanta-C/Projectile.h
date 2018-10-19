#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "GeometricObject.h"
#include "GeometryGlobals.h"
#include "LineRenderer.h"
#include "ProgramGlobals.h"

class Projectile : public GeometricObject
{
	XMVECTOR				centroid;
	SIMPLE_VERTEX			vertices[2];

public:
	// Initialize
	Projectile();

	// Update 
	void Update() override;
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override;
};

#endif