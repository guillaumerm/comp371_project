#ifndef PHYSICAL_OBJECT_H
#define PHYSICAL_OBJECT_H
#include "Object.h"
#include "Material.h"
#include "Ray.h"

class PhysicalObject: public Object {
public:
	//! A constructor which creates a default PhysicalObject.
	PhysicalObject();

	//! A constructor which creates a PhysicalObject with a position and Material.
	/*!
		\param position position of the PhysicalObject.
		\param material Material of the physicalObject.
	*/
	PhysicalObject(glm::vec3 position, Material material);

	//! Obtain the Material of the PhysicalObject.
	/*!
		\return The Material of the PhysicalObject.
	*/
	Material getMaterial();

	//! Mutates the Material of the PhysicalObject.
	/*!
		\param material new Material of the PhysicalObject.
	*/
	void setMaterial(Material material);

	//! Verifies if a ray intersects with the PhysicalObject.
	/*!
		\param ray Ray that is being tested for intersection.
		\return True if intersects, False otherwise.
	*/
	virtual bool intersect(Ray& ray);

	//! Verifies if a ray intersects with the PhysicalObject. If it does then t, intersectionPoint and intersectionNormal gets the values calculated.
	/*!
		\param ray Ray that is being tested for intersection.
		\param t result from the geometric query.
		\param intersectionPoint point of intersection between the PhysicalObject and the Ray.
		\param intersectionNormal normal at the point of intersection.
		\return True if intersects, False otherwise.
	*/
	virtual bool intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal) = 0;
private:
	Material material;						/*!< Material of the PhysicalObject */
protected:
	const static Material DEFAULT_MATERIAL;	/*!< Default Material for PhysicalObjects. */
};
#endif
