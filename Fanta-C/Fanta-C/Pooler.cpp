#pragma region Dependencies
// My Headers
#include "Pooler.h"			// Connection to declarations

#include "BulletTrail.h"
#include "Line.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
Pooler*	Pooler::poolerInstance = nullptr;
#pragma endregion

#pragma region Initialization
Pooler* Pooler::GetInstance()
{
	// If instance is already created, return it
	if (poolerInstance) return poolerInstance;

	// If instance has not been created, create it and return it
	else
	{
		poolerInstance = new Pooler;
		return poolerInstance;
	}
}
#pragma endregion

#pragma region Public Interface
SceneObject* Pooler::SpawnBulletTrail(XMVECTOR* startPosition, XMVECTOR* endPosition)
{
	// For each scene object
	for (iterator = 0; iterator < bulletTrailPool.GetCapacity(); ++iterator)
	{
		// If bulletTrail is not active, return it
		if (!bulletTrailPool.At(iterator)->GetActive())
		{
			// Set line attributes, set it to active, and return it
			static_cast<Line*>(bulletTrailPool.At(0)->GetMesh())->SetLineColor(&Colors::White);
			static_cast<Line*>(bulletTrailPool.At(0)->GetMesh())->SetPositions(startPosition, endPosition);
			static_cast<BulletTrail*>(bulletTrailPool.At(0)->GetMyScripts()->at(0))->ReInit();
			bulletTrailPool.At(iterator)->SetActive(true);
			return bulletTrailPool.At(0);
		}
	}

	// If function makes it here, there was no available bulletTrail;
	return nullptr;
}
#pragma endregion

#pragma region Clean Up
Pooler::~Pooler()
{
	// For each scene object
	for (iterator = 0; iterator < bulletTrailPool.GetCapacity(); ++iterator)
	{
		// If it is not nullptr
		if (bulletTrailPool.At(iterator))
		{
			// If scene objects container has this object within it, set it to nullptr
			if (sceneObjects.CapacityContains(bulletTrailPool.At(iterator)))
				sceneObjects.SetAt(sceneObjects.ReturnIndex(bulletTrailPool.At(iterator)), nullptr);

			// Delete object and set it to nullptr
			delete bulletTrailPool.At(iterator);
			bulletTrailPool.SetAt(iterator, nullptr);
		}
	}

	// For each scene object
	for (iterator = 0; iterator < sceneObjects.GetCapacity(); ++iterator)
	{
		// If it is not nullptr
		if (sceneObjects.At(iterator))
		{
			delete sceneObjects.At(iterator);
			sceneObjects.SetAt(iterator, nullptr);
		}
	}
}
#pragma endregion