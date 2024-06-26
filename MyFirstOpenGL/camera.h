#pragma once
#include "GameObject.h"

class Camera : public GameObject
{

public:
	glm::vec3 localVectorUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 lookat = glm::vec3(0, 0, 0);

	float fFov = 45.f;
	float fNear = 0.1f;
	float fFar = 100.f;
	float distance = 8.0f;
	double xPos, yPos;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	float orbitVelocity;

	bool set = false;


	//Type 0
	glm::vec3 type0Position = glm::vec3(0.3f, 5.0f, 0);

	//Type 1
	glm::vec3 type1Position = glm::vec3(0.2, 1.3, 2.7);
	glm::vec3 type1LookAt = glm::vec3(-1.5, 1, 0.5);
	float speed = 0.1f;
	float yaw = -90;
	float pitch = 0.0f;
	float lastX = 400;
	float lastY = 300;
	bool firstMouse = true;	

	Camera(GLuint program, Model model);
	void Film(float dt);
	void ChangeCamera(int value);
	void Update(GLuint actualProgram);
	void GoFront()
	{
		position += speed * front;
	}

	void GoBack()
	{
		position -= speed * front;
	}

	void GoLeft()
	{
		position -= glm::normalize(glm::cross(front, localVectorUp)) * speed;
	}

	void GoRight()
	{
		position += glm::normalize(glm::cross(front, localVectorUp)) * speed;
	}

};