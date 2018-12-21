#ifndef _RETICLE_H
#define _RETICLE_H

// My Headers
#include "Mesh.h"

class Reticle : public Mesh
{
	// Variables
	constexpr static ushort		numberOfVertices = 3;				
	SIMPLE_VERTEX				vertices[numberOfVertices];	

	// Private Functionality
	void CreateMesh(float inHeight, float inWidth, float inScale);

public:
	// Initialization
	Reticle(float inHeight = 0.015f, float inWidth = 0.01f, float inScale = 1) : Mesh(Colors::Orange, 1, inHeight, inWidth, inScale) { CreateMesh(inHeight, inWidth, inScale); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer* lineRenderer) override;
};
#endif