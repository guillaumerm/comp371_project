#include "Ray.h"

Ray::Ray(glm::vec3 origin, glm::vec3 direction)
{
}

glm::vec3 Ray::getDirection()
{
	return this->direction;
}

glm::vec3 Ray::getOrigin()
{
	return this->origin;
}
