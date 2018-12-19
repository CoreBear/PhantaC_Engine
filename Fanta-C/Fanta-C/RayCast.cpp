#pragma region Dependencies
// My Headers
#include "RayCast.h"		// Connection to declarations

#include "SceneObject.h"
#pragma endregion

#pragma region Public Interface
bool RayCast::Cast(XMVECTOR* startPosition, XMVECTOR* endPosition)
{
	startEnd[0] = *startPosition;
	startEnd[1] = *endPosition;
}
#pragma endregion

#pragma region Private Functionality
bool RayCast::Hit()
{

}
#pragma endregion