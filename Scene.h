#ifndef SCENE_H
#define SCENE_H
#include "Color.h"
#include "Object.h"
#include "Camera.h"
#include "PhysicalObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "Mesh.h"
#include "Light.h"
#include "Ray.h"
#include "Utils.h"
#include "./CImg.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <limits>

class Scene {
public:
	Scene(const char *path);
	void render(const char* path);
private:
	std::vector<PhysicalObject*> objects;
	std::vector<Light> lights;
	Camera camera;
	bool parseFile(const char* path);
	glm::vec3 trace(Ray& ray);
	bool shadowTrace(Ray& shadowRay);
};
#endif
