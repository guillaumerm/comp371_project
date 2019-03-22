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
	Sphere();
	Sphere(glm::vec3 position, float radius, Material material);
	bool intersect(Ray &ray, float &t, glm::vec3& intersectionPoint, glm::vec3& intersectionNormal);
	void parse(std::istream& input);
	float getRadius();
	void setRadius(float radius);
	glm::vec3 calculateNormal(glm::vec3 position);
private:
	glm::vec3 position;
	float radius;
	float computeB(Ray& ray);
	float computeC(Ray& ray);
	float computeA(Ray& ray);
protected:
	const static float DEFAULT_RADIUS;
};
#endif
