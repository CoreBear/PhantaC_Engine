#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "AgentManager.h"
#include "BulletTrail.h"
#include "Cube.h"
#include "Line.h"
#include "Pooler.h"
#include "SceneObject.h"
#include "ScriptManager.h"
#pragma endregion

#pragma region Initialization
TestScene::TestScene(bool useGrid, ushort* clientDimensions) : SceneGraph(useGrid, clientDimensions)
{
	// For iterators
	short x, y, z;

	#pragma region Enemy Creation
	#if DEBUG_RUN
	// This is 27 objects - Runs well in both
	for (x = -5; x < 6; x += 5)
	{
		for (y = -5; y < 6; y += 5)
		{
			for (z = -5; z < 6; z += 5)
			{
				if (CreateSceneObject(new SceneObject(new Cube(1, 1, 1), true, true, true, true, XMVectorSet(x, y, z, 1))))
				{
					Pooler::sceneObjects.At(numberOfObjectsInScene - 1)->AddScript(new AgentManager(Pooler::sceneObjects.At(numberOfObjectsInScene - 1), 1, 1, 10, 1));
					static_cast<AgentManager*>(Pooler::sceneObjects.At(numberOfObjectsInScene - 1)->GetMyScripts()->at(0))->AssignTarget(Pooler::sceneObjects.At(1)->GetTransform()->GetPosition());	// Assign target
				}
			}
		}
	}
	#elif RELEASE_RUN
	// This is 125 objects - Runs well in both
	for (x = -10; x < 11; x += 5)
	{
		for (y = -10; y < 11; y += 5)
		{
			for (z = -10; z < 11; z += 5)
			{
				if (CreateSceneObject(new SceneObject(new Cube(1, 1, 1), true, true, true, true, XMVectorSet(x, y, z, 1))))
				{
					Pooler::sceneObjects.At(numberOfObjectsInScene - 1)->AddScript(new AgentManager(Pooler::sceneObjects.At(numberOfObjectsInScene - 1), 1, 1, 10, 1));
					static_cast<AgentManager*>(Pooler::sceneObjects.At(numberOfObjectsInScene - 1)->GetMyScripts()->at(0))->AssignTarget(Pooler::sceneObjects.At(1)->GetTransform()->GetPosition());	// Assign target
				}
			}
		}
	}
	#endif
	#pragma endregion

	#pragma region Bullet Trail Creation
	// Generate bullet trails
	// Let pooler know where bullet trails start
	Pooler::bulletTrailIndices[0] = numberOfObjectsInScene;
	
	for (x = numberOfObjectsInScene, numberOfObjectsInScene += Pooler::numberOfBulletsTrailsToPool; x < numberOfObjectsInScene; ++x)
	{
		CreateSceneObject(new SceneObject(new Line, false, false, true, true));
		Pooler::sceneObjects.At(x)->AddScript(new BulletTrail(Pooler::sceneObjects.At(x)));
	}

	// Let pooler know where bullet trails end
	Pooler::bulletTrailIndices[1] = x;
	#pragma endregion
}
#pragma endregion