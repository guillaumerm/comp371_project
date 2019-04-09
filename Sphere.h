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

	//! Mutates the Sphere to the parameters read from the input stream.
	/*!
		\param input the input stream that contains the Sphere new parameters.
	*/
	void parse(std::istream& input);

	//! Obtain the radius of the Sphere.
	/*!
		\return The radius of the Sphere.
	*/
	float getRadius();

	//! Mutates the radius of the Sphere.
	/*!
		\param radius new radius of the Sphere.
	*/
	void setRadius(float radius);
private:
	float radius;						/*!< Raidus of the Sphere. */

	//! Calculates the "b" component of the root equation.
	/*!
		\param ray ray which contains p_0 (origin coordinates) and d (direction vector).
		\return The value of "b" of the root equation.
	*/
	float computeB(Ray& ray);

	//! Calculates the "C" component of the root equation.
	/*!
		\param ray ray which contains p_0 (origin coordinates) and d (direction vector).
		\return The value of "c" of the root equation.
	*/
	float computeC(Ray& ray);

	//! Calculates the "a" component of the root equation.
	/*!
		\param ray ray which contains p_0 (origin coordinates) and d (direction vector).
		\return The value of "a" of the root equation.
	*/
	float computeA(Ray& ray);
protected:
	const static float DEFAULT_RADIUS;	/*!< Default radius for Spheres. */
};
#endif
