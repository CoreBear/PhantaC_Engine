#ifndef _PROJECTILE_H
#define _PROJECTILE_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalGeometry.h"
#include "ProgramGlobals.h"
#include "RenderObject.h"

class Projectile : public RenderObject
{
	SIMPLE_VERTEX			vertices[2];

public:
	// Initialize
	Projectile();

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override { lineRenderer.AddNewLine(vertices[0].localPos, vertices[1].localPos, vertices[0].color, vertices[1].color); }
};

#endif