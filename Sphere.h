#ifndef SPHERE_H
#define SPHERE_H
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
	bool intersect(Ray &ray, float &t);
	void parse(std::istream& input);
private:
	glm::vec3 position;
	float radius;
	float computeB(Ray& ray);
	float computeC(Ray& ray);
	float computeA(Ray& ray);
	float computeRoot(Ray& ray);
protected:
	const static float DEFAULT_RADIUS;
};
#endif
