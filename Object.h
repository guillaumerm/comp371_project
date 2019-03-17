#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <istream>

#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Object {
public:
	Object();
	Object(glm::vec3 position);
	virtual void parse(std::istream& input) = 0;
	virtual void setPosition(glm::vec3 position);
	virtual glm::vec3 getPosition();
private:
	glm::vec3 position;
protected:
	const static glm::vec3 DEFAULT_POSITION;
};
#endif
