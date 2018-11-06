#ifndef _QUAD_H
#define _QUAD_H

// My Headers
#include "Mesh.h"

class Quad : public Mesh
{
	constexpr static uchar	numberOfVertices = 4;
	SIMPLE_VERTEX			vertices[numberOfVertices];

	void CreateMesh();

public:
	// Initialization
	Quad(const XMVECTOR& position = { 0, 0, 0, 1 }, float inScale = 1) : Mesh(position, true, inScale, Colors::Purple) { CreateMesh(); }
	Quad(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up, float inScale = 1) : Mesh(position, forward, up, true, inScale, Colors::Purple) { CreateMesh(); }

	// Public Interface
	void AddMyLinesToRenderer(LineRenderer& lineRenderer) override;
};

#endif