#include "Plane.h"

Plane::Plane(glm::vec3 normal, glm::vec3 position, Material material) {
	this->normal = normal;
	this->position = position;
	this->material = material;
}

bool Plane::intersect(Ray& ray, float& t) {
	float temp = glm::dot(this->position - ray.getOrigin(), this->normal) / glm::dot(ray.getDirection(), this->normal);
	if (temp >= 0) {
		t = temp;
		return true;
	}
	else {
		return false;
	}
}

glm::vec3 Plane::getNormal() {
	return this->normal;
}

glm::vec3 Plane::getPositition() {
	return this->position;
}