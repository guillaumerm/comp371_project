#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"

class Material {
public:
	//! A constructor which creates an empty Material instance.
	Material();

	//! A constructor which creates a Material with specified Color and shininess.
	/*!
		\param color Color of the Material.
		\param shininess degree of shininess of the Material.
	*/
	Material(Color color, float shininess);

	//! Obtain the Color of the Material
	/*!
		\return The Color of the Material.
	*/
	Color getColor();

	//! Obtain the shininess of the Material.
	/*!
		\return The shininess of the Material.
	*/
	float getShininess();

	//! Mutates the Material Color.
	/*!
		\param color new color of the Material.
	*/
	void setColor(Color color);

	//! Mutates the Material shininess
	/*!
		\param shininess new shininess of the Material.
	*/
	void setShininess(float shininess);
private:
	const static Color DEFAULT_COLOR;	/*!< Material default color */
	const static int DEFAULT_SHININESS; /*!< Material default shininess */
	Color color;						/*!< Color of the Material */
	float shininess;					/*!< Shininess of the Material*/
};
#endif
