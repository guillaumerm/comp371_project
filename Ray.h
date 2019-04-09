#ifndef RAY_H
#define RAY_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Ray {
public:
	//! A constructor which creates a Ray with a specified origin and direction.
	/*!
		\param origin origin of the ray.
		\param direction tracing direction of the ray.
	*/
	Ray(glm::vec3 origin, glm::vec3 direction);

	//! Obtain the direction of the Ray.
	/*!
		\return The direction of the Ray.
	*/
	glm::vec3 getDirection();

	//! Obtain the origin of the Ray.
	/*!
		\param The origin of the Ray.
	*/
	glm::vec3 getOrigin();
private:
	glm::vec3 origin;		/*!< Origin of the Ray. */
	glm::vec3 direction;	/*!< Direction of the Ray. */
};
#endif
