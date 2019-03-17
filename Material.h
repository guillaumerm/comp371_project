#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"

class Material {
public:
	Material();
	Material(Color color, float shininess);
	Color getColor();
	float getShininess();
	void setColor(Color color);
	void setShininess(float shiniess);
private:
	const static Color DEFAULT_COLOR;
	const static int DEFAULT_SHININESS;
	Color color;
	float shininess;
};
#endif
