#include "Scene.h"

inline bool Scene::parseFile(const char* path) {
	std::ifstream inFile;
	inFile.open(path);

	if (!inFile) {
		std::fprintf(stderr, "Unable to open scene file.");
		exit(1);
	}

	// Get the number of objects in the scene
	int numberOfObjects;
	inFile >> numberOfObjects;

	for (int i = 0; i < numberOfObjects; i++) {
		std::string objectType;
		std::getline(inFile, objectType);

		if (objectType == "camera") {
			this->camera.parse(inFile);
		}
		else if (objectType == "sphere") {
			
		}
		else if (objectType == "mesh") {
		
		}
		else if (objectType == "light") {
		
		} else{
			std::fprintf(stderr, "Unknown object type.");
			exit(1);
		}
	}

	inFile.close();
}