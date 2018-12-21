#pragma region Dependencies
// My Headers
#include "Spawner.h"		// Connection to declarations

#include "Line.h"
#include "Pooler.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
// Pooler Variables
ushort Pooler::bulletTrailIndices[2];

// Spawner Variables
ushort Spawner::iterator;
#pragma endregion

#pragma region Public Interface
SceneObject* Spawner::SpawnBulletTrail(XMVECTOR* startPosition, XMVECTOR* endPosition)
{
	// For each scene object
	for (iterator = Pooler::bulletTrailIndices[0]; iterator < Pooler::bulletTrailIndices[1]; ++iterator)
	{
		// If object is not active in the scene
		if (!Pooler::sceneObjects.At(iterator)->GetActive())
		{
			// Set to active, line color, positions, and return object
			Pooler::sceneObjects.At(iterator)->SetActive(true);
			static_cast<Line*>(Pooler::sceneObjects.At(iterator)->GetMesh())->SetLineColor(&Colors::White);
			static_cast<Line*>(Pooler::sceneObjects.At(iterator)->GetMesh())->SetPositions(startPosition, endPosition);
			return Pooler::sceneObjects.At(iterator);
		}
	}

	// If function makes it here, there was no available bulletTrail;
	return nullptr;
}
#pragma endregion