#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include <sstream>

#include "Object.h"
#include "Utils.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Camera: public Object {
public:
	Camera();
	Camera(glm::vec3 position, float fov, float focalLength, float aspectRatio);
	float getFov();
	float getFocalLength();
	float getAspectRatio();
	void setFov(float fov);
	void setFocalLength(float focalLength);
	void setAspectRatio(float aspectRatio);
	void parse(std::istream& input);
	float getWidth();
	float getHeight();
private:
	const static float DEFAULT_FOV;
	const static float DEFAULT_FOCAL_LENGTH;
	const static float DEFAULT_ASPECT_RATIO;
	float fov;
	float focalLength;
	float aspectRatio;
};
#endif
