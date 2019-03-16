#include "Sphere.h"

Sphere::Sphere(glm::vec3 position, float radius, Material material) {
	this->position = position;
	this->radius = radius;
	this->material = material;
}

bool Sphere::intersect(Ray& ray, float& t) {
	float a = this->computeA(ray);
	float b = this->computeB(ray);
	float c = this->computeC(ray);

	// Abort if b^2 - 4ac is negative
	if (glm::pow(b, 2) - 4 * a * c < 0) {
		return false;
	}

	float t_0 = (-b + glm::sqrt(glm::pow(b, 2) - 4 * a * c)) / (2 * a);
	float t_1 = (-b - glm::sqrt(glm::pow(b, 2) - 4 * a * c)) / (2 * a);

	t = glm::min(t_0, t_1);
	return true;
};

float Sphere::computeA(Ray& ray) {
	return glm::pow(ray.getDirection().x, 2) + glm::pow(ray.getDirection().y, 2) + glm::pow(ray.getDirection().z, 2);
}

float Sphere::computeB(Ray& ray) {
	return 
		2 * (ray.getDirection().x * (ray.getOrigin().x - this->position.x) + 
		ray.getDirection().y * (ray.getOrigin().y - this->position.y) + 
		ray.getDirection().z * (ray.getOrigin().z - this->position.z));
}

float Sphere::computeC(Ray& ray) {
	return
		glm::pow(ray.getOrigin().x - this->position.x, 2) +
		glm::pow(ray.getOrigin().y - this->position.y, 2) +
		glm::pow(ray.getOrigin().z - this->position.z, 2);
}