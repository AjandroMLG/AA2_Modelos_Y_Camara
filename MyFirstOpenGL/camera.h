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
	glm::vec3 type0Position = glm::vec3(0.3f, 5.0f, 0);

	//Type 1
	glm::vec3 type1Position = glm::vec3(0.2, 1.3, 2.7);
	glm::vec3 type1LookAt = glm::vec3(-1.5, 1, 0.5);

	//Type 2
	glm::vec3 type2Position = glm::vec3(0.8, 1.3, 1.2);
	glm::vec3 type2LookAt = glm::vec3(1.5, 1.2, 0.5);

	//Type 3
	glm::vec3 type3Position = glm::vec3(0, 1.3, 5);
	glm::vec3 type3LookAt = glm::vec3(0, 1.3, 0.5);
	float fFovVelocity = 17.0f;
	float zMovement = 1.0f;

	Camera(GLuint program);
	void Film(float dt);
	void ChangeCamera(int value);
	void Update(GLuint actualProgram);		
};