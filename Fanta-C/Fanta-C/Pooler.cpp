#pragma region Dependencies
// My Headers
#include "Pooler.h"			// Connection to declarations

#include "SceneObject.h"
#pragma endregion

#pragma region Clean Up
void Pooler::PoolerDestructor()
{
	// For each scene object
	for (ushort iterator = 0; iterator < sceneObjects.GetCapacity(); ++iterator)
	{
		// If it is not nullptr, delete it and set to nullptr
		if (sceneObjects.At(iterator))
		{
			delete sceneObjects.At(iterator);
			sceneObjects.SetAt(iterator, nullptr);
		}
	}
}
#pragma endregion