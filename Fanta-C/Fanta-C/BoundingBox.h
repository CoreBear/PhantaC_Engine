#ifndef _BOUNDING_BOX_H
#define _BOUNDING_BOX_H

// System Headers
#include <vector>
#include <unordered_map>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class ObjectManager;

class BoundingBox
{
	bool						isColliding;
	//std::vector<ObjectManager*>	collidingObjects;
	std::unordered_map<ushort, ObjectManager*>	collidingObjects;
	uchar						boundingIterators[2];
	XMVECTOR					extents;			// Also the max
	XMVECTOR					minMax[2];			// Index 0 - Min. Index 1 - Max

	void CreateBounds(float inWidth, float inHeight, float inDepth, float inScale);

public:
	// Initialization
	BoundingBox(float inWidth, float inHeight, float inDepth, float inScale) : isColliding(false) { CreateBounds(inWidth, inHeight, inDepth, inScale); }

	// Public Interface
	/// Summary
	/// When object collides with invoking object, the other object gets added to this container
	///
	/// Parameters
	/// collidingObject - The object that is colliding with the invoking object
	void AddCollidingObject(ObjectManager* collidingObject);
	/// Summary
	/// A check to see if the parametered object is colliding with the invoking object
	///
	/// Parameters
	/// collidingObject - The object that is being checked for collision with the invoking object
	bool CheckIfObjectInContainer(ObjectManager* collidingObject);
	void CalculateMinMax(XMVECTOR* myPosition);
	/// Summary
	/// Checks if the invoking object is colliding with any other object
	///
	/// Return
	/// True if there is no collision with invoking object. False if not
	bool ContainerEmpty() { return (collidingObjects.size() > 0) ? false : true; }
	/// Summary
	/// If separation occurs this frame, the parametered object is removed from collision
	///
	/// Parameters
	/// removeObject - The object that will be removed from invoking object's collision container
	void RemoveCollidingObject(ObjectManager* removeObject);

	// Accessors
	bool GetColliding() { return isColliding; }
	XMVECTOR& GetExtents() { return extents; }
	XMVECTOR& GetMinMax(ushort index) { return minMax[index]; }

	// Mutators
	void SetExtents(float x, float y, float z);
	void ToggleColliding() { isColliding = !isColliding; }
};

#endif