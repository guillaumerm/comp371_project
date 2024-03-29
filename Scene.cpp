#include "Scene.h"

Scene::Scene(const char* path)
{
	this->parseFile(path);
}

bool Scene::render(const char* path) {
	const int width = glm::round(this->camera.getWidth());
	const int height = glm::round(this->camera.getHeight());
	const float angle = glm::tan(glm::radians(this->camera.getFov() / 2));

	cimg_library::CImg<float> image(width, height, 1, 3, 0);

	// Shoots the rays for tracing the scene
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {

			// Calculate the xyz components of the ray direction
			float x = (2 * (i + 0.5) / (float)width - 1) * this->camera.getAspectRatio() * angle;
			float y = (1 - 2 * (j + 0.5) / (float)height) * angle;
			float z = -1;

			// Create ray and trace it
			glm::vec3 rayDirection = glm::normalize(glm::vec3(x, y, z));
			if (j == 0 && i == width - 1) {
				int breakpoint = 1 + 1;
			}
			Ray ray(this->camera.getPosition(), rayDirection);
			glm::vec3 pixelColor = trace(ray);

			// Apply the color from the ray trace to the image pixel
			image(i, j, 0) = pixelColor.r * 255.0f;
			image(i, j, 1) = pixelColor.g * 255.0f;
			image(i, j, 2) = pixelColor.b * 255.0f;
		}
	}
	image.save(path);

	return true;
}

bool Scene::shadowTrace(Ray& shadowRay) {
	float t = INFINITY;
	bool isBlocked = false;

	// Verify if the shadow ray intersects with any objects
	for (int j = 0; j < this->objects.size() && !isBlocked; j++) {
		isBlocked = this->objects[j]->intersect(shadowRay);
	}

	return isBlocked;
}

glm::vec3 Scene::trace(Ray& ray) {
	float nearest_t = INFINITY;
	glm::vec3 intersectionNormal;
	glm::vec3 intersectionPoint;
	int indexClosestObject = -1;

	// Find the closest intersection if any
	for (int i = 0; i < this->objects.size(); i++) {
		float t = INFINITY;
		glm::vec3 point;
		glm::vec3 normal;
		if (this->objects[i]->intersect(ray, t, point, normal) && t < nearest_t) {
			nearest_t = t;
			indexClosestObject = i;
			intersectionNormal = normal;
			intersectionPoint = point;
		}
	}

	glm::vec3 pixelColor = glm::vec3(0);

	// If no intersection return the background color
	if (nearest_t == INFINITY && indexClosestObject == -1) {
		return pixelColor;
	}

	glm::vec3 normalizedNormal = glm::normalize(intersectionNormal);

	// Cast shadow rays for each light sources
	for (int i = 0; i < this->lights.size(); i++) {
		Ray shadowRay(intersectionPoint, glm::normalize(this->lights[i].getPosition() - intersectionPoint));

		// If shadow ray do not intersect with object apply phong illumination for light
		if (!shadowTrace(shadowRay)) {

			// Diffuse
			glm::vec3 lightDirection = glm::normalize(this->lights[i].getPosition() - intersectionPoint);
			float diffuseStrength = glm::max(glm::dot(normalizedNormal, lightDirection), 0.0f);
			glm::vec3 diffuse = this->lights[i].getColor().getDiffuseColor() * diffuseStrength * this->objects[indexClosestObject]->getMaterial().getColor().getDiffuseColor();

			// Specular
			glm::vec3 viewDirection = glm::normalize(this->camera.getPosition() - intersectionPoint);
			glm::vec3 reflectedLightDirection = glm::reflect(-lightDirection, normalizedNormal);
			float specularStrength = glm::pow(glm::max(glm::dot(reflectedLightDirection, viewDirection), 0.0f), this->objects[indexClosestObject]->getMaterial().getShininess());
			glm::vec3 specular = this->lights[i].getColor().getSpecularColor() * specularStrength * this->objects[indexClosestObject]->getMaterial().getColor().getSpecularColor();
			
			// Add the light's contribution to the pixel_color
			pixelColor += (diffuse + specular);
		}
	}

	// Ambient color added once
	pixelColor += this->objects[indexClosestObject]->getMaterial().getColor().getAmbientColor();

	// Clamp color channels between 0.0f and 1.0f
	pixelColor.r = glm::min(1.0f, pixelColor.r);
	pixelColor.g = glm::min(1.0f, pixelColor.g);
	pixelColor.b = glm::min(1.0f, pixelColor.b);

	return pixelColor;
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