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
	//! A Light constructor which creates a Light with the default values.
	Light();

	//! A Light constructor which creates a Light with the specified values.
	/*!
		\param position position of the Light.
		\param color Color of the Light.
	*/
	Light(glm::vec3 position, Color color);

	//! Obtain the Color of the Light.
	/*!
		The Color object contains the ambient and diffuse components of the Light.
		\return The Color of the Light
	*/
	Color getColor();

	//! Mutate the Color of the Light.
	/*!
		\param color the new Light's Color.
	*/
	void setColor(Color color);

	//! Mutates the Light to the paramters read from the input stream.
	/*!
		\param input the input stream that contains the Light new parameters.
	*/
	void parse(std::istream& input);
private:
	Color color; /*!< Color of the Light */
protected:
	const static Color DEFAULT_COLOR; /*!< Default color member value */
};
#endif