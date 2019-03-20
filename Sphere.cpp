#include "Sphere.h"

const float Sphere::DEFAULT_RADIUS = 0.0f;

Sphere::Sphere():Sphere(Sphere::DEFAULT_POSITION, Sphere::DEFAULT_RADIUS, Sphere::DEFAULT_MATERIAL) {
}

Sphere::Sphere(glm::vec3 position, float radius, Material material):PhysicalObject(position, material) {
	this->radius = radius;
}

bool Sphere::intersect(Ray& ray, float& t) {
	float a = this->computeA(ray);
	float b = this->computeB(ray);
	float c = this->computeC(ray);

	float discriminant = glm::pow(b, 2) - (4.0f * a * c);

	// Abort if b^2 - 4ac is negative
	if (discriminant < 0) {
		return false;
	}

	float t_0 = (-b - glm::sqrt(discriminant)) / (2 * a);
	float t_1 = (-b + glm::sqrt(discriminant)) / (2 * a);

	if (t_1<0) {
		return false;
	}
//	else if (t_0 <= 0 && t_1 > 0) {
//		t = t_1;
//	}
	else {
		t = glm::min(t_0, t_1);
	}

	return true;
}

glm::vec3 Sphere::calculateNormal(glm::vec3 position) {
	return (1 / this->radius) * glm::vec3(
		(position.x - this->position.x),
		(position.y - this->position.y),
		(position.z - this->position.z)
	);
}

float Sphere::computeA(Ray& ray) {
	return glm::dot(ray.getDirection(), ray.getDirection());
}

float Sphere::computeB(Ray& ray) {
	return
		2 * (ray.getDirection().x * (ray.getOrigin().x - this->position.x) +
			ray.getDirection().y * (ray.getOrigin().y - this->position.y) +
			ray.getDirection().z * (ray.getOrigin().z - this->position.z));
}

float Sphere::computeC(Ray & ray) {
	return
		glm::pow(ray.getOrigin().x - this->position.x, 2) +
		glm::pow(ray.getOrigin().y - this->position.y, 2) +
		glm::pow(ray.getOrigin().z - this->position.z, 2) -
		glm::pow(this->radius, 2);
}

void Sphere::setRadius(float radius) {
	this->radius = radius;
}

float Sphere::getRadius() {
	return this->radius;
}

void Sphere::parse(std::istream& input)
{
	std::string line;
	char colon = ':';

	std::istringstream lineStream;

	// Parse the position
	std::getline(input, line);
	std::string stringPosition = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setPosition(readVec3(std::istringstream(stringPosition)));

	// Prase radius
	std::getline(input, line);
	std::string stringRadius = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setRadius(std::stof(stringRadius));

	Color color;
	Material material;

	// Parse ambient color
	std::getline(input, line);
	std::string stringAmbientColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setAmbientColor(readVec3(std::istringstream(stringAmbientColor)));

	// Parse diffuse color
	std::getline(input, line);
	std::string stringDiffuseColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setDiffuseColor(readVec3(std::istringstream(stringDiffuseColor)));

	// Parse specular color
	std::getline(input, line);
	std::string stringSpecularColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setSpecularColor(readVec3(std::istringstream(stringSpecularColor)));

	material.setColor(color);

	// Prase shininess
	std::getline(input, line);
	std::string stringShininess = trim(line.substr(line.find(colon) + 1, line.length()));
	material.setShininess(std::stof(stringShininess));

	this->setMaterial(material);
}