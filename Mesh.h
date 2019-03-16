#ifndef MESH_H
#define MESH_H
#include "Object.h"
#include "Color.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Mesh: virtual Object {
public:
	Mesh(const char* path, Color* color);
	bool intersect(Ray& ray);
};
#endif