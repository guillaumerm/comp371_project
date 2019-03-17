#ifndef LIGHT_H
#define LIGHT_H
#include <string>
#include <sstream>
#include "Utils.h"
#include "Object.h"
#include "Color.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Light: public Object {
public:
	Light();
	Light(glm::vec3 position, Color color);
	Color getColor();
	void setColor(Color color);
	void parse(std::istream& input);
private:
	Color color;
protected:
	const static Color DEFAULT_COLOR;
};
#endif