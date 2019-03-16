#ifndef MATERIAL_H
#define MATERIAL
#include "Color.h"

class Material {
public:
	Material(Color color, float shininess);
	Color getColor();
	float getShininess();
private:
	Color color;
	float shininess;
};
#endif
