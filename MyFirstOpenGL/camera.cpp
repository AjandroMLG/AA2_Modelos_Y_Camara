#include "camera.h"

Camera::Camera(GLuint program, Model model) : GameObject(program, glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 1, 0.0f), glm::vec3(1, 1, 1), model)
{
	orbitVelocity = 20.0f;
}

void Camera::Film( float dt)
{	
		viewMatrix = glm::lookAt(position, position + front, localVectorUp);
		projectionMatrix = glm::perspective(glm::radians(fFov), (float)640 / (float)480, fNear, fFar);
}

void Camera::ChangeCamera(int value)
{
}


void Camera::Update(GLuint actualProgram)
{
	glUniformMatrix4fv(glGetUniformLocation(actualProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(glGetUniformLocation(actualProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
