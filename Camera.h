#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include <sstream>

#include "Object.h"
#include "Utils.h"
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"


class Camera: public Object {
public:
	//! A Camera constructor which creates a Camera with default memebers.
	Camera();

	//! A Camera constructor which creates a Camera with the specified parameters.
	/*!
	  \param position point representing the position of the Camera.
	  \param fov angle in degree for the Camera field of view.
	  \param focalLength focal length for the Camera.
	  \param aspectRatio aspect ratio for a Camera.
	  \return The test results
	  \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
	*/
	Camera(glm::vec3 position, float fov, float focalLength, float aspectRatio);

	//! Obtain the current Camera field of view.
	/*!
	  \return The current field of view of the Camera.
	*/
	float getFov();

	//! Obtain the current focal length of the Camera.
	/*!
	  \return The current focal length of the Camera.
	*/
	float getFocalLength();

	//! Obtain the current aspect ratio of the Camera.
	/*!
	  \return The current aspect ratio of the Camera.
	*/
	float getAspectRatio();

	//! Mutate the current Camera field of view.
	/*!
		\param fov the new Camera's field of view angle.
	*/
	void setFov(float fov);

	//! Mutate the current Camera focal length.
	/*!
		\param focalLength the new Camera's focalLength.
	*/
	void setFocalLength(float focalLength);

	//! Mutate the current Camera aspect ratio.
	/*!
		\param aspectRatio the Camera's new aspect ratio.
	*/
	void setAspectRatio(float aspectRatio);

	//! Mutate the current Camera with the parameters from an input stream.
	/*!
		\param input InputStream containing the new Camera's paramters.
	*/
	void parse(std::istream& input);

	//! Calculates the width of the image space.
	/*!
		\return The width in pixel of the image
	*/
	float getWidth();

	//! Calculates the height of the image space.
	/*!
		\return The height in pixel of the image
	*/
	float getHeight();
private:
	const static float DEFAULT_FOV;				/*!< Default field of view value for a Camera */
	const static float DEFAULT_FOCAL_LENGTH;	/*!< Default focal length for a Camera */
	const static float DEFAULT_ASPECT_RATIO;	/*!< Default aspect ratio for a Camera */
	float fov;									/*!< Field of view of the Camera */
	float focalLength;							/*!< Focal length of the Camera */
	float aspectRatio;							/*!< Aspect ratio of the Camera */
};
#endif
