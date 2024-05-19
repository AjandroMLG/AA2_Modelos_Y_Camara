#include "camera.h"

Camera::Camera(GLuint program) : GameObject(program, glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 1, 0.0f), 0, glm::vec3(1, 1, 1))
{
	typeOfCamera = 0;
	orbitVelocity = 20.0f;
}

void Camera::Film( float dt)
{
	if (typeOfCamera == 0)
	{
		set = false;
		float camX = distance * -sinf(rotation.x * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));
		float camY = distance * -sinf((rotation.y) * (3.141516 / 180));
		float camZ = -distance * cosf((rotation.x) * (3.141516 / 180)) * cosf((rotation.y) * (3.141516 / 180));

		rotation.y += orbitVelocity * dt;
		glm::mat4 translateMatrix = MatrixTools::GenerateTranslationMatrix(position);
		glm::mat4 rotateMatrix = MatrixTools::GenerateRotationMatrix(rotation, rotation.y);
		glm::mat4 scaleMatrix = MatrixTools::GenerateScaleMatrix(scale);

		viewMatrix = glm::lookAt(type0Position + glm::vec3(camY, camX, camZ), lookat, localVectorUp);
		projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
	}
	else if (typeOfCamera == 1)
	{
		set = false;
		lookat = type1LookAt;
		position = type1Position;
		viewMatrix = glm::lookAt(position, lookat, localVectorUp);
		projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
	}
	else if (typeOfCamera == 2)
	{
		set = false;
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

		position.z -= zMovement * dt;
		fFov += fFovVelocity * dt;

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

void Camera::ChangeCamera(int value)
{
	typeOfCamera = value;
}

void Camera::Update(GLuint actualProgram)
{
	glUniformMatrix4fv(glGetUniformLocation(actualProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(glGetUniformLocation(actualProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
