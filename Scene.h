#ifndef SCENE_H
#define SCENE_H
#include "Color.h"
#include "Object.h"
#include "Camera.h"
#include "Ray.h"
#include "Utils.h"
#include <fstream>
#include <vector>
#include <string>

class Scene {
public:
	Scene(const char *path);
	void render(const char* path);
private:
	int numberOfObjects;
	std::vector<Object> objects;
	Camera camera;
	bool parseFile(const char* path);
	Color trace(Ray& ray, int depth);
};
#endif
