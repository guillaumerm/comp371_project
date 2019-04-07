#include "Triangle.h"

Triangle::Triangle(glm::vec3 &v0, glm::vec3 &v1, glm::vec3 &v2, glm::vec3 normal) {
	this->v0 = v0;
	this->v1 = v1;
	this->v2 = v2;
	this->normal = normal;
}

bool Triangle::intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal) {
	float potential_t = INFINITY;
	glm::vec3 potential_point;
	glm::vec3 potential_normal;

	// Step 1 - Intersects with the plane containing the triangel
	Plane plane(this->normal, this->v0, Material());

	if (!plane.intersect(ray, potential_t, potential_point, potential_normal)) {
		return false;
	}


	// Step 2 - Point-in-triangle Test 
	// (adapted from https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle)

	// Verifies if angle formed by p,v0,v1 is positive, else not in triangle v0,v1,v2
	glm::vec3 edge0_1 = this->v1 - this->v0;
	glm::vec3 vec0_p = potential_point - this->v0;
	if (glm::dot(potential_normal, glm::cross(edge0_1, vec0_p)) < 0) {
		return false;
	}

	// Verifies if angle formed by p,v1,v2 is positive, else not in triangle v0,v1,v2
	glm::vec3 edge1_2 = this->v2 - this->v1;
	glm::vec3 vec1_p = potential_point - this->v1;
	if (glm::dot(this->normal, glm::cross(edge1_2, vec1_p)) < 0) {
		return false;
	}

	// Verifies if angle formed by p,v0,v2 is positive, else not in triangle v0,v1,v2
	glm::vec3 edge2_0 = this->v0 - this->v2;
	glm::vec3 vec2_p = potential_point - this->v2;
	if (glm::dot(this->normal, glm::cross(edge2_0, vec2_p)) < 0) {
		return false;
	}

	// Intersection point is valid return values
	t = potential_t;
	intersectionPoint = potential_point;
	intersectionNormal = this->normal;

	return true;
}