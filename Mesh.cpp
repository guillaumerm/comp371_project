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
	std::string line;
	char colon = ':';

	std::istringstream lineStream;

	// Read object file
	std::getline(input, line);
	std::string stringPath = "./scenes/" + trim(line.substr(line.find(colon) + 1, line.length()));
	loadOBJ(stringPath.c_str(), this->indices, this->vertices, this->normals, this->UVs);

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
