#ifndef PLANE_H
#define PLANE_H
#include <string>
#include <sstream>

#include "PhysicalObject.h"
#include "Material.h"
#include "Utils.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Plane : public PhysicalObject {
public:
	//! A constructor which creates a default Plane.
	Plane();

	//! A constructor which creates a Plane with a specified normal, position and material.
	/*!
		\param normal normal of the Plane.
		\param position position of the Plane.
		\param material Material of the Plane.
	*/
	Plane(glm::vec3 normal, glm::vec3 position, Material material);

	//! Obtain the normal of the Plane.
	/*!
		\return The normal of the Plane.
	*/
	glm::vec3 getNormal();

	//! Mutates the normal of the Plane.
	/*!
		\param normal new normal of the Plane.
	*/
	void setNormal(glm::vec3 normal);

	//! Verifies if a ray intersects with the Plane. If it does then t, intersectionPoint and intersectionNormal gets the values calculated.
	/*!
		\param ray Ray that is being tested for intersection.
		\param t result from the geometric query.
		\param intersectionPoint point of intersection between the Plane and the Ray.
		\param intersectionNormal normal at the point of intersection.
		\return True if intersects, False otherwise.
	*/
	bool intersect(Ray& ray, float& t, glm::vec3& intersectionPoint, glm::vec3& intersectionNormal);

	//! Mutates the Plane to the parameters read from the input stream.
	/*!
		\param input the input stream that contains the Object new parameters.
	*/
	void parse(std::istream& input);
private:
	glm::vec3 normal;						/*!< Normal of the Plane. */
protected:
	const static glm::vec3 DEFAULT_NORMAL; /*!< Default normal for Planes. */
};
#endif
