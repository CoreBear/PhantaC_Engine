#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "BulletTrail.h"
#include "Camera.h"
#include "GlobalInputVariables.h"
#include "GlobalTransform.h"
#include "Line.h"
#include "RayCast.h"
#include "SceneGraph.h"
#include "SceneObject.h"
#include "Spawner.h"
#pragma endregion

#pragma region Forward Declarations
PlayerManager* PlayerManager::playerManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
PlayerManager* PlayerManager::GetInstance(Camera* inCamera, SceneObject* inSceneObject, float inPitchVelocity, float inRollVelocity, float inVelocity, float inYawVelocity)
{
	// If instance is already created, return it
	if (playerManagerInstance) return playerManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		playerManagerInstance = new PlayerManager(inCamera, inSceneObject, inPitchVelocity, inRollVelocity, inVelocity, inYawVelocity);
		return playerManagerInstance;
	}
}
#pragma endregion

#pragma region Public Interface
void PlayerManager::Move(char x, char y, char z)
{
	// Update camera matrix and copy it over to transform matrix
	GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *cameraPtr->GetViewMatrix());
	myObject->GetTransform()->SetLocalMatrix(cameraPtr->GetViewMatrix());
}
void PlayerManager::Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * pitchVelocity, *cameraPtr->GetViewMatrix()); }
void PlayerManager::Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * rollVelocity, *cameraPtr->GetViewMatrix()); }
void PlayerManager::Shoot()
{
	#pragma region Ray Cast
	// Shoot ray cast
	hitObject = RayCast::Cast(

		// Start Position (X, Y, Z, W)
		&cameraPtr->GetViewMatrix()->r[3],

		// End Position (X, Y, Z, W)
		&XMVectorSet(cameraPtr->GetViewMatrix()->r[3].m128_f32[0] + cameraPtr->GetViewMatrix()->r[2].m128_f32[0] * trailDistance, 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[1] + cameraPtr->GetViewMatrix()->r[2].m128_f32[1] * trailDistance,
			cameraPtr->GetViewMatrix()->r[3].m128_f32[2] + cameraPtr->GetViewMatrix()->r[2].m128_f32[2] * trailDistance, 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[3]));
	#pragma endregion

	//#pragma region Bullet Trail
	// If an object was hit
	if (hitObject)
	{
		// Spawn bullet trail (if available) at specified positions and activate it
		SceneGraph::ActivateObject(Spawner::SpawnBulletTrail(
		
		// Start Position (X, Y, Z, W)
		&XMVectorSet(cameraPtr->GetViewMatrix()->r[3].m128_f32[0], 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[1] - 1,
			cameraPtr->GetViewMatrix()->r[3].m128_f32[2], 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[3]),
	
		// End Position (X, Y, Z, W)
		hitObject->GetTransform()->GetPosition()));
	
		// Remove hit object from the scene
		SceneGraph::RemoveFromActive(hitObject);
	
		// Remove the hit object
		hitObject = nullptr;
	}
	
	// If miss
	else
	{
		// Spawn bullet trail (if available) at specified positions and activate it
		SceneGraph::ActivateObject(Spawner::SpawnBulletTrail(
		
		// Start Position (X, Y, Z, W)
		&XMVectorSet(cameraPtr->GetViewMatrix()->r[3].m128_f32[0], 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[1] - 1,
			cameraPtr->GetViewMatrix()->r[3].m128_f32[2], 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[3]),
	
		// End Position (X, Y, Z, W)
		&XMVectorSet(cameraPtr->GetViewMatrix()->r[3].m128_f32[0] + cameraPtr->GetViewMatrix()->r[2].m128_f32[0] * trailDistance, 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[1] + cameraPtr->GetViewMatrix()->r[2].m128_f32[1] * trailDistance,
			cameraPtr->GetViewMatrix()->r[3].m128_f32[2] + cameraPtr->GetViewMatrix()->r[2].m128_f32[2] * trailDistance, 
			cameraPtr->GetViewMatrix()->r[3].m128_f32[3])));
	}
	#pragma endregion
}
void PlayerManager::Yaw(char angle) { GlobalTransform::RotateOnYAxis(angle * GlobalTime::deltaTime * yawVelocity, *cameraPtr->GetViewMatrix()); }
#pragma endregion