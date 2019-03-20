#ifndef COLOR_H
#define COLOR_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Color {
public:
	Color();
	Color(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specularColor);
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
	void setAmbientColor(glm::vec3 ambientColor);
	void setDiffuseColor(glm::vec3 diffuseColor);
	void setSpecularColor(glm::vec3 specularColor);
	glm::vec3 addColors();
	friend const Color operator*(Color color, float value);
private:
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
protected:
	const static glm::vec3 DEFAULT_AMBIENT_COLOR;
	const static glm::vec3 DEFAULT_DIFFUSE_COLOR;
	const static glm::vec3 DEFAULT_SPECULAR_COLOR;
};
#endif