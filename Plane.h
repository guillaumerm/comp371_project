#ifndef PLANE_H
#define PLANE_H
#include "PHysicalObject.h"
#include "Material.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Plane : public PhysicalObject {
public:
	Plane();
	Plane(glm::vec3 normal, glm::vec3 position, Material material);
	glm::vec3 getNormal();
	bool intersect(Ray& ray, float& t);
	void parse(std::istream& input);
private:
	glm::vec3 normal;
	Material material;
protected:
	const static glm::vec3 DEFAULT_NORMAL;
};
#endif
