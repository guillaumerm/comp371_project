#ifndef MESH_H
#define MESH_H
#include <string>
#include <sstream>
#include <vector>
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"
#include "PhysicalObject.h"
#include "OBJLoader.h"
#include "Material.h"
#include "Ray.h"
#include "Utils.h"

class Mesh: public PhysicalObject {
public:
	Mesh();
	Mesh(const char* path, Material material);
	bool intersect(Ray& ray, float& t);
	void parse(std::istream& input);
	glm::vec3 calculateNormal(glm::vec3 position);
protected:
	const static Material DEFAULT_MATERIAL;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> UVs;
	std::vector<int> indices;
};
#endif