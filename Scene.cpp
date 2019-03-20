#include "Scene.h"

Scene::Scene(const char* path)
{
	this->parseFile(path);
}

void Scene::render(const char* path) {
	const int width = glm::round(this->camera.getWidth());
	const int height = glm::round(this->camera.getHeight());
	std::printf("Width:%d Height:%d", width, height);
	float angle = glm::tan(glm::radians(this->camera.getFov() / 2));

	cimg_library::CImg<float> image(width, height, 1, 3, 0);


	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			float x = (2 * ((i + 0.5) / (float)width) - 1) * this->camera.getAspectRatio() * angle;
			float y = (1 - 2 * ((j + 0.5) / (float)height)) * angle;
			//float z = -this->camera.getFocalLength();
			float z = -1;
			// Should I substract the center of projection that is the position of the camera
			glm::vec3 rayDirection = glm::normalize(glm::vec3(x, y, z));
			Ray ray(this->camera.getPosition(), rayDirection);
			Color pixelColor = trace(ray);
			image(i, j, 0) = pixelColor.addColors().r * 255.0f;
			image(i, j, 1) = pixelColor.addColors().g * 255.0f;
			image(i, j, 2) = pixelColor.addColors().b * 255.0f;
		}
	}
	//image.save(path);
	cimg_library::CImgDisplay main_disp(image, "Render");
	while (!main_disp.is_closed()) {
		main_disp.wait();
	}
}

bool Scene::shadowTrace(Ray& shadowRay) {
	float t = INFINITY;
	for (int i = 0; i < this->objects.size(); i++) {
		if (this->objects[i]->intersect(shadowRay, t)) {
			return true;
		}
	}
	return false;
}

Color Scene::trace(Ray& ray) {
	Color color;
	// TODO
	float nearest_t = INFINITY;
	int indexClosestObject = -1;
	for (int i = 0; i < this->objects.size(); i++) {
		float t = INFINITY;
		if (this->objects[i]->intersect(ray, t)) {
			if (t < nearest_t) {
				nearest_t = t;
				indexClosestObject = i;
			}
		}
	}

	bool isInShadow = true;
	if (indexClosestObject != -1) {
		// Computer shadow ray
		isInShadow = false;
	}
	//
	return (!isInShadow)?this->objects[indexClosestObject]->getMaterial().getColor() : Color();
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