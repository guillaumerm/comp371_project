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
#include "Plane.h"
#include "Utils.h"
#include "Triangle.h"

class Mesh: public PhysicalObject {
public:
	
	//! A constructor which creates a default empty Mesh instance
	Mesh();

	//! A constructor which creates a mesh from a OBJ file with a specified Material.
	/*!
		\param path path to the OBJ file
		\param material Material of the mesh
	*/
	Mesh(const char* path, Material material);

	//! Verifies if their is an instersection with a given ray. Calculates the t, point of intersection and normal.
	/*!
		\param ray Ray that is being tested for intersection.
		\param t smallest positive root for the geometric query.
		\param intersectionPoint point at which the ray intersects the mesh.
		\param intersectionNormal normal at the intersectionPoint.
		\return True if intersects, False otherwise
	*/
	bool intersect(Ray& ray, float& t, glm::vec3& intersectionPoint, glm::vec3& intersectionNormal);
	
	//! Mutates the Mesh to the parameters read from the input stream.
	/*!
		\param input the input stream that contains the Mesh new parameters.
	*/
	void parse(std::istream& input);
protected:
	const static Material DEFAULT_MATERIAL;		/*!< Default Mesh Material */
	std::vector<glm::vec3> normals;				/*!< Normals for the vertices */
	std::vector<glm::vec3> vertices;			/*!< Vertices of mesh */
	std::vector<glm::vec2> UVs;					/*!< UVs of mesh */
	std::vector<Triangle> faces;				/*!< Triangle faces of the mesh */
	std::vector<int> indices;					/*!< Edge list */
};
#endif