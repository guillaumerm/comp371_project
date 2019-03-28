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
	float temp = INFINITY;
	glm::vec3 potentialPoint;
	glm::vec3 potentialNormal;

	// Step #1 see if the ray intersects with the plane containing a polygon
	int numberTriangles = this->indices.size() / 3;
	glm::vec3 A;
	glm::vec3 B;
	glm::vec3 C;
	for (int i = 0; i < numberTriangles; i++) {
		glm::vec3& current_A = this->vertices[this->indices[3 * i]];
		glm::vec3& current_B = this->vertices[this->indices[3 * i + 1]];
		glm::vec3& current_C = this->vertices[this->indices[3 * i + 2]];
		Plane plane(glm::cross(current_B - current_A, current_C - current_A), current_A, Material());
		float current_t = INFINITY;
		glm::vec3 point;
		glm::vec3 normal;
		if (plane.intersect(ray, current_t, point, normal) && temp < current_t < temp) {
			temp = current_t;
			potentialPoint = point;
			potentialNormal = normal;
			A = current_A;
			B = current_B;
			C = current_C;
		}
	}

	// No intersection with the plane that contains the polygon.
	if (temp == INFINITY) {
		return false;
	}

	
	// Step #2 see if the ray intersection point is within the triangle (Point-in-triangle test)
	float denom = glm::dot(potentialNormal, potentialNormal);

	glm::vec3 M;
	glm::vec3& P = potentialPoint;
	glm::vec3& v0 = A;
	glm::vec3& v1 = B;
	glm::vec3& v2 = C;

	// Barycentric Coordinates
	float u;
	float v;
	float w;

	// edge0
	glm::vec3 edge0 = v1 - v0;
	glm::vec3 vp0 = P - v0;
	M = glm::cross(edge0, vp0);
	if (glm::dot(potentialNormal, M) < 0) return false;

	// edge1
	glm::vec3 edge1 = v2 - v1;
	glm::vec3 vp1 = P - v1;
	M = glm::cross(edge1, vp1);
	if ((u = glm::dot(potentialNormal, M)) < 0) return false;

	// edge2
	glm::vec3 edge2 = v0 - v2;
	glm::vec3 vp2 = P - v2;
	M = glm::cross(edge2, vp2);
	if ((v = glm::dot(potentialNormal, M)) < 0) return false;

	u /= denom;
	v /= denom;
	w = 1 - u - v;

	t = temp;
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

#ifndef DEBUG
	std::string stringPath = trim(line.substr(line.find(colon) + 1, line.length()));
#else
	std::string stringPath = "./scenes/" + trim(line.substr(line.find(colon) + 1, line.length()));
#endif

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
