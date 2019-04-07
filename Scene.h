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
	//! A contructor which construct a scene from a particular text file.
	/*!
		\param path path to a scene text file.
	*/
	Scene(const char *path);

	//! Renders the scene to a specific image file.
	/*!
		\param path path to the image file.
	*/
	bool render(const char* path);
private:
	std::vector<PhysicalObject*> objects;		/*!< Objects in the scene */
	std::vector<Light> lights;					/*!< Lights in the scene */
	Camera camera;								/*!< Camera from which the scene is rendering from */

	//! Scene text file parser. Converts an scene text file with the appropriate syntax to a scene.
	/*!
		\param path path to a scene text file.
	*/
	bool parseFile(const char* path);

	//! Tace a specific Ray in the scene. Geometric queries are run on each objects to determine if any intersection occurs.
	/*!
		\param ray ray to be traced.
		\return glm::vec3 containing the color of the pixel.
	*/
	glm::vec3 trace(Ray& ray);

	//! Verifies if a shadow ray is block by any object.
	/*!
		\param shadowRay ray shot from intersection to light source.
		\param True if blocked, false otherwise.
	*/
	bool shadowTrace(Ray& shadowRay);
};
#endif
