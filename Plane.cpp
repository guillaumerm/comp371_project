#include "Plane.h"

const glm::vec3 Plane::DEFAULT_NORMAL = glm::vec3(0, 0, 0);

Plane::Plane() :Plane(Plane::DEFAULT_NORMAL, Plane::DEFAULT_POSITION, Plane::DEFAULT_MATERIAL) {
}

Plane::Plane(glm::vec3 normal, glm::vec3 position, Material material): PhysicalObject(position, material) {
	this->normal = normal;
}

bool Plane::intersect(Ray& ray, float& t) {
	float denominator = glm::dot(this->normal, ray.getDirection());
	
	// If denominator is 0 there is no intersection has the ray are parallel to the plane
	if (denominator == 0) {
		return false;
	}

	float numerator = -(glm::dot(this->normal, ray.getOrigin()) + glm::distance(this->getPosition(), ray.getOrigin()));
	float tmp = denominator / numerator;

	// If t <= 0, the intersection is behind the ray's origin
	if (tmp <= 0) {
		return false;
	}

	t = tmp;

	return true;
}

void Plane::parse(std::istream& input)
{
	std::string line;
	char colon = ':';

	std::istringstream lineStream;

	// Parse the normal
	std::getline(input, line);
	std::string stringNormal = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setNormal(readVec3(std::istringstream(stringNormal)));

	// Parse the position
	std::getline(input, line);
	std::string stringPosition = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setPosition(readVec3(std::istringstream(stringPosition)));

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

glm::vec3 Plane::calculateNormal(glm::vec3 position)
{
	return this->normal;
}

glm::vec3 Plane::getNormal() {
	return this->normal;
}

void Plane::setNormal(glm::vec3 normal) {
	this->normal = normal;
}