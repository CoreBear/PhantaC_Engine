#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "BulletTrail.h"
#include "Camera.h"
#include "GlobalInputVariables.h"
#include "GlobalTransform.h"
#include "Line.h"
#include "Pooler.h"
#include "SceneGraph.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
PlayerManager*	PlayerManager::playerManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
PlayerManager * PlayerManager::GetInstance(Camera* inCamera, SceneGraph* sceneGraph, float inPitchVelocity, float inRollVelocity, float inVelocity, float inYawVelocity)
{
	// If instance is already created, return it
	if (playerManagerInstance) return playerManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		playerManagerInstance = new PlayerManager(inCamera, sceneGraph, inPitchVelocity, inRollVelocity, inVelocity, inYawVelocity);
		return playerManagerInstance;
	}
}
#pragma endregion

#pragma region Public Interface
void PlayerManager::Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *camera->GetViewMatrix()); }
void PlayerManager::Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * pitchVelocity, *camera->GetViewMatrix()); }
void PlayerManager::Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * rollVelocity, *camera->GetViewMatrix()); }
void PlayerManager::Shoot()
{
	// Get a trail from the pooler and set its positions
	bulletTrail = poolerInstance->SpawnBulletTrail(
	
	// Start Position (X, Y, Z, W)
	&XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0],
		camera->GetViewMatrix()->r[3].m128_f32[1],
		camera->GetViewMatrix()->r[3].m128_f32[2] - 1,
		camera->GetViewMatrix()->r[3].m128_f32[3]),

	// End Position (X, Y, Z, W)
	&XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0] + camera->GetViewMatrix()->r[2].m128_f32[0] * trailDistance,
		camera->GetViewMatrix()->r[3].m128_f32[1] + camera->GetViewMatrix()->r[2].m128_f32[1] * trailDistance,
		camera->GetViewMatrix()->r[3].m128_f32[2] + camera->GetViewMatrix()->r[2].m128_f32[2] * trailDistance,
		camera->GetViewMatrix()->r[3].m128_f32[3]));

	// If bullet trail was available, add it to the scene
	if (bulletTrail)
		sceneGraphPtr->AddObjectToScene(bulletTrail);
}
void PlayerManager::Yaw(char angle) { GlobalTransform::RotateOnYAxis(angle * GlobalTime::deltaTime * yawVelocity, *camera->GetViewMatrix()); }
#pragma endregion