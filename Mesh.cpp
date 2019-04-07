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

bool Mesh::intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal)
{
	float potential_t = INFINITY;
	glm::vec3 potentialPoint;
	glm::vec3 potentialNormal;


	for (int i = 0; i < this->faces.size(); i++) {

		float current_t = INFINITY;
		glm::vec3 current_point;
		glm::vec3 current_normal;

		if (this->faces[i].intersect(ray, current_t, current_point, current_normal) && current_t < potential_t) {
			potential_t = current_t;
			potentialPoint = current_point;
			potentialNormal = current_normal;
		}
	}

	if (potential_t == INFINITY) {
		return false;
	}

	t = potential_t;
	intersectionPoint = potentialPoint;
	intersectionNormal = potentialNormal;
	return true;
}

void Mesh::parse(std::istream& input)
{
	std::string line;
	char colon = ':';

	std::istringstream lineStream;

	// Read object file
	std::getline(input, line);

	std::string stringOBJPath = trim(line.substr(line.find(colon) + 1, line.length()));

	loadOBJ(stringOBJPath.c_str(), this->indices, this->vertices, this->normals, this->UVs);

	// Construct triangle from the indices read from the OBJ file
	int numberOfTriangles = this->indices.size() / 3;

	for (int i = 0; i < numberOfTriangles; i++) {
		glm::vec3& v0 = this->vertices[this->indices[3*i]];
		glm::vec3& v1 = this->vertices[this->indices[3*i + 1]];
		glm::vec3& v2 = this->vertices[this->indices[3*i + 2]];
		glm::vec3 normal = glm::cross(v1 - v0, v2 - v0);
		this->faces.push_back(Triangle(v0, v1, v2, normal));
	}

	Color color;
	Material material;

	// Parse ambient color
	std::getline(input, line);
	std::string stringAmbientColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setAmbientColor(readVec3(std::istringstream(stringAmbientColor)));

	// Parse diffuse color
	std::getline(input, line);
	std::string stringDiffuseColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setDiffuseColor(readVec3(std::istringstream(stringDiffuseColor)));

	// Parse specular color
	std::getline(input, line);
	std::string stringSpecularColor = trim(line.substr(line.find(colon) + 1, line.length()));
	color.setSpecularColor(readVec3(std::istringstream(stringSpecularColor)));

	material.setColor(color);

	// Prase shininess
	std::getline(input, line);
	std::string stringShininess = trim(line.substr(line.find(colon) + 1, line.length()));
	material.setShininess(std::stof(stringShininess));

	this->setMaterial(material);
}

glm::vec3 Mesh::calculateNormal(glm::vec3 position)
{
	return glm::vec3();
}
