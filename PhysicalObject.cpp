#include "PhysicalObject.h"

const Material PhysicalObject::DEFAULT_MATERIAL = Material();

PhysicalObject::PhysicalObject() : PhysicalObject(Object::DEFAULT_POSITION, PhysicalObject::DEFAULT_MATERIAL) {}

PhysicalObject::PhysicalObject(glm::vec3 position, Material material): Object(position) {
	this->setMaterial(material);
}

void PhysicalObject::setMaterial(Material material) {
	this->material = material;
}

Material PhysicalObject::getMaterial() {
	return this->material;
}