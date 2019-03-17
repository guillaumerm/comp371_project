#include "Light.h"

const Color Light::DEFAULT_COLOR = Color();

Light::Light():Light(Light::DEFAULT_POSITION, Light::DEFAULT_COLOR)
{
}

Light::Light(glm::vec3 position, Color color) : Object(position) {
	this->setColor(color);
}

void Light::setColor(Color color) {
	this->color = color;
}

Color Light::getColor() {
	return this->color;
}

void Light::parse(std::istream& input) {
	std::string line;
	char colon = ':';

	std::istringstream lineStream;

	// Parse the position
	std::getline(input, line);
	std::string stringPosition = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setPosition(readVec3(std::istringstream(stringPosition)));

	Color color;

	// Parse diffuse color
	std::getline(input, line);
	std::string stringDiffuseColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setDiffuseColor(readVec3(std::istringstream(stringDiffuseColor)));

	// Parse specular color
	std::getline(input, line);
	std::string stringSpecularColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setSpecularColor(readVec3(std::istringstream(stringSpecularColor)));

	this->setColor(color);
}
