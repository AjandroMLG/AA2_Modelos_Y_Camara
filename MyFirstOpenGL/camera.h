#pragma once
#include "GameObject.h"

class Camera : public GameObject
{

public:
	glm::vec3 localVectorUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 localVectorRight = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 lookat = glm::vec3(0, 0, 0);
	glm::vec3 camFocusVector = position - lookat;
	float fFov = 45.f;
	float fNear = 0.1f;
	float fFar = 100.f;
	float distance = 8.0f;

	Camera(GLuint program) : GameObject(program, glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 1, 0.0f),90, glm::vec3(1, 1, 1))
	{

	}

	void Film()
	{


		float camX = distance * -sinf(rotation.x * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
		float camY = distance * -sinf((rotation.y) * (3.141516 / 180));
		float camZ = -distance * cosf((rotation.x) * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));

		glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
		glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotation.y);
		glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

		glm::mat4 viewMatrix = glm::lookAt (glm::vec3(0.3f, 3.0f, 0) + glm::vec3(camY,camX,camZ), lookat, localVectorUp);
		// Definir la matriz proyeccion
		glm::mat4 projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
		// Pasar las matrices				
		glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));


	}
};