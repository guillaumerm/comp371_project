#ifndef LIGHT_H
#define LIGHT_H
#include "Color.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Light {
public:
	Light(glm::vec3 position, Color color);
	glm::vec3 getPosition();
	Color getColor();
private:
	Color color;
};
#endif