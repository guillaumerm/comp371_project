#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Ray.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"
#include "Plane.h"

class Triangle {
public:
	Triangle(glm::vec3 &v0, glm::vec3 &v1, glm::vec3 &v2, glm::vec3 normal);
	bool intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal);
private:
	glm::vec3 v0;
	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 normal;
};
#endif
