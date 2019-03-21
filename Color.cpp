#include "Color.h"

const glm::vec3 Color::DEFAULT_AMBIENT_COLOR = glm::vec3(0, 0, 0);

const glm::vec3 Color::DEFAULT_DIFFUSE_COLOR = glm::vec3(0, 0, 0);

const glm::vec3 Color::DEFAULT_SPECULAR_COLOR = glm::vec3(0, 0, 0);

Color::Color(): Color(Color::DEFAULT_AMBIENT_COLOR, Color::DEFAULT_DIFFUSE_COLOR, Color::DEFAULT_SPECULAR_COLOR)
{
}

Color::Color(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specularColor)
{
	this->setAmbientColor(ambientColor);
	this->setDiffuseColor(diffuseColor);
	this->setSpecularColor(specularColor);
}

glm::vec3 Color::getAmbientColor() {
	return this->ambientColor;
}

glm::vec3 Color::getDiffuseColor() {
	return this->diffuseColor;
}

glm::vec3 Color::getSpecularColor() {
	return this->specularColor;
}

void Color::setAmbientColor(glm::vec3 ambientColor) {
	this->ambientColor = ambientColor;
}

void Color::setDiffuseColor(glm::vec3 diffuseColor) {
	this->diffuseColor = diffuseColor;
}

void Color::setSpecularColor(glm::vec3 specularColor) {
	this->specularColor = specularColor;
}

glm::vec3 Color::addColors()
{
	return this->ambientColor + this->diffuseColor + this->specularColor;
}

const Color operator*(Color &color, float value)
{
	return Color(value * color.getAmbientColor(), value * color.getDiffuseColor(), value * color.getSpecularColor());
}

const Color operator+(Color &color1, Color &color2)
{
	return Color(color1.getAmbientColor() + color2.getAmbientColor(), color1.getDiffuseColor() + color2.getDiffuseColor(), color1.getSpecularColor() + color2.getSpecularColor());
}

const Color operator*(Color color1, Color color2)
{
	return Color(color1.getAmbientColor() * color2.getAmbientColor(), color1.getDiffuseColor() * color2.getDiffuseColor(), color1.getSpecularColor() * color2.getSpecularColor());
}
