#include "MatrixTools.h"

glm::mat4 MatrixTools::GenerateTranslationMatrix(glm::vec3 translation)
{
	return glm::translate(glm::mat4(1.f), translation);
}

glm::mat4 MatrixTools::GenerateRotationMatrix(glm::vec3 axis, float fDegrees)
{
	return glm::rotate(glm::mat4(1.f), glm::radians(fDegrees), glm::normalize(axis));
}

glm::mat4 MatrixTools::GenerateScaleMatrix(glm::vec3 scaleAxis)
{
	return glm::scale(glm::mat4(1.f), scaleAxis);
}

