#include "Plane.h"

const glm::vec3 Plane::DEFAULT_NORMAL = glm::vec3(0, 0, 0);

Plane::Plane() :Plane(Plane::DEFAULT_NORMAL, Plane::DEFAULT_POSITION, Plane::DEFAULT_MATERIAL) {
}

Plane::Plane(glm::vec3 normal, glm::vec3 position, Material material): PhysicalObject(position, material) {
	this->normal = normal;
}

bool Plane::intersect(Ray& ray, float& t) {
	float temp = glm::dot(this->getPosition() - ray.getOrigin(), this->normal) / glm::dot(ray.getDirection(), this->normal);
	if (temp >= 0) {
		t = temp;
		return true;
	}
	else {
		return false;
	}
}

void Plane::parse(std::istream& input)
{
}

glm::vec3 Plane::getNormal() {
	return this->normal;
}