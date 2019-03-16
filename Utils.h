#ifndef UTILS_H
#define UTILS_H
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

template<typename T>
glm::vec3<T> readVec3(istream& input) {
	glm::vec3<T> vector;
	char delimiter;
	input >> vector.x;
	input >> delimiter;
	input >> vector.y;
	input >> delimiter;
	input >> vector.z;

	return vector;
}

std::string trim(std::string str)
{
	// remove trailing white space
	while (!str.empty() && std::isspace(str.back())) str.pop_back();

	// return residue after leading white space
	std::size_t pos = 0;
	while (pos < str.size() && std::isspace(str[pos])) ++pos;
	return str.substr(pos);
}

#endif