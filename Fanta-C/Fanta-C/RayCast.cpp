#pragma region Dependencies
// My Headers
#include "RayCast.h"		// Connection to declarations

#include "GlobalMath.h"
#include "Pooler.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
uchar		RayCast::objectCheckStartIndex;
ushort		RayCast::iterator;
XMVECTOR	RayCast::checkObjectsMinMax[2];
XMVECTOR	RayCast::checkedObjectDirection;
XMVECTOR	RayCast::rayCastDirection;
XMVECTOR	RayCast::startEnd[2];
#pragma endregion

#pragma region Public Interface
SceneObject* RayCast::Cast(XMVECTOR* startPosition, XMVECTOR* endPosition)
{
	// Ray cast start and end positions
	startEnd[0] = *startPosition;
	startEnd[1] = *endPosition;
	
	// Direction from beginning to end of the ray cast
	rayCastDirection = *GlobalMath::VectorSubtraction(endPosition, startPosition);

	// For each collidable object	
	for (iterator = 2; iterator < Pooler::activeObjects.GetSize(); ++iterator)
	{
		// Direction from raycaster's position to collidable object
		checkedObjectDirection = *GlobalMath::VectorSubtraction(Pooler::activeObjects.At(iterator)->GetTransform()->GetPosition(), startPosition);
		
		// Normalize the two vectors before checking their dot product
		GlobalMath::Normalize(&rayCastDirection);
		GlobalMath::Normalize(&checkedObjectDirection);

		// If object is is close enough to player's reticule, run check
		if (GlobalMath::Vector3DotProduct(&rayCastDirection, &checkedObjectDirection) > allowableLimit)
		{
			// Update check object's min max
			//activeObjects->At(iterator)->GetColliderManager()->GetBoundingBox()->CalculateMinMax(activeObjects->At(iterator)->GetTransform()->GetLocalMatrix(), &checkObjectsMinMax[0], &checkObjectsMinMax[1]);
			
			//// Find box's z on raycast's z
			//// Lerp
			//// Figure out min max on that angle
			//// Figure out if line is going through
			//
			//
			//&XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0] + camera->GetViewMatrix()->r[2].m128_f32[0] * trailDistance,
			//	camera->GetViewMatrix()->r[3].m128_f32[1] + camera->GetViewMatrix()->r[2].m128_f32[1] * trailDistance,
			//	camera->GetViewMatrix()->r[3].m128_f32[2] + camera->GetViewMatrix()->r[2].m128_f32[2] * trailDistance,
			//	camera->GetViewMatrix()->r[3].m128_f32[3]));

			// Return first object hit
			// Quick and lazy, just to check
			return Pooler::activeObjects.At(iterator);
		}
	}

	// If no object was hit
	return nullptr;
}
#pragma endregion

#pragma region Mutators
void RayCast::UpdateRayCastStartIndex(uchar index) { objectCheckStartIndex = index; }
#pragma endregion
