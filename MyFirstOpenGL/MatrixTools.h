#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>


static class MatrixTools
{
public:
	static glm::mat4 GenerateTranslationMatrix(glm::vec3 translation);

	static glm::mat4 GenerateRotationMatrix(glm::vec3 axis, float fDegrees);

	static glm::mat4 GenerateScaleMatrix(glm::vec3 scaleAxis);
	
	static int RandonNumberBetween(int min, int max)
	{
		return min + rand() % (max - min + 1);
	}

	static float RandomNumberBetweenFloat(float min, float max)
	{
		// Generar un número aleatorio entre 0 y 1
		float random = ((float)rand()) / (float)RAND_MAX;

		// Escalar el número aleatorio al rango deseado
		float range = max - min;
		float scaled = random * range;

		// Desplazar al rango deseado
		float result = min + scaled;

		return result;
	}
};