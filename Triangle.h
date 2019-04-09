#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Ray.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"
#include "Plane.h"

class Triangle {
public:
	//! A constructor which creates a Triangle with the specified v0, v1, v2 and normal.
	Triangle(glm::vec3 &v0, glm::vec3 &v1, glm::vec3 &v2, glm::vec3 normal);

	//! Verifies if Triangle intersects with a given Ray.
	/*!
		\param ray Ray which is checked.
		\param intersectionPoint point at which the ray intersects.
		\param intersectionNormal normal at the intersection point.
	*/
	bool intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal);
private:
	glm::vec3 v0;		/*!< First vertex of the Triangle */
	glm::vec3 v1;		/*!< Second vertex of the Triangle */
	glm::vec3 v2;		/*!< Third vertex of the Triangle */
	glm::vec3 normal;	/*!< Normal of the Triangle */
};
#endif
