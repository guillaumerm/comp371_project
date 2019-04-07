#ifndef PHYSICAL_OBJECT_H
#define PHYSICAL_OBJECT_H
#include "Object.h"
#include "Material.h"
#include "Ray.h"

class PhysicalObject: public Object {
public:
	PhysicalObject();
	PhysicalObject(glm::vec3 psotion, Material material);
	Material getMaterial();
	void setMaterial(Material material);
	virtual bool intersect(Ray& ray);
	virtual bool intersect(Ray& ray, float& t, glm::vec3 &intersectionPoint, glm::vec3 &intersectionNormal) = 0;
private:
	Material material;
protected:
	const static Material DEFAULT_MATERIAL;
};
#endif
