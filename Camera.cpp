#include "Camera.h"

const float Camera::DEFAULT_FOV = 0.0f;
const float Camera::DEFAULT_ASPECT_RATIO = 0.0f;
const float Camera::DEFAULT_FOCAL_LENGTH = 0.0f;

Camera::Camera() : Camera(Object::DEFAULT_POSITION,Camera::DEFAULT_FOV, Camera::DEFAULT_FOCAL_LENGTH, Camera::DEFAULT_ASPECT_RATIO) {
	// Left Empty
}

Camera::Camera(glm::vec3 position, float fov, float focalLength, float aspectRatio) : Object(position) {
	this->fov = fov;
	this->focalLength = focalLength;
	this->aspectRatio = aspectRatio;
}

void Camera::setFov(float fov) {
	this->fov = fov;
}

void Camera::setAspectRatio(float aspectRatio) {
	this->aspectRatio = aspectRatio;
}

void Camera::setFocalLength(float focalLength) {
	this->focalLength = focalLength;
}

float Camera::getFov() {
	return this->fov;
}

float Camera::getFocalLength() {
	return this->focalLength;
}

float Camera::getAspectRatio() {
	return this->aspectRatio;
}

void Camera::parse(std::istream& input) {
	std::string line;
	char colon = ':';

	std::istringstream lineStream;
	
	// Parse the postion
	std::getline(input, line);
	std::string stringPosition = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setPosition(readVec3(std::istringstream(stringPosition)));

	// Parse the fov
	std::getline(input, line);
	std::string stringFov = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setFov(std::stof(stringFov));

	// Parse focal length
	std::getline(input, line);
	std::string stringFocalLength = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setFocalLength(std::stof(stringFocalLength));

	// Prase aspect ratio
	std::getline(input, line);
	std::string stringAspectRatio = trim(line.substr(line.find(colon) + 1, line.length()));
	this->setAspectRatio(std::stof(stringAspectRatio));
}