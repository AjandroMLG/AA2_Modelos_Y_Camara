#include "camera.h"

Camera::Camera(GLuint program) : GameObject(program, glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 1, 0.0f), 0, glm::vec3(1, 1, 1))
{
	typeOfCamera = 1;
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
	if (typeOfCamera == 1)
	{
		viewMatrix = glm::lookAt(position, position + front, localVectorUp);
		projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
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
