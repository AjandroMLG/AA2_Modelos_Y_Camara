#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>


static class MatrixTools
{
public:
	static glm::mat4 GenerateTranslationMatrix(glm::vec3 translation);

	static glm::mat4 GenerateRotationMatrix(glm::vec3 axis, float fDegrees);

	static glm::mat4 GenerateScaleMatrix(glm::vec3 scaleAxis);
};