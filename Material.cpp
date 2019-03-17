#include "Material.h"

const Color Material::DEFAULT_COLOR = Color();
const int Material::DEFAULT_SHININESS = 0;

Material::Material():Material(Material::DEFAULT_COLOR, Material::DEFAULT_SHININESS)
{
}

Material::Material(Color color, float shininess)
{
	this->setColor(color);
	this->setShininess(shininess);
}

Color Material::getColor()
{
	return this->color;
}

float Material::getShininess()
{
	return this->shininess;
}

void Material::setColor(Color color)
{
	this->color = color;
}

void Material::setShininess(float shininess)
{
	this->shininess = shininess;
}
