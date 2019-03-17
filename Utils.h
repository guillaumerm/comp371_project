#ifndef UTILS_H
#define UTILS_H
#include <istream>
#include "./glm/glm.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/type_ptr.hpp"

inline glm::vec3 readVec3(std::istringstream input) {
	glm::vec3 vector;
	char delimiter;
	input >> vector.x;
	input >> vector.y;
	input >> vector.z;

	return vector;
}

inline std::string trim(std::string str)
{
	// remove trailing white space
	while (!str.empty() && std::isspace(str.back())) str.pop_back();

	// return residue after leading white space
	std::size_t pos = 0;
	while (pos < str.size() && std::isspace(str[pos])) ++pos;
	return str.substr(pos);
}
#endif