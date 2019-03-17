#include "Scene.h"

Scene::Scene(const char* path)
{
	this->parseFile(path);
}

void Scene::render(const char* path) {

}

Color Scene::trace(Ray& ray, int depth) {
	Color color;
	// TODO
	float t = INFINITY;
	for (int i = 0; i < this->objects.size(); i++) {
		if (this->objects[i]->intersect(ray, t)) {
			// Cast Shadow ray
			//  if(not in shadow)
			//		calculate illumination
			//	else
			//		set to zero/ambient
		}
	}
	//
	return color;
}

bool Scene::parseFile(const char* path) {
	std::ifstream inFile;
	inFile.open(path);

	if (!inFile) {
		std::fprintf(stderr, "Unable to open scene file.");
		exit(1);
	}

	// Get the number of objects in the scene
	std::string stringNumberOfObjects;
	int numberOfObjects;

	std::getline(inFile, stringNumberOfObjects);
	numberOfObjects = std::stoi(stringNumberOfObjects);

	for (int i = 0; i < numberOfObjects; i++) {
		std::string objectType;
		std::getline(inFile, objectType);

		if (objectType == "camera") {
			this->camera.parse(inFile);
		}
		else if (objectType == "sphere") {
			Sphere *sphere = new Sphere();
			sphere->parse(inFile);
			this->objects.push_back(sphere);
		}
		else if (objectType == "mesh") {
			Mesh *mesh = new Mesh();
			mesh->parse(inFile);
			this->objects.push_back(mesh);
		}
		else if (objectType == "plane") {
			Plane *plane = new Plane();
			plane->parse(inFile);
			this->objects.push_back(plane);
		}else if (objectType == "light") {
			Light light;
			light.parse(inFile);
			this->lights.push_back(light);
		} else{
			std::fprintf(stderr, "Unknown object type.");
			exit(1);
		}
	}

	inFile.close();
}