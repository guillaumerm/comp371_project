#ifndef MATERIAL_H
#define MATERIAL_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Color {
public:
	Color(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specularColor);
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
private:
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
};
#endif