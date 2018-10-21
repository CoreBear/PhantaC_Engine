#ifndef _LINE_H
#define _LINE_H

// My Headers
#include "CollidableObject.h"
#include "GlobalGame.h"

class Line : public CollidableObject
{
	SIMPLE_VERTEX			vertices[2];

public:
	// Initialize
	Line();

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) override { lineRenderer.AddNewLine(vertices[0].localPos, vertices[1].localPos, vertices[0].color, vertices[1].color); }
};

#endif