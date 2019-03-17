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

float Ray::x(float t)
{
	return this->origin.x + this->direction.x * t;
}

float Ray::y(float t)
{
	return this->origin.y + this->direction.y * t;
}

float Ray::z(float t)
{
	return this->origin.z + this->direction.z * t;
}
