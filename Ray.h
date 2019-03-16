#ifndef RAY_H
#define RAY_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Ray {
public:
	Ray(glm::vec3 origin, glm::vec3 direction);
	glm::vec3 getDirection();
	glm::vec3 getOrigin();
private:
	glm::vec3 origin;
	glm::vec3 direction;
};
#endif
