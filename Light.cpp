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
	// TODO
}
