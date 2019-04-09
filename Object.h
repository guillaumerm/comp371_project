#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <istream>

#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Object {
public:
	//! A constructor which creates a default Object.
	Object();

	//! A constructor which creates am Object located at the specified location.
	/*!
		\param position position of the Object.
	*/
	Object(glm::vec3 position);

	//! Mutates the Object to the parameters read from the input stream.
	/*!
		\param input the input stream that contains the Object new parameters.
	*/
	virtual void parse(std::istream& input) = 0;

	//! Mutates the Object current position.
	/*!
		\param position new position of the Object.
	*/
	virtual void setPosition(glm::vec3 position);

	//! Obtain the OBject current position.
	/*!
		\return The position of the Object.
	*/
	virtual glm::vec3 getPosition();
private:
	glm::vec3 position;							/*!< Position of the Object.*/
protected:
	const static glm::vec3 DEFAULT_POSITION;	/*!< Default position of Objects.*/
};
#endif
