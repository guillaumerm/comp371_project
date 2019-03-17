#ifndef MESH_H
#define MESH_H
#include "PhysicalObject.h"
#include "Material.h"
#include "Ray.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Mesh: public PhysicalObject {
public:
	Mesh();
	Mesh(const char* path, Material material);
	bool intersect(Ray& ray, float& t);
	void parse(std::istream& input);
protected:
	const static Material DEFAULT_MATERIAL;
};
#endif