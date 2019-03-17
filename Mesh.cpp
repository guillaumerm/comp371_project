#include "Mesh.h"

const Material Mesh::DEFAULT_MATERIAL = Material();

Mesh::Mesh():Mesh("", Mesh::DEFAULT_MATERIAL)
{
}

Mesh::Mesh(const char* path, Material material) : PhysicalObject(Mesh::DEFAULT_POSITION, material) {
	if (path != "") {
		//this->loadOBJ(path);
	}
}

bool Mesh::intersect(Ray& ray, float& t)
{
	return false;
}

void Mesh::parse(std::istream& input)
{
}
