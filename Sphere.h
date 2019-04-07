#ifndef SPHERE_H
#define SPHERE_H
#include <string>
#include <sstream>
#include "Utils.h"
#include "Ray.h"
#include "PhysicalObject.h"
#include "Material.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Sphere: public PhysicalObject {
public:
	//! A constructor which creates an empty Sphere object.
	Sphere();

	//! A constructor which creates a Sphere object with the specified position, radius and meterial
	/*!
		\param position position of the object relative to world origin
		\param radius length of raidus
	*/
	Sphere(glm::vec3 position, float radius, Material material);

	//! Verifies if Sphere intersects with a given Ray.
	/*!
		\param ray Ray which is checked.
		\param intersectionPoint point at which the ray intersects.
		\param intersectionNormal normal at the intersection point.
	*/
	bool intersect(Ray &ray, float &t, glm::vec3& intersectionPoint, glm::vec3& intersectionNormal);
	void parse(std::istream& input);
	float getRadius();
	void setRadius(float radius);
private:
	float radius;
	float computeB(Ray& ray);
	float computeC(Ray& ray);
	float computeA(Ray& ray);
protected:
	const static float DEFAULT_RADIUS;
};
#endif
