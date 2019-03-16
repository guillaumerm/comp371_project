#include "Object.h"

const glm::vec3 DEFAULT_POSITION = glm::vec3(0, 0, 0);

Object::Object():Object(Object::DEFAULT_POSITION) {
	// Left Empty
}

Object::Object(glm::vec3 position) {
	this->setPosition(position);
}

glm::vec3 Object::getPosition() {
	return this->position;
}

void Object::setPosition(glm::vec3 position) {
	this->position = position;
}