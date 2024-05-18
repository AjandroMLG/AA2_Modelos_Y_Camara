#pragma once
#include "GameObject.h"

class Camera : public GameObject
{

public:
	glm::vec3 localVectorUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 lookat = glm::vec3(0, 0, 0);

	float fFov = 45.f;
	float fNear = 0.1f;
	float fFar = 100.f;
	float distance = 8.0f;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	int typeOfCamera;
	float orbitVelocity;

	bool set = false;


	//Type 0
	glm::vec3 type0Position = glm::vec3(0.3f, 3.0f, 0);

	//Type 1
	glm::vec3 type1Position = glm::vec3(0.2, 1.3, 2.7);
	glm::vec3 type1LookAt = glm::vec3(-1.5, 1, 0.5);

	//Type 2
	glm::vec3 type2Position = glm::vec3(0.8, 1.3, 1.2);
	glm::vec3 type2LookAt = glm::vec3(1.5, 1.2, 0.5);

	//Type 3
	glm::vec3 type3Position = glm::vec3(0, 1.3, 5);
	glm::vec3 type3LookAt = glm::vec3(0, 1.3, 0.5);
	float fFovVelocity = 0.2f;
	float zMovement = 0.1;

	Camera(GLuint program) : GameObject(program, glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 1, 0.0f),0, glm::vec3(1, 1, 1))
	{

		typeOfCamera = 0;
		orbitVelocity = 0.2f;
	}

	void Film()
	{
		if (typeOfCamera == 0)
		{
			float camX = distance * -sinf(rotation.x * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
			float camY = distance * -sinf((rotation.y) * (3.141516 / 180));
			float camZ = -distance * cosf((rotation.x) * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));

			rotation.y += orbitVelocity;
			glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
			glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotation.y);
			glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

			viewMatrix = glm::lookAt( type0Position + glm::vec3(camY, camX, camZ), lookat, localVectorUp);
			projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
		} 
		else if (typeOfCamera == 1)
		{
			lookat = type1LookAt;
			position = type1Position;
			viewMatrix = glm::lookAt(position, lookat, localVectorUp);
			projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
		}
		else if (typeOfCamera == 2)
		{
			lookat = type2LookAt;
			position = type2Position;
			viewMatrix = glm::lookAt(position, lookat, localVectorUp);
			projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
		}
		else if (typeOfCamera == 3)
		{
			if (!set)
			{
				lookat = type3LookAt;
				position = type3Position;
				set = true;
			}		
			
			position.z -= zMovement;
			fFov += fFovVelocity;

			viewMatrix = glm::lookAt(position, lookat, localVectorUp);
			projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
			if (position.z <= lookat.z)
			{
				fFov = 45;
				typeOfCamera = 0;
				set = false;
			}
		}
		
	}

	void ChangeCamera(int value)
	{
		typeOfCamera = value;
	}
	void Update(GLuint actualProgram)
	{

		glUniformMatrix4fv(glGetUniformLocation(actualProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(glGetUniformLocation(actualProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	}
};