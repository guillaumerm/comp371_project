#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include <sstream>

#include "Object.h"
#include "Utils.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Camera: virtual Object {
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
private:
	const static float DEFAULT_FOV;
	const static float DEFAULT_FOCAL_LENGTH;
	const static float DEFAULT_ASPECT_RATIO;
	float fov;
	float focalLength;
	float aspectRatio;
};

std::string trim(std::string str)
{
	// remove trailing white space
	while (!str.empty() && std::isspace(str.back())) str.pop_back();

	// return residue after leading white space
	std::size_t pos = 0;
	while (pos < str.size() && std::isspace(str[pos])) ++pos;
	return str.substr(pos);
}
#endif
