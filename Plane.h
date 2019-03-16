#ifndef PLANE_H
#define PLANE_H
#include "PHysicalObject.h"
#include "Material.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Plane : virtual PhysicalObject {
public:
	Plane(glm::vec3 normal, glm::vec3 position, Material material);
	glm::vec3 getNormal();
	glm::vec3 getPositition();
	bool intersect(Ray& ray, float& t);
private:
	glm::vec3 position;
	glm::vec3 normal;
	Material material;
};
#endif
