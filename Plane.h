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
	Plane();
	Plane(glm::vec3 normal, glm::vec3 position, Material material);
	glm::vec3 getNormal();
	void setNormal(glm::vec3 normal);
	bool intersect(Ray& ray, float& t, glm::vec3& intersectionPoint, glm::vec3& intersectionNormal);
	void parse(std::istream& input);
private:
	glm::vec3 normal;
protected:
	const static glm::vec3 DEFAULT_NORMAL;
};
#endif
