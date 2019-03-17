#include "Scene.h"

Scene::Scene(const char* path)
{
	this->parseFile(path);
}

void Scene::render(const char* path) {
	const int width = this->camera.getWidth() * this->camera.getFocalLength();
	const int height = this->camera.getHeight() * this->camera.getFocalLength();
	cimg_library::CImg<float> image(width, height, 1, 3, 0);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float x = ((i < width / 2)?-1:1)*this->camera.getAspectRatio() * glm::tan(glm::radians(this->camera.getFov()) / 2); 
			float y = ((j < height / 2)?-1:1)*glm::tan(glm::radians(this->camera.getFov()) / 2); 
			float z = -this->camera.getFocalLength();

			glm::vec3 rayDirection = glm::normalize(glm::vec3(x, y, z) - this->camera.getPosition());
			Ray ray(this->camera.getPosition(), rayDirection);
			Color pixelColor = trace(ray, -this->camera.getFocalLength());
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

Color Scene::trace(Ray& ray, int depth) {
	Color color;
	// TODO
	float t = INFINITY;
	for (int i = 0; i < this->objects.size(); i++) {
		if (this->objects[i]->intersect(ray, t)) {
			for (int k = 0; k < this->lights.size(); k++) {

				// Construct the shadowRay from point of intersection
				Ray shadowRay(glm::vec3(ray.x(t), ray.y(t), ray.z(t)), this->lights[k].getPosition());

				// Cast shadowRay
				if (shadowTrace(shadowRay)) {
					color.setAmbientColor(glm::vec3(0,0,0));
					return color;
				}
				else {
					return this->objects[i]->getMaterial().getColor();
				}
			}
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