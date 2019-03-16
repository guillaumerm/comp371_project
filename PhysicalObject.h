#ifndef PHYSICAL_OBJECT_H
#define PHYSICAL_OBJECT_H
#include "Object.h"
#include "Material.h"
#include "Ray.h"

class PhysicalObject: virtual Object {
public:
	PhysicalObject(Material material);
	virtual Material getMaterial();
	virtual bool intersect(Ray& ray, float& t);
private:
	Material material;
};
#endif
