#pragma once
#include "MatrixTools.h"
#include <GL/glew.h>
#include <vector>


class GameObject {
public:

	GLuint vao, vbo;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 up;
	glm::vec3 rotationDirection;
	glm::mat4 modelMatrix;
	std::vector<GLfloat> vertex;
	float fVelocity;
	float fAngularVelocity;
	glm::vec4 defaultColor;
	bool wareFrame;
	bool render; 
	float topScreen, downScreen;


	GameObject()
	{
		render = true;
		defaultColor = glm::vec4(1.0f);
		position = glm::vec3(0.f);
		rotation = glm::vec3(0.f);
		up = glm::vec3(0.f, 1.f, 0.f);
		rotationDirection = glm::vec3(0.f, 1.f, 0.f);
		modelMatrix = glm::mat4(1.f);
		fVelocity = 0.002f;
		fAngularVelocity = -1.f;
		topScreen = 0.85f;
		downScreen = -0.85f;
	}

	void SpeedUp()
	{
		fVelocity += fVelocity * 0.1f;
	}

	void SpeedDown()
	{
		fVelocity -= fVelocity * 0.1f;
	}

	void ChangeView()
	{
		wareFrame != wareFrame;
	}

	void ChangeRender()
	{
		render = !render;
	}

	virtual void Update(GLuint compiled) = 0;
};