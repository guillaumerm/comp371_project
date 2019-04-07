#ifndef COLOR_H
#define COLOR_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

class Color {
public:
	//! A Color constructor which creates a Color with the default components
	Color();

	//! A Color constructor which creates a Color with the specified parameters.
	/*!
		\param ambientColor vector that contains the RGB channels different ambient color.
		\param diffuseColor vector that contains the RGB channels different diffuse color.
		\param specularColor vector that contains the RGB channels different specular color.
	*/
	Color(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specularColor);

	//! Get the vector with the RGB channels ambient color.
	/*!
		\return The vector containing the RGB channels ambient color.
	*/
	glm::vec3 getAmbientColor();

	//! Get the vector with the RGB channels diffuse color.
	/*!
		\return The vector containing the RGB channels diffuse color.
	*/
	glm::vec3 getDiffuseColor();

	//! Get the vector with the RGB channels specular color.
	/*!
		\return The vector containing the RGB channels specular color.
	*/
	glm::vec3 getSpecularColor();

	//! Mutates the ambient color of the Color.
	/*!
		\param ambientColor the Color's new ambient RGB colors.
	*/
	void setAmbientColor(glm::vec3 ambientColor);

	//! Mutates the diffuse color of the Color.
	/*!
		\param diffuseColor the Color's new diffuse RGB colors.
	*/
	void setDiffuseColor(glm::vec3 diffuseColor);

	//! Mutates the specular color of the Color.
	/*!
		\return specularColor the Color's new specular RGB colors.
	*/
	void setSpecularColor(glm::vec3 specularColor);

	//! Add the different ambient, diffuse and specular colors in a single color.
	/*!
		\return The added color components of the Color.
	*/
	glm::vec3 addColors();

	//! Friend function which multiple the color channels by a float value.
	/*!
		\param color reference to the color being multiply.
		\param value multiplier of the multiplication.
		\return The Color resulting from the multiplication.
	*/
	friend const Color operator*(Color &color, float value);

	//! Friend function which add two Color together.
	/*!
		\param color1 first Color operand.
		\param color2 second Color operand.
		\return The Color resulting from the addition.
	*/
	friend const Color operator+(Color &color1, Color &color2);

	//! Friend function which multiplies two Color.
	/*!
		\param color1 first Color operand.
		\param color2 second Color operand.
		\return The Color resulting from the multiplication.
	*/
	friend const Color operator*(Color color1, Color color2);
private:
	glm::vec3 ambientColor; /*!< Ambient component of the color */	
	glm::vec3 diffuseColor; /*!< Diffuse component of the color */
	glm::vec3 specularColor; /*!< Specular component of the color */
protected:
	const static glm::vec3 DEFAULT_AMBIENT_COLOR; /*!< Default ambient component of Color */
	const static glm::vec3 DEFAULT_DIFFUSE_COLOR; /*!< Default diffuse component of Color */
	const static glm::vec3 DEFAULT_SPECULAR_COLOR; /*!< Default specular component of Color */
};
#endif